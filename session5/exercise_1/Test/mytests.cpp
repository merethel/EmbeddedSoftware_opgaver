#include <gtest/gtest.h>

extern "C" {
#include "rectangle.h"
}

TEST(rectangle, rectangle_setGetWidth){
  rectangle_setWidth(2);
  EXPECT_EQ(rectangle_getWidth(), 2);
}

TEST(rectangle, rectangle_setGetHeight){
  rectangle_setHeight(2);
  EXPECT_EQ(rectangle_getHeight(), 2);
}

TEST(rectangle, rectangle_getArea){
  rectangle_setWidth(2);
  rectangle_setHeight(2);
  EXPECT_EQ(rectangle_getArea(), 4);
}
