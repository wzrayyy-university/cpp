#include <gtest/gtest.h>
#include <lib/Array3D.h>
#include <sstream>

std::vector<std::string> SplitString(const std::string& str) {
  std::istringstream iss(str);

  return {std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>()};
}

TEST(Array3DTestSuite, MultiplyOperator) {
  Array3D arr(2, 3, 4);

  arr[0][0][0] = 4;
  arr[0][0][1] = 0;
  arr[0][0][2] = 4;
  arr[0][0][3] = 0;

  arr[0][1][0] = 4;
  arr[0][1][1] = 0;
  arr[0][1][2] = 4;
  arr[0][1][3] = 0;

  arr[0][2][0] = 4;
  arr[0][2][1] = 0;
  arr[0][2][2] = 4;
  arr[0][2][3] = 0;

  arr[1][0][0] = 4;
  arr[1][0][1] = 0;
  arr[1][0][2] = 4;
  arr[1][0][3] = 0;

  arr[1][1][0] = 4;
  arr[1][1][1] = 0;
  arr[1][1][2] = 4;
  arr[1][1][3] = 0;

  arr[1][2][0] = 4;
  arr[1][2][1] = 0;
  arr[1][2][2] = 4;
  arr[1][2][3] = 0;

  Array3D arr2 = arr * 2;
  EXPECT_EQ(arr.GetValue(0, 0, 0), 4);
  EXPECT_EQ(arr.GetValue(0, 0, 1), 0);
  EXPECT_EQ(arr.GetValue(0, 0, 2), 4);
  EXPECT_EQ(arr.GetValue(0, 0, 3), 0);

  EXPECT_EQ(arr.GetValue(0, 1, 0), 4);
  EXPECT_EQ(arr.GetValue(0, 1, 1), 0);
  EXPECT_EQ(arr.GetValue(0, 1, 2), 4);
  EXPECT_EQ(arr.GetValue(0, 1, 3), 0);

  EXPECT_EQ(arr.GetValue(0, 2, 0), 4);
  EXPECT_EQ(arr.GetValue(0, 2, 1), 0);
  EXPECT_EQ(arr.GetValue(0, 2, 2), 4);
  EXPECT_EQ(arr.GetValue(0, 2, 3), 0);

  EXPECT_EQ(arr.GetValue(1, 0, 0), 4);
  EXPECT_EQ(arr.GetValue(1, 0, 1), 0);
  EXPECT_EQ(arr.GetValue(1, 0, 2), 4);
  EXPECT_EQ(arr.GetValue(1, 0, 3), 0);

  EXPECT_EQ(arr.GetValue(1, 1, 0), 4);
  EXPECT_EQ(arr.GetValue(1, 1, 1), 0);
  EXPECT_EQ(arr.GetValue(1, 1, 2), 4);
  EXPECT_EQ(arr.GetValue(1, 1, 3), 0);

  EXPECT_EQ(arr.GetValue(1, 2, 0), 4);
  EXPECT_EQ(arr.GetValue(1, 2, 1), 0);
  EXPECT_EQ(arr.GetValue(1, 2, 2), 4);
  EXPECT_EQ(arr.GetValue(1, 2, 3), 0);

  EXPECT_EQ(arr2.GetValue(0, 0, 0), 8);
  EXPECT_EQ(arr2.GetValue(0, 0, 1), 0);
  EXPECT_EQ(arr2.GetValue(0, 0, 2), 8);
  EXPECT_EQ(arr2.GetValue(0, 0, 3), 0);

  EXPECT_EQ(arr2.GetValue(0, 1, 0), 8);
  EXPECT_EQ(arr2.GetValue(0, 1, 1), 0);
  EXPECT_EQ(arr2.GetValue(0, 1, 2), 8);
  EXPECT_EQ(arr2.GetValue(0, 1, 3), 0);

  EXPECT_EQ(arr2.GetValue(0, 2, 0), 8);
  EXPECT_EQ(arr2.GetValue(0, 2, 1), 0);
  EXPECT_EQ(arr2.GetValue(0, 2, 2), 8);
  EXPECT_EQ(arr2.GetValue(0, 2, 3), 0);

  EXPECT_EQ(arr2.GetValue(1, 0, 0), 8);
  EXPECT_EQ(arr2.GetValue(1, 0, 1), 0);
  EXPECT_EQ(arr2.GetValue(1, 0, 2), 8);
  EXPECT_EQ(arr2.GetValue(1, 0, 3), 0);

  EXPECT_EQ(arr2.GetValue(1, 1, 0), 8);
  EXPECT_EQ(arr2.GetValue(1, 1, 1), 0);
  EXPECT_EQ(arr2.GetValue(1, 1, 2), 8);
  EXPECT_EQ(arr2.GetValue(1, 1, 3), 0);

  EXPECT_EQ(arr2.GetValue(1, 2, 0), 8);
  EXPECT_EQ(arr2.GetValue(1, 2, 1), 0);
  EXPECT_EQ(arr2.GetValue(1, 2, 2), 8);
  EXPECT_EQ(arr2.GetValue(1, 2, 3), 0);
}

