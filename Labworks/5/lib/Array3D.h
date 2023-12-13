#pragma once

#include <cstddef>
#include <cstdint>
#include <iostream>

const uint32_t kSize = 17;
const uint32_t kContainerSize = 16;
const uint32_t kBitMask = (1 << kSize) - 1;

class Array3D {
 private:
  uint16_t* data_;
  size_t x_size_;
  size_t y_size_;
  size_t z_size_;
  size_t data_size_;

 public:
  class WrapperZ {
   public:
    WrapperZ(size_t x, size_t y, size_t z, Array3D* array);
    WrapperZ& operator=(const size_t rhs);
    friend std::ostream& operator<<(std::ostream& stream, const WrapperZ& wrapper);

   private:
    size_t x_;
    size_t y_;
    size_t z_;
    Array3D* array_;
  };

  class WrapperY {
   public:
    WrapperY(size_t y, size_t x, Array3D* array);
    WrapperZ operator[](size_t z) const;

   private:
    size_t y_;
    size_t x_;
    Array3D* array;
  };

  class WrapperX {
   public:
    WrapperX(size_t x, Array3D* array);
    WrapperY operator[](size_t y) const;

   private:
    size_t x_;
    Array3D* array_;
  };

 public:
  Array3D(size_t x, size_t y, size_t z);
  ~Array3D();

  WrapperX operator[](size_t x);

  friend std::ostream& operator<<(std::ostream& stream, const Array3D& array);
  friend std::istream& operator>>(std::istream& stream, Array3D& array);

  Array3D& operator*(const uint32_t number);
  Array3D& operator+(const Array3D& rhs);
  Array3D& operator-(const Array3D& rhs);

  static Array3D& CreateArray(size_t x, size_t y, size_t z);

  void SetValue(size_t x, size_t y, size_t z, uint32_t value);
  uint32_t GetValue(size_t x, size_t y, size_t z) const;
};
