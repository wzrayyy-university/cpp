#include "lib/Array3D.h"
#include <cstddef>
#include <iostream>

int main() {
  size_t array_size = 4;
  Array3D a = Array3D::CreateArray(array_size, array_size, array_size);

  a[0][0][0] = 4;
  a[0][0][0] = 0;

  std::cout << a;
}