TEST(Array3DTestSuite, PlusOperator) {
  Array3D arr(2, 3, 4);

  arr[0][0][0] = 4;
  arr[0][0][1] = 0;
  arr[0][0][2] = 4;
  arr[0][0][3] = 0;

  arr[0][1][0] = 4;
  arr[0][1][1] = 0;
  arr[0][1][2] = 4;
  arr[0][1][3] = 0;

  arr[0][2][0] = 4;
  arr[0][2][1] = 0;
  arr[0][2][2] = 4;
  arr[0][2][3] = 0;

  arr[1][0][0] = 4;
  arr[1][0][1] = 0;
  arr[1][0][2] = 4;
  arr[1][0][3] = 0;

  arr[1][1][0] = 4;
  arr[1][1][1] = 0;
  arr[1][1][2] = 4;
  arr[1][1][3] = 0;

  arr[1][2][0] = 4;
  arr[1][2][1] = 0;
  arr[1][2][2] = 4;
  arr[1][2][3] = 0;

  Array3D arr2 = arr + arr;

  EXPECT_EQ(arr.GetValue(0, 0, 0), 4);
  EXPECT_EQ(arr.GetValue(0, 0, 1), 0);
  EXPECT_EQ(arr.GetValue(0, 0, 2), 4);
  EXPECT_EQ(arr.GetValue(0, 0, 3), 0);

  EXPECT_EQ(arr.GetValue(0, 1, 0), 4);
  EXPECT_EQ(arr.GetValue(0, 1, 1), 0);
  EXPECT_EQ(arr.GetValue(0, 1, 2), 4);
  EXPECT_EQ(arr.GetValue(0, 1, 3), 0);

  EXPECT_EQ(arr.GetValue(0, 2, 0), 4);
  EXPECT_EQ(arr.GetValue(0, 2, 1), 0);
  EXPECT_EQ(arr.GetValue(0, 2, 2), 4);
  EXPECT_EQ(arr.GetValue(0, 2, 3), 0);

  EXPECT_EQ(arr.GetValue(1, 0, 0), 4);
  EXPECT_EQ(arr.GetValue(1, 0, 1), 0);
  EXPECT_EQ(arr.GetValue(1, 0, 2), 4);
  EXPECT_EQ(arr.GetValue(1, 0, 3), 0);

  EXPECT_EQ(arr.GetValue(1, 1, 0), 4);
  EXPECT_EQ(arr.GetValue(1, 1, 1), 0);
  EXPECT_EQ(arr.GetValue(1, 1, 2), 4);
  EXPECT_EQ(arr.GetValue(1, 1, 3), 0);

  EXPECT_EQ(arr.GetValue(1, 2, 0), 4);
  EXPECT_EQ(arr.GetValue(1, 2, 1), 0);
  EXPECT_EQ(arr.GetValue(1, 2, 2), 4);
  EXPECT_EQ(arr.GetValue(1, 2, 3), 0);

  EXPECT_EQ(arr2.GetValue(0, 0, 0), 8);
  EXPECT_EQ(arr2.GetValue(0, 0, 1), 0);
  EXPECT_EQ(arr2.GetValue(0, 0, 2), 8);
  EXPECT_EQ(arr2.GetValue(0, 0, 3), 0);

  EXPECT_EQ(arr2.GetValue(0, 1, 0), 8);
  EXPECT_EQ(arr2.GetValue(0, 1, 1), 0);
  EXPECT_EQ(arr2.GetValue(0, 1, 2), 8);
  EXPECT_EQ(arr2.GetValue(0, 1, 3), 0);

  EXPECT_EQ(arr2.GetValue(0, 2, 0), 8);
  EXPECT_EQ(arr2.GetValue(0, 2, 1), 0);
  EXPECT_EQ(arr2.GetValue(0, 2, 2), 8);
  EXPECT_EQ(arr2.GetValue(0, 2, 3), 0);

  EXPECT_EQ(arr2.GetValue(1, 0, 0), 8);
  EXPECT_EQ(arr2.GetValue(1, 0, 1), 0);
  EXPECT_EQ(arr2.GetValue(1, 0, 2), 8);
  EXPECT_EQ(arr2.GetValue(1, 0, 3), 0);

  EXPECT_EQ(arr2.GetValue(1, 1, 0), 8);
  EXPECT_EQ(arr2.GetValue(1, 1, 1), 0);
  EXPECT_EQ(arr2.GetValue(1, 1, 2), 8);
  EXPECT_EQ(arr2.GetValue(1, 1, 3), 0);

  EXPECT_EQ(arr2.GetValue(1, 2, 0), 8);
  EXPECT_EQ(arr2.GetValue(1, 2, 1), 0);
  EXPECT_EQ(arr2.GetValue(1, 2, 2), 8);
  EXPECT_EQ(arr2.GetValue(1, 2, 3), 0);
}

