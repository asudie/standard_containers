#include <gtest/gtest.h>

#include <cstddef>
#include <list>
#include <queue>
#include <string>

#include "s21_containers.h"

TEST(push, test1) {
  s21::Queue<int> first;
  std::queue<int> orig_first;
  first.push(5);
  orig_first.push(5);
  ASSERT_EQ(first.back(), orig_first.back());

  first.push(55);
  orig_first.push(55);
  ASSERT_EQ(first.back(), orig_first.back());
  ASSERT_EQ(first.front(), orig_first.front());
}

TEST(size, test1) {
  s21::Queue<int> first;
  std::queue<int> orig_first;
  first.push(5);
  orig_first.push(5);
  ASSERT_EQ(first.size(), orig_first.size());

  first.push(55);
  orig_first.push(55);
  ASSERT_EQ(first.size(), orig_first.size());
}

TEST(pop, test1) {
  s21::Queue<int> first;
  std::queue<int> orig_first;
  first.push(5);
  orig_first.push(5);
  first.push(55);
  orig_first.push(55);
  first.pop();
  orig_first.pop();
  ASSERT_EQ(first.size(), orig_first.size());
  ASSERT_EQ(first.back(), orig_first.back());
}

TEST(list, test1) {
  s21::Queue<int> first({1, 2, 3, 4, 5});
  std::queue<int> orig_first({1, 2, 3, 4, 5});
  while (first.size() != 1 && orig_first.size() != 1) {
    ASSERT_EQ(first.front(), orig_first.front());
    first.pop();
    orig_first.pop();
  }
}

TEST(copy, test1) {
  s21::Queue<int> st_1;
  std::queue<int> st_original_1;
  st_1.push(5);
  st_original_1.push(5);
  st_1.push(55);
  st_original_1.push(55);
  std::queue<int> st_original_2(st_original_1);
  s21::Queue<int> st_2(st_1);

  ASSERT_EQ(st_1.size(), st_2.size());
  ASSERT_EQ(st_1.back(), st_2.back());
  ASSERT_EQ(st_2.size(), st_original_2.size());
  ASSERT_EQ(st_1.size(), st_original_1.size());
}

TEST(move, test1) {
  s21::Queue<int> st_1({1, 2, 3});
  s21::Queue<int> st_2(std::move(st_1));
  std::queue<int> st_original_1({1, 2, 3});
  std::queue<int> st_original_2(std::move(st_original_1));

  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.size(), st_original_2.size());
  ASSERT_EQ(st_2.front(), st_original_2.front());
}

TEST(equal_op_copy, test1) {
  s21::Queue<int> st_1({1, 2, 3});
  s21::Queue<int> st_2 = st_1;
  std::queue<int> st_original_1({1, 2, 3});
  std::queue<int> st_original_2 = st_original_1;

  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.size(), st_original_2.size());
  ASSERT_EQ(st_2.front(), st_original_2.front());
}

TEST(oper_move, test1) {
  s21::Queue<double> st({11.11, 22.22, 33.33, 44.44, 88.88});
  std::queue<double> st_original({11.11, 22.22, 33.33, 44.44, 88.88});
  s21::Queue<double> st_copy;
  std::queue<double> st_original_copy;
  st_copy = (std::move(st));
  st_original_copy = (std::move(st_original));
  ASSERT_EQ(st_copy.front(), st_original_copy.front());
  ASSERT_EQ(st_copy.back(), st_original_copy.back());
  ASSERT_EQ(st_copy.size(), st_original_copy.size());

  st.push(0.95);
  st_original.push(0.95);
  st.push(0.125);
  st_original.push(0.125);
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(front, test1) {
  s21::Queue<int> st_1({1, 2, 3});
  std::queue<int> st_original_1({1, 2, 3});

  ASSERT_EQ(st_1.front(), st_original_1.front());
  st_1.pop();
  st_original_1.pop();
  ASSERT_EQ(st_1.front(), st_original_1.front());
  st_1.pop();
  st_original_1.pop();
  ASSERT_EQ(st_1.front(), st_original_1.front());
}

TEST(back, test1) {
  s21::Queue<int> st_1;
  std::queue<int> st_original_1;
  st_1.push(1);
  st_original_1.push(1);
  ASSERT_EQ(st_1.back(), st_original_1.back());
  st_1.push(2);
  st_original_1.push(2);
  ASSERT_EQ(st_1.back(), st_original_1.back());
  st_1.push(3);
  st_original_1.push(3);
  ASSERT_EQ(st_1.back(), st_original_1.back());
}

TEST(empty, test1) {
  s21::Queue<int> st_1;
  std::queue<int> st_original_1;

  ASSERT_EQ(st_1.empty(), st_original_1.empty());

  st_1.push(1);
  st_original_1.push(1);

  ASSERT_EQ(st_1.empty(), st_original_1.empty());

  st_1.pop();
  st_original_1.pop();

  ASSERT_EQ(st_1.empty(), st_original_1.empty());
}

TEST(swap, test1) {
  s21::Queue<int> st_1({1, 2, 3});
  std::queue<int> st_original_1({1, 2, 3});
  s21::Queue<int> st_2({4, 5, 6, 7});
  std::queue<int> st_original_2({4, 5, 6, 7});

  st_1.swap(st_2);
  st_original_1.swap(st_original_2);

  while (st_1.size() != 0 && st_original_1.size() != 0) {
    ASSERT_EQ(st_1.front(), st_original_1.front());
    st_1.pop();
    st_original_1.pop();
  }
}
