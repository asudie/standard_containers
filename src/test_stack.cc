#include <gtest/gtest.h>

#include <cstddef>
#include <stack>
#include <string>

#include "s21_containers.h"

TEST(s21_stack_push_top_check, test1) {
  s21::Stack<int> st;
  std::stack<int> st_original;
  st.push(5);
  st_original.push(5);
  ASSERT_EQ(st.top(), st_original.top());

  st.push(55);
  st_original.push(55);
  ASSERT_EQ(st.top(), st_original.top());
}

TEST(s21_stack_push_top_check, test2) {
  s21::Stack<char> st;
  std::stack<char> st_original;
  st.push('a');
  st_original.push('a');
  ASSERT_EQ(st.top(), st_original.top());

  st.push('b');
  st_original.push('b');
  ASSERT_EQ(st.top(), st_original.top());
}

TEST(s21_stack_size_check, test1) {
  s21::Stack<int> st;
  std::stack<int> st_original;
  ASSERT_EQ(st.size(), st_original.size());

  st.push(5);
  st_original.push(5);
  ASSERT_EQ(st.size(), st_original.size());

  st.push(55);
  st_original.push(55);
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_stack_size_check, test2) {
  s21::Stack<char> st;
  std::stack<char> st_original;
  ASSERT_EQ(st.size(), st_original.size());

  st.push('a');
  st_original.push('a');
  ASSERT_EQ(st.size(), st_original.size());

  st.push('b');
  st_original.push('b');
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_stack_empty_check, test1) {
  s21::Stack<int> st;
  std::stack<int> st_original;
  ASSERT_EQ(st.empty(), st_original.empty());

  st.push(5);
  st_original.push(5);
  ASSERT_EQ(st.empty(), st_original.empty());

  st.push(55);
  st_original.push(55);
  ASSERT_EQ(st.empty(), st_original.empty());
}

TEST(s21_stack_empty_check, test2) {
  s21::Stack<char> st;
  std::stack<char> st_original;
  ASSERT_EQ(st.empty(), st_original.empty());

  st.push('a');
  st_original.push('a');
  ASSERT_EQ(st.empty(), st_original.empty());

  st.push('b');
  st_original.push('b');
  ASSERT_EQ(st.empty(), st_original.empty());
}

TEST(s21_stack_pop_check, test1) {
  s21::Stack<int> st;
  std::stack<int> st_original;
  ASSERT_EQ(st.size(), st_original.size());

  st.push(5);
  st_original.push(5);
  st.push(55);
  st_original.push(55);
  st.pop();
  st_original.pop();

  ASSERT_EQ(st.top(), st_original.top());
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_stack_pop_check, test2) {
  s21::Stack<char> st;
  std::stack<char> st_original;
  st.push('a');
  st_original.push('a');
  st.push('b');
  st_original.push('b');
  st.pop();
  st_original.pop();
  ASSERT_EQ(st.top(), st_original.top());
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_stack_initializer_check, test1) {
  s21::Stack<int> st({11, 22, 33, 44, 88});
  std::stack<int> st_original({11, 22, 33, 44, 88});
  ASSERT_EQ(st.top(), st_original.top());
  ASSERT_EQ(st.size(), st_original.size());

  st.push(5);
  st_original.push(5);
  st.push(55);
  st_original.push(55);
  st.pop();
  st_original.pop();
  ASSERT_EQ(st.top(), st_original.top());
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_stack_initializer_check, test2) {
  s21::Stack<double> st({11.11, 22.22, 33.33, 44.44, 88.88});
  std::stack<double> st_original({11.11, 22.22, 33.33, 44.44, 88.88});
  ASSERT_DOUBLE_EQ(st.top(), st_original.top());
  ASSERT_EQ(st.size(), st_original.size());

  st.push(5.5);
  st_original.push(5.5);
  st.push(55.55);
  st_original.push(55.55);
  st.pop();
  st_original.pop();
  ASSERT_DOUBLE_EQ(st.top(), st_original.top());
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_stack_copy_check, test1) {
  s21::Stack<int> st_1;
  std::stack<int> st_original_1;
  st_1.push(5);
  st_original_1.push(5);
  st_1.push(55);
  st_original_1.push(55);
  std::stack<int> st_original_2(st_original_1);
  s21::Stack<int> st_2(st_1);

  ASSERT_EQ(st_1.size(), st_2.size());
  ASSERT_EQ(st_1.top(), st_2.top());
  ASSERT_EQ(st_2.size(), st_original_2.size());
  ASSERT_EQ(st_1.size(), st_original_1.size());
}