TEST(Array3DTestSuite, MinusOperator) {
  Array3D arr(2, 3, 4);

  arr[0][0][0] = 4;
  arr[0][0][1] = 0;
  arr[0][0][2] = 4;
  arr[0][0][3] = 0;
  arr[0][0][3] = 0;

  arr[0][1][0] = 4;
  arr[0][1][1] = 0;
  arr[0][1][2] = 4;
  arr[0][1][3] = 0;

  arr[0][2][0] = 4;
  arr[0][2][1] = 0;
  arr[0][2][2] = 4;
  arr[0][2][3] = 0;

  arr[1][0][0] = 4;
  arr[1][0][1] = 0;
  arr[1][0][2] = 4;
  arr[1][0][3] = 0;

  arr[1][1][0] = 4;
  arr[1][1][1] = 0;
  arr[1][1][2] = 4;
  arr[1][1][3] = 0;

  arr[1][2][0] = 4;
  arr[1][2][1] = 0;
  arr[1][2][2] = 4;
  arr[1][2][3] = 0;

  Array3D arr2 = arr - arr;

  EXPECT_EQ(arr2.GetValue(0, 0, 0), 0);
  EXPECT_EQ(arr2.GetValue(0, 0, 1), 0);
  EXPECT_EQ(arr2.GetValue(0, 0, 2), 0);
  EXPECT_EQ(arr2.GetValue(0, 0, 3), 0);

  EXPECT_EQ(arr2.GetValue(0, 1, 0), 0);
  EXPECT_EQ(arr2.GetValue(0, 1, 1), 0);
  EXPECT_EQ(arr2.GetValue(0, 1, 2), 0);
  EXPECT_EQ(arr2.GetValue(0, 1, 3), 0);

  EXPECT_EQ(arr2.GetValue(0, 2, 0), 0);
  EXPECT_EQ(arr2.GetValue(0, 2, 1), 0);
  EXPECT_EQ(arr2.GetValue(0, 2, 2), 0);
  EXPECT_EQ(arr2.GetValue(0, 2, 3), 0);

  EXPECT_EQ(arr2.GetValue(1, 0, 0), 0);
  EXPECT_EQ(arr2.GetValue(1, 0, 1), 0);
  EXPECT_EQ(arr2.GetValue(1, 0, 2), 0);
  EXPECT_EQ(arr2.GetValue(1, 0, 3), 0);

  EXPECT_EQ(arr2.GetValue(1, 1, 0), 0);
  EXPECT_EQ(arr2.GetValue(1, 1, 1), 0);
  EXPECT_EQ(arr2.GetValue(1, 1, 2), 0);
  EXPECT_EQ(arr2.GetValue(1, 1, 3), 0);

  EXPECT_EQ(arr2.GetValue(1, 2, 0), 0);
  EXPECT_EQ(arr2.GetValue(1, 2, 1), 0);
  EXPECT_EQ(arr2.GetValue(1, 2, 2), 0);
  EXPECT_EQ(arr2.GetValue(1, 2, 3), 0);
}

