#include <gtest/gtest.h>

#include "s21_containers.h"

TEST(s21_vector, test1) {
  s21::Vector<int> a;
  std::vector<int> b;
  ASSERT_TRUE(a.size() == b.size());
  ASSERT_TRUE(a.capacity() == b.capacity());
  ASSERT_TRUE(a.data() == b.data());
}

TEST(s21_vector, test2) {
  s21::Vector<int> narr({1, 2, 3, 4, 5, 6, 7, 8});
  narr.at(1) = 88;
  ASSERT_EQ(narr[1], 88);
}

TEST(s21_vector, test3) {
  s21::Vector<int> narr({1, 2, 3, 4, 5, 6});
  std::vector<int> narr_std({1, 2, 3, 4, 5, 6});
  ASSERT_TRUE(narr.front() == narr_std.front());
}

TEST(s21_vector, test4) {
  s21::Vector<int> narr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> narr_std = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  ASSERT_TRUE(narr.back() == narr_std.back());
}

TEST(s21_vector, test5) {
  s21::Vector<int> narr = {1, 2, 3, 4, 5, 6};
  s21::Vector<int> new_arr(narr);
  ASSERT_EQ(new_arr[4], narr[4]);
}

TEST(s21_vector, test6) {
  s21::Vector<int> arr1 = {1, 2, 3, 4, 5};
  s21::Vector<int> arr = {5, 4, 3, 2, 1};
  arr = std::move(arr1);
  for (auto it : arr) {
    std::cout << it << " ";
  }
}

TEST(s21_vector, test7) {
  std::vector<int> a({1, 2, 3, 4, 5});
  s21::Vector<int> ab({1, 2, 3, 4, 5});
  ASSERT_TRUE(a.size() == ab.size());
  for (size_t i = 0; i < a.size(); ++i) {
    ASSERT_TRUE(a.at(i) == ab.at(i));
  }
}

TEST(s21_vector, test8) {
  std::vector<int> a({1, 2, 3, 4, 5});
  s21::Vector<int> ab({1, 2, 3, 4, 5});
  ASSERT_TRUE(*a.data() == *ab.data());
}

TEST(s21_vector, test9) {
  std::vector<int> a({1, 2, 3, 4, 5});
  s21::Vector<int> ab({1, 2, 3, 4, 5});
  ASSERT_TRUE(*a.begin() == *ab.begin());
}

TEST(s21_vector, test10) {
  std::vector<int> a({1, 2, 3, 4, 5});
  s21::Vector<int> ab({1, 2, 3, 4, 5});
  ASSERT_TRUE(*(a.end() - 1) == *(ab.end() - 1));
}

TEST(s21_vector, test11) {
  std::vector<int> a({1, 2, 3, 4, 5});
  s21::Vector<int> ab({1, 2, 3, 4, 5});
  ASSERT_TRUE(a.empty() == ab.empty());
}

TEST(s21_vector, test13) {
  s21::Vector<int> a({1, 2, 3, 4, 5});
  s21::Vector<int> b({1, 2, 3, 4, 5});
  s21::Vector<int> c({1, 2, 3, 4, 5});
  a.swap(b);
  for (size_t i = 0; i < a.size(); ++i) {
    ASSERT_TRUE(c.at(i) == a.at(i));
  }
}

TEST(s21_vector, test15) {
  s21::Vector<int> a({1, 2, 3, 4, 5, 6, 7, 8, 9});
  s21::Vector<int> b;
  b = std::move(a);
  ASSERT_TRUE(b.size() == 9);
  for (size_t i = 0; i < b.size(); ++i) {
    ASSERT_TRUE(b.at(i) == (int)(i + 1));
  }
}

TEST(s21_vector, test16) {
  s21::Vector<int> a({1, 2, 3, 4, 5, 6, 7, 8, 9});
  s21::Vector<int> b;
  b = a;
  ASSERT_TRUE(b.size() == 9);
  for (size_t i = 0; i < b.size(); ++i) {
    ASSERT_TRUE(b.at(i) == (int)(i + 1));
  }
}

TEST(s21_vector, test17) {
  s21::Vector<int> ab;
  ASSERT_TRUE(ab.empty() == true);
}

TEST(s21_vector, test18) {
  s21::Vector<int> ab = {1, 2, 3, 4};
  ASSERT_ANY_THROW(ab.at(10));
}

TEST(s21_vector, test19) {
  std::vector<int> a({1, 2, 3, 4, 5});
  s21::Vector<int> ab({1, 2, 3, 4, 5});
  ASSERT_TRUE(a.max_size() == ab.max_size());
  for (size_t i = 0; i < a.size(); ++i) {
    ASSERT_TRUE(a.at(i) == ab.at(i));
  }
}

TEST(s21_vector, test20) {
  std::vector<int> a({1, 2, 3, 4});
  s21::Vector<int> ab({1, 2, 3, 4, 5});
  ASSERT_TRUE(a.max_size() == ab.max_size());
  ab.pop_back();
  for (size_t i = 0; i < a.size(); ++i) {
    ASSERT_TRUE(a.at(i) == ab.at(i));
  }
}

TEST(s21_vector, test21) {
  class Aboba {
   public:
    Aboba() = delete;
    Aboba(int data) : data_(data) {}

    int GetData() const noexcept { return data_; };

   private:
    int data_;
  };
  s21::Vector<Aboba> v;
  v.reserve(15);
  v.push_back(Aboba(7));
  v.push_back(Aboba(14));

  ASSERT_EQ(v.size(), 2);
  ASSERT_EQ(v.capacity(), 15);
  ASSERT_EQ(v.at(0).GetData(), 7);
  ASSERT_EQ(v.back().GetData(), 14);
  v.shrink_to_fit();

  ASSERT_EQ(v.capacity(), 2);
  ASSERT_EQ(v.at(0).GetData(), 7);
  ASSERT_EQ(v.back().GetData(), 14);
}
