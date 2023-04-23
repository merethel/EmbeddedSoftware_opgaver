#include <gtest/gtest.h>

extern "C" {
#include "my_string_func.h"
}

TEST(StringManipulation, my_strlen ) {
  EXPECT_EQ(my_length("Hello, world!"), 14);
  EXPECT_EQ(my_length(""), 1);
}

/*TEST(StringManipulation, my_strcmp) {
  EXPECT_TRUE(my_strcmp("Hello, world!", "Hello, world!")==0);
  EXPECT_TRUE(my_strcmp("Hi", "Hi!")!=0);
  EXPECT_TRUE(my_strcmp("Hey", "Hi!")!=0);
}

TEST(StringManipulation, my_strcpy) {
  char dest[20];
  my_strcpy(dest, "Hello, world!");
  EXPECT_STREQ(dest, "Hello, world!");
  my_strcpy(dest, "");
  EXPECT_STREQ(dest, "");
}*/

TEST(StringManipulation, my_strUpper) {
  char dest[20];
  my_to_upper( "Hello, world!",dest);
  EXPECT_STREQ(dest, "HELLO, WORLD!");
}