TEST(Array3DTestSuite, GetSet) {
  Array3D arr(2, 3, 4);

  arr[0][0][0] = 4;
  arr[0][0][1] = 0;
  arr[0][0][2] = 4;
  arr[0][0][3] = 0;

  arr[0][1][0] = 4;
  arr[0][1][1] = 0;
  arr[0][1][2] = 4;
  arr[0][1][3] = 0;

  arr[0][2][0] = 4;
  arr[0][2][1] = 0;
  arr[0][2][2] = 4;
  arr[0][2][3] = 0;

  arr[1][0][0] = 4;
  arr[1][0][1] = 0;
  arr[1][0][2] = 4;
  arr[1][0][3] = 0;

  arr[1][1][0] = 4;
  arr[1][1][1] = 0;
  arr[1][1][2] = 4;
  arr[1][1][3] = 0;

  arr[1][2][0] = 4;
  arr[1][2][1] = 0;
  arr[1][2][2] = 4;
  arr[1][2][3] = 0;

  EXPECT_EQ(arr.GetValue(0, 0, 0), 4);
  EXPECT_EQ(arr.GetValue(0, 0, 1), 0);
  EXPECT_EQ(arr.GetValue(0, 0, 2), 4);
  EXPECT_EQ(arr.GetValue(0, 0, 3), 0);

  EXPECT_EQ(arr.GetValue(0, 1, 0), 4);
  EXPECT_EQ(arr.GetValue(0, 1, 1), 0);
  EXPECT_EQ(arr.GetValue(0, 1, 2), 4);
  EXPECT_EQ(arr.GetValue(0, 1, 3), 0);

  EXPECT_EQ(arr.GetValue(0, 2, 0), 4);
  EXPECT_EQ(arr.GetValue(0, 2, 1), 0);
  EXPECT_EQ(arr.GetValue(0, 2, 2), 4);
  EXPECT_EQ(arr.GetValue(0, 2, 3), 0);

  EXPECT_EQ(arr.GetValue(1, 0, 0), 4);
  EXPECT_EQ(arr.GetValue(1, 0, 1), 0);
  EXPECT_EQ(arr.GetValue(1, 0, 2), 4);
  EXPECT_EQ(arr.GetValue(1, 0, 3), 0);

  EXPECT_EQ(arr.GetValue(1, 1, 0), 4);
  EXPECT_EQ(arr.GetValue(1, 1, 1), 0);
  EXPECT_EQ(arr.GetValue(1, 1, 2), 4);
  EXPECT_EQ(arr.GetValue(1, 1, 3), 0);

  EXPECT_EQ(arr.GetValue(1, 2, 0), 4);
  EXPECT_EQ(arr.GetValue(1, 2, 1), 0);
  EXPECT_EQ(arr.GetValue(1, 2, 2), 4);
  EXPECT_EQ(arr.GetValue(1, 2, 3), 0);
}

