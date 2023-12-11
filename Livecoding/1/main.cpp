#include <cstdint>
#include <iostream>

// Дано
bool compare_uint64(void* a_, void* b_, int size) {
  uint64_t a = *(uint64_t*) a_;
  uint64_t b = *(uint64_t*) b_;
  return a >= b;
}


// Реализовать
void swap(void* a_, void* b_, int size) {
  for (int i = 0; i < size; ++i) {

    char* a = (char*) a_ + i;
    char* b = (char*) b_ + i;

    char tmp = *a;
    *a = *b;
    *b = tmp;
  }
}

void sort(void* data, int size, int count, bool (*compare)(void*, void*, int)) {
  int swaps;
  do {
    swaps = 0;
    for (int i = 0; i < size; ++i) {
      void* a = (char*) data + (i * size);
      void* b = (char*) data + ((i + 1) * size);
      if (compare(a, b, size)) {
        swap(a, b, size);
        ++swaps;
      }
    }
  } while (swaps > 0);
}

// Пример использования sort()
int main() {
  int size = 8, count = 8;

  uint64_t* data = new uint64_t[count]{7, 3, 5, 2, 11, 28, 4, 16};

  std::cout << "Initial values: ";
  for (int i = 0; i < count; ++i) {
    std::cout << (int) data[i] << ' ';

  }

  std::cout << std::endl;

  sort(data, size, count, compare_uint64);

  std::cout << "Sorted values: ";
  for (int i = 0; i < count; ++i) {
    std::cout << (int) data[i] << ' ';
  }

  std::cout << std::endl;

  delete[] data;
}