TEST(s21_stack_copy_check, test2) {
  s21::Stack<int> st_1({7, 8, 9});
  std::stack<int> st_original_1({7, 8, 9});
  st_1.push(5);
  st_original_1.push(5);
  st_1.push(55);
  st_original_1.push(55);
  std::stack<int> st_original_2(st_original_1);
  s21::Stack<int> st_2(st_1);

  ASSERT_EQ(st_1.size(), st_2.size());
  ASSERT_EQ(st_1.top(), st_2.top());
  ASSERT_EQ(st_2.size(), st_original_2.size());
  ASSERT_EQ(st_1.size(), st_original_1.size());
}

TEST(s21_stack_copy_check, test3) {
  s21::Stack<char> st_1({'a', 'b', 'c'});
  std::stack<char> st_original_1({'a', 'b', 'c'});
  std::stack<char> st_original_2(st_original_1);
  s21::Stack<char> st_2(st_1);

  ASSERT_EQ(st_1.size(), st_2.size());
  ASSERT_EQ(st_1.top(), st_2.top());
  ASSERT_EQ(st_2.size(), st_original_2.size());
  ASSERT_EQ(st_1.size(), st_original_1.size());
}

TEST(s21_stack_copy_oper_check, test1) {
  s21::Stack<int> st_1;
  std::stack<int> st_original_1;
  st_1.push(5);
  st_original_1.push(5);
  st_1.push(55);
  st_original_1.push(55);
  std::stack<int> st_original_2;
  st_original_2 = st_original_1;
  s21::Stack<int> st_2;
  st_2 = st_1;

  ASSERT_EQ(st_1.size(), st_2.size());
  ASSERT_EQ(st_1.top(), st_2.top());
  ASSERT_EQ(st_original_1.size(), st_1.size());
  ASSERT_EQ(st_original_2.size(), st_2.size());
}

TEST(s21_stack_copy_oper_check, test2) {
  s21::Stack<int> st_1;
  std::stack<int> st_original_1;
  st_1.push(5);
  st_original_1.push(5);
  st_1.push(55);
  st_original_1.push(55);
  std::stack<int> st_original_2;
  st_original_2 = st_original_1;
  s21::Stack<int> st_2;
  st_2 = st_1;

  ASSERT_EQ(st_1.size(), st_2.size());
  ASSERT_EQ(st_1.top(), st_2.top());
  ASSERT_EQ(st_original_1.size(), st_1.size());
  ASSERT_EQ(st_original_2.size(), st_2.size());
}

TEST(s21_stack_copy_oper_check, test3) {
  s21::Stack<char> st_1({'a', 'b', 'c'});
  std::stack<char> st_original_1({'a', 'b', 'c'});
  std::stack<char> st_original_2;
  st_original_2 = st_original_1;
  s21::Stack<char> st_2;
  st_2 = st_1;

  ASSERT_EQ(st_1.size(), st_2.size());
  ASSERT_EQ(st_1.top(), st_2.top());
  ASSERT_EQ(st_2.size(), st_original_2.size());
  ASSERT_EQ(st_1.size(), st_original_1.size());
}

