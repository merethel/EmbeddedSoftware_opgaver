#include <gtest/gtest.h>

extern "C" {
#include "rectangle.h"
}


TEST(calc, GetArea) {
  rectangle_t myRectangle;
  set_dimensions(&myRectangle, 2,2);
  EXPECT_EQ(get_area(myRectangle), 4);
  set_dimensions(&myRectangle, 3,4);
  EXPECT_EQ(get_area(myRectangle), 12);
}

TEST(calc, GetParimeter) {
  rectangle_t myRectangle;
  set_dimensions(&myRectangle, 2,2);
  EXPECT_EQ(get_perimeter(myRectangle), 8);
  set_dimensions(&myRectangle, 3,4);
  EXPECT_EQ(get_perimeter(myRectangle), 14);
}

