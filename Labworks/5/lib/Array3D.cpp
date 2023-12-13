#include "Array3D.h"

Array3D::Array3D(size_t x, size_t y, size_t z) : x_size_(x), y_size_(y), z_size_(z) {
  data_size_ = ((x_size_ * y_size_ * z_size_ * 17) / 16) + (((x_size_ * y_size_ * z_size_ * 17) % 16 == 0) ? 0 : 1);
  data_ = new uint16_t[data_size_];
};

Array3D::WrapperX Array3D::operator[](size_t z) {
  return WrapperX(z, this);
};

Array3D::~Array3D() {
  delete[] data_;
};

Array3D& Array3D::CreateArray(size_t x, size_t y, size_t z) {
  return *(new Array3D(x, y, z));
};

void Array3D::SetValue(size_t x, size_t y, size_t z, uint32_t value) {
  size_t start_position = ((z_size_ * y_size_ * x + z_size_ * y + z) * kSize) / kContainerSize;
  uint8_t offset = ((z_size_ * y_size_ * x + z_size_ * y + z) * kSize) % kContainerSize;
  for (size_t i = 0; i < kSize; ++i) {
    uint32_t tmp_number = (value >> i) % 2;
    data_[start_position + ((offset + i) / kContainerSize)] &= ~(1 << ((offset + i) % kContainerSize));
    data_[start_position + ((offset + i) / kContainerSize)] |= tmp_number << ((offset + i) % kContainerSize);
  }
};

uint32_t Array3D::GetValue(size_t x, size_t y, size_t z) const {
  size_t start_position = ((z_size_ * y_size_ * x + z_size_ * y + z) * kSize) / kContainerSize;
  uint8_t offset = ((z_size_ * y_size_ * x + z_size_ * y + z) * kSize) % kContainerSize;
  uint32_t result = 0;
  for (size_t i = 0; i < kSize; ++i) {
    // result |= ((data_[start_position + ((offset + i) / kContainerSize)] >> ((offset + i) % kContainerSize))) << i;
    uint32_t tmp_number = ((data_[start_position + ((offset + i) / kContainerSize)] >> ((offset + i) % kContainerSize)) % 2) << i;
    result |= tmp_number;
  }

  return result;
};

// WrapperX
Array3D::WrapperX::WrapperX(size_t x, Array3D* array) : x_(x), array_(array){};

Array3D::WrapperY Array3D::WrapperX::operator[](size_t y) const {
  return WrapperY(x_, y, array_);
};

// WrapperY
Array3D::WrapperY::WrapperY(size_t x, size_t y, Array3D* array) : x_(x), y_(y), array(array){};

Array3D::WrapperZ Array3D::WrapperY::operator[](size_t z) const {
  return WrapperZ(x_, y_, z, array);
};

// WrapperZ
Array3D::WrapperZ::WrapperZ(size_t x, size_t y, size_t z, Array3D* array) : x_(x), y_(y), z_(z), array_(array){};

Array3D::WrapperZ& Array3D::WrapperZ::operator=(size_t rhs) {
  array_->SetValue(x_, y_, z_, rhs);
  return *this;
};

// Output array element
std::ostream& operator<<(std::ostream& stream, const Array3D::WrapperZ& wrapper) {
  stream << wrapper.array_->GetValue(wrapper.x_, wrapper.y_, wrapper.z_);
  return stream;
};

// Output entire array
std::ostream& operator<<(std::ostream& stream, const Array3D& array) {
  for (size_t x = 0; x < array.x_size_; ++x) {
    for (size_t y = 0; y < array.y_size_; ++y) {
      for (size_t z = 0; z < array.z_size_; ++z) {
        stream << array.GetValue(x, y, z) << ' ';
      }
      stream << '\n';
    }
    stream << '\n';
  }

  return stream;
};

// Input elements into array
std::istream& operator>>(std::istream& stream, Array3D& array) {
  for (size_t x = 0; x < array.x_size_; ++x) {
    for (size_t y = 0; y < array.y_size_; ++y) {
      for (size_t z = 0; z < array.z_size_; ++z) {
        uint32_t tmp;
        stream >> tmp;
        array.SetValue(x, y, z, tmp);
      }
    }
  }

  return stream;
};

Array3D& Array3D::operator*(const uint32_t number) {
  Array3D* result = new Array3D(x_size_, y_size_, z_size_);
  for (size_t x = 0; x < x_size_; ++x) {
    for (size_t y = 0; y < y_size_; ++y) {
      for (size_t z = 0; z < z_size_; ++z) {
        result->SetValue(x, y, z, GetValue(x, y, z) * number);
      }
    }
  }
  return *result;
};

Array3D& Array3D::operator+(const Array3D& rhs) {
  Array3D* result = new Array3D(x_size_, y_size_, z_size_);
  for (size_t x = 0; x < x_size_; ++x) {
    for (size_t y = 0; y < y_size_; ++y) {
      for (size_t z = 0; z < z_size_; ++z) {
        result->SetValue(x, y, z, GetValue(x, y, z) + rhs.GetValue(x, y, z));
      }
    }
  }
  return *result;
};

Array3D& Array3D::operator-(const Array3D& rhs) {
  Array3D* result = new Array3D(x_size_, y_size_, z_size_);
  for (size_t x = 0; x < x_size_; ++x) {
    for (size_t y = 0; y < y_size_; ++y) {
      for (size_t z = 0; z < z_size_; ++z) {
        result->SetValue(x, y, z, GetValue(x, y, z) - rhs.GetValue(x, y, z));
      }
    }
  }
  return *result;
};
