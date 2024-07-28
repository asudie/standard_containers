#include <gtest/gtest.h>

#include "s21_containersplus.h"

TEST(s21_array, test1) {
  std::array<int, 5> a;
  s21::Array<int, 5> ab;
  ASSERT_TRUE(a.size() == ab.size());
}

TEST(s21_array, test2) {
  s21::Array<int, 6> narr = {1, 2, 3, 4, 5, 6};
  narr.at(1) = 88;
  ASSERT_EQ(narr[1], 88);
}

TEST(s21_array, test3) {
  s21::Array<int, 6> narr({1, 2, 3, 4, 5, 6});
  std::array<int, 6> narr_std({1, 2, 3, 4, 5, 6});
  ASSERT_TRUE(narr.front() == narr_std.front());
}

TEST(s21_array, test4) {
  s21::Array<int, 9> narr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::array<int, 9> narr_std = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  ASSERT_TRUE(narr.back() == narr_std.back());
}

TEST(s21_array, test5) {
  s21::Array<int, 6> narr = {1, 2, 3, 4, 5, 6};
  s21::Array<int, 6> new_arr(narr);
  ASSERT_EQ(new_arr[4], narr[4]);
}

TEST(s21_array, test6) {
  s21::Array<int, 5> arr1 = {1, 2, 3, 4, 5};
  s21::Array<int, 5> arr = {5, 4, 3, 2, 1};
  arr = std::move(arr1);
  for (auto it : arr) {
    std::cout << it << " ";
  }
}

TEST(s21_array, test7) {
  std::array<int, 5> a({1, 2, 3, 4, 5});
  s21::Array<int, 5> ab({1, 2, 3, 4, 5});
  ASSERT_TRUE(a.size() == ab.size());
  for (size_t i = 0; i < a.size(); ++i) {
    ASSERT_TRUE(a.at(i) == ab.at(i));
  }
}

TEST(s21_array, test8) {
  std::array<int, 5> a({1, 2, 3, 4, 5});
  s21::Array<int, 5> ab({1, 2, 3, 4, 5});
  ASSERT_TRUE(*a.data() == *ab.data());
}

TEST(s21_array, test9) {
  std::array<int, 5> a({1, 2, 3, 4, 5});
  s21::Array<int, 5> ab({1, 2, 3, 4, 5});
  ASSERT_TRUE(*a.begin() == *ab.begin());
}

TEST(s21_array, test10) {
  s21::Array<int, 5> ab({1, 2, 3, 4, 5});
  std::array<int, 5> a({1, 2, 3, 4, 5});
  ASSERT_TRUE(*(a.end() - 1) == *(ab.end() - 1));
}

TEST(s21_array, test11) {
  std::array<int, 5> a({1, 2, 3, 4, 5});
  s21::Array<int, 5> ab({1, 2, 3, 4, 5});
  ASSERT_TRUE(a.empty() == ab.empty());
}

TEST(s21_array, test12) {
  std::array<int, 15> a;
  s21::Array<int, 15> ab;
  ASSERT_TRUE(a.max_size() == ab.max_size());
  std::array<double, 6> b;
  s21::Array<double, 6> ba;
  ASSERT_TRUE(b.max_size() == ba.max_size());
  std::array<std::array<int, 100>, 6> c;
  s21::Array<std::array<int, 100>, 6> ca;
  ASSERT_TRUE(c.max_size() == ca.max_size());
}

TEST(s21_array, test13) {
  s21::Array<int, 5> a({1, 2, 3, 4, 5});
  s21::Array<int, 5> b({1, 2, 3, 4, 5});
  s21::Array<int, 5> c({1, 2, 3, 4, 5});
  a.swap(b);
  for (size_t i = 0; i < a.size(); ++i) {
    ASSERT_TRUE(c.at(i) == a.at(i));
  }
}

TEST(s21_array, test14) {
  s21::Array<int, 5> ab({1, 2, 3, 4, 5});
  ab.fill(88);
  for (size_t i = 0; i < ab.size(); ++i) {
    ASSERT_TRUE(ab.at(i) == 88);
  }
}

TEST(s21_array, test15) {
  s21::Array<int, 9> a({1, 2, 3, 4, 5, 6, 7, 8, 9});
  s21::Array<int, 9> b;
  b = std::move(a);
  ASSERT_TRUE(b.size() == 9);
  for (size_t i = 0; i < b.size(); ++i) {
    ASSERT_TRUE(b.at(i) == (int)(i + 1));
  }
}

TEST(s21_array, test16) {
  s21::Array<int, 9> a({1, 2, 3, 4, 5, 6, 7, 8, 9});
  s21::Array<int, 9> b;
  b = a;
  ASSERT_TRUE(b.size() == 9);
  for (size_t i = 0; i < b.size(); ++i) {
    ASSERT_TRUE(b.at(i) == (int)(i + 1));
  }
}

TEST(s21_array, test17) {
  s21::Array<int, 0> ab = {};
  ASSERT_TRUE(ab.empty() == true);
}

TEST(s21_array, test18) {
  s21::Array<int, 4> ab = {1, 2, 3, 4};
  ASSERT_ANY_THROW(ab.at(10));
}