TEST(s21_stack_copy_oper_check, test4) {
  s21::Stack<char> st_1({'a', 'b', 'c'});
  std::stack<char> st_original_1({'a', 'b', 'c'});
  st_original_1 = st_original_1;
  st_1 = st_1;

  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_1.top(), st_original_1.top());
}

TEST(s21_stack_move_check, test1) {
  s21::Stack<int> st_1({1, 2, 3});
  s21::Stack<int> st_2(std::move(st_1));
  std::stack<int> st_original_1({1, 2, 3});
  std::stack<int> st_original_2(std::move(st_original_1));

  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.size(), st_original_2.size());
  ASSERT_EQ(st_2.top(), st_original_2.top());
  ASSERT_EQ(st_1.empty(), st_original_1.empty());
}

TEST(s21_stack_move_oper_check, test1) {
  s21::Stack<int> st_1({1, 2, 3});
  s21::Stack<int> st_2;
  st_2 = (std::move(st_1));
  std::stack<int> st_original_1({1, 2, 3});
  std::stack<int> st_original_2;
  st_original_2 = (std::move(st_original_1));
  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.size(), st_original_2.size());
  ASSERT_EQ(st_2.top(), st_original_2.top());

  st_1.push(5);
  st_original_1.push(5);
  st_2.push(55);
  st_original_2.push(55);
  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.size(), st_original_2.size());
  ASSERT_EQ(st_1.top(), st_original_1.top());
  ASSERT_EQ(st_2.top(), st_original_2.top());
}

TEST(s21_stack_move_oper_check, test2) {
  s21::Stack<int> st_1({1, 2, 3});
  s21::Stack<int> st_2;
  st_2 = (std::move(st_1));
  std::stack<int> st_original_1({1, 2, 3});
  std::stack<int> st_original_2;
  st_original_2 = (std::move(st_original_1));

  ASSERT_EQ(st_2.size(), st_original_2.size());
  ASSERT_EQ(st_2.top(), st_original_2.top());
  ASSERT_EQ(st_1.size(), st_original_1.size());
}

TEST(s21_stack_swap, test1) {
  s21::Stack<int> st_1({11, 22, 33, 44, 88});
  s21::Stack<int> st_2({55, 66, 77, 99, 0});
  std::stack<int> st_original_1({11, 22, 33, 44, 88});
  std::stack<int> st_original_2({55, 66, 77, 99, 0});
  ASSERT_EQ(st_1.top(), st_original_1.top());
  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.top(), st_original_2.top());
  ASSERT_EQ(st_2.size(), st_original_2.size());

  st_2.swap(st_1);
  st_original_2.swap(st_original_1);
  ASSERT_EQ(st_1.top(), st_original_1.top());
  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.top(), st_original_2.top());
  ASSERT_EQ(st_2.size(), st_original_2.size());

  st_1.swap(st_2);
  st_original_1.swap(st_original_2);
  ASSERT_EQ(st_1.top(), st_original_1.top());
  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.top(), st_original_2.top());
  ASSERT_EQ(st_2.size(), st_original_2.size());
}

TEST(s21_stack_swap, test2) {
  s21::Stack<std::string> st_1({"aa", "bb", "cc"});
  s21::Stack<std::string> st_2({"aboba"});
  std::stack<std::string> st_original_1({"aa", "bb", "cc"});
  std::stack<std::string> st_original_2({"aboba"});
  ASSERT_EQ(st_1.top(), st_original_1.top());
  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.top(), st_original_2.top());
  ASSERT_EQ(st_2.size(), st_original_2.size());

  st_2.swap(st_1);
  st_original_2.swap(st_original_1);
  ASSERT_EQ(st_1.top(), st_original_1.top());
  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.top(), st_original_2.top());
  ASSERT_EQ(st_2.size(), st_original_2.size());

  st_1.swap(st_2);
  st_original_1.swap(st_original_2);
  ASSERT_EQ(st_1.top(), st_original_1.top());
  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.top(), st_original_2.top());
  ASSERT_EQ(st_2.size(), st_original_2.size());
}