TEST(Array3DTestSuite, InputOutput) {
  Array3D arr(2, 3, 4);

  arr[0][0][0] = 4;
  arr[0][0][1] = 0;
  arr[0][0][2] = 4;
  arr[0][0][3] = 0;

  arr[0][1][0] = 4;
  arr[0][1][1] = 0;
  arr[0][1][2] = 4;
  arr[0][1][3] = 0;

  arr[0][2][0] = 4;
  arr[0][2][1] = 0;
  arr[0][2][2] = 4;
  arr[0][2][3] = 0;

  arr[1][0][0] = 4;
  arr[1][0][1] = 0;
  arr[1][0][2] = 4;
  arr[1][0][3] = 0;

  arr[1][1][0] = 4;
  arr[1][1][1] = 0;
  arr[1][1][2] = 4;
  arr[1][1][3] = 0;

  arr[1][2][0] = 4;
  arr[1][2][1] = 0;
  arr[1][2][2] = 4;
  arr[1][2][3] = 0;

  std::ostringstream oss;
  std::cout << arr;
  oss << arr;
  std::string output = oss.str();
  std::vector<std::string> lines = SplitString(output);

  EXPECT_EQ(lines[0], "4");
  EXPECT_EQ(lines[1], "0");
  EXPECT_EQ(lines[2], "4");
  EXPECT_EQ(lines[3], "0");

  EXPECT_EQ(lines[4], "4");
  EXPECT_EQ(lines[5], "0");
  EXPECT_EQ(lines[6], "4");
  EXPECT_EQ(lines[7], "0");

  EXPECT_EQ(lines[8], "4");
  EXPECT_EQ(lines[9], "0");
  EXPECT_EQ(lines[10], "4");
  EXPECT_EQ(lines[11], "0");

  EXPECT_EQ(lines[12], "4");
  EXPECT_EQ(lines[13], "0");
  EXPECT_EQ(lines[14], "4");
  EXPECT_EQ(lines[15], "0");

  EXPECT_EQ(lines[16], "4");
  EXPECT_EQ(lines[17], "0");
  EXPECT_EQ(lines[18], "4");
  EXPECT_EQ(lines[19], "0");

  EXPECT_EQ(lines[20], "4");
  EXPECT_EQ(lines[21], "0");
  EXPECT_EQ(lines[22], "4");
  EXPECT_EQ(lines[23], "0");
}

TEST(Array3DTestSuite, InputTest) {
  Array3D arr(2, 3, 4);

  std::istringstream iss("2 3 4 0 0 0 0 0 0 0 0 0 0 0 0 0");

  iss >> arr;

  EXPECT_EQ(arr.GetValue(0, 0, 0), 2);
  EXPECT_EQ(arr.GetValue(0, 0, 1), 3);
  EXPECT_EQ(arr.GetValue(0, 0, 2), 4);
  EXPECT_EQ(arr.GetValue(0, 0, 3), 0);

  EXPECT_EQ(arr.GetValue(0, 1, 0), 0);
  EXPECT_EQ(arr.GetValue(0, 1, 1), 0);
  EXPECT_EQ(arr.GetValue(0, 1, 2), 0);
  EXPECT_EQ(arr.GetValue(0, 1, 3), 0);

  EXPECT_EQ(arr.GetValue(0, 2, 0), 0);
  EXPECT_EQ(arr.GetValue(0, 2, 1), 0);
  EXPECT_EQ(arr.GetValue(0, 2, 2), 0);
  EXPECT_EQ(arr.GetValue(0, 2, 3), 0);

  EXPECT_EQ(arr.GetValue(1, 0, 0), 0);
  EXPECT_EQ(arr.GetValue(1, 0, 1), 0);
  EXPECT_EQ(arr.GetValue(1, 0, 2), 0);
  EXPECT_EQ(arr.GetValue(1, 0, 3), 0);

  EXPECT_EQ(arr.GetValue(1, 1, 0), 0);
  EXPECT_EQ(arr.GetValue(1, 1, 1), 0);
  EXPECT_EQ(arr.GetValue(1, 1, 2), 0);
  EXPECT_EQ(arr.GetValue(1, 1, 3), 0);

  EXPECT_EQ(arr.GetValue(1, 2, 0), 0);
  EXPECT_EQ(arr.GetValue(1, 2, 1), 0);
  EXPECT_EQ(arr.GetValue(1, 2, 2), 0);
  EXPECT_EQ(arr.GetValue(1, 2, 3), 0);
}

TEST(Array3DTestSuite, ValueOverwrite) {
  Array3D arr(2, 3, 4);

  arr[0][0][0] = 131071;
  arr[0][0][0] = 0;

  EXPECT_EQ(arr.GetValue(0, 0, 0), 0);
}
