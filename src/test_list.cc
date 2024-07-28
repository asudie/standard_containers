#include <gtest/gtest.h>

#include <cstddef>
#include <iterator>
#include <list>
#include <string>

#include "s21_containers.h"

TEST(s21_list_push_check, test1) {
  s21::List<int> st;
  std::list<int> st_original;
  st.push_back(5);
  st_original.push_back(5);
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());

  st.push_back(55);
  st_original.push_back(55);
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_list_push_check, test2) {
  s21::List<int> st;
  std::list<int> st_original;
  st.push_front(5);
  st_original.push_front(5);
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());

  st.push_front(55);
  st_original.push_front(55);
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_list_push_check, test3) {
  s21::List<char> st;
  std::list<char> st_original;
  st.push_front('a');
  st_original.push_front('a');
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());

  st.push_front('b');
  st_original.push_front('b');
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());

  st.push_front('c');
  st_original.push_front('c');
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_list_create_n_check, test1) {
  s21::List<char> st(3);
  std::list<char> st_original(3);
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());

  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_list_create_n_check, test2) {
  s21::List<int> st(3);
  std::list<int> st_original(3);
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_list_create_n_check, test3) {
  s21::List<double> st(3);
  std::list<double> st_original(3);
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_list_initializer_check, test1) {
  s21::List<int> st({11, 22, 33, 44, 88});
  std::list<int> st_original({11, 22, 33, 44, 88});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  st.push_back(5);
  st_original.push_back(5);
  st.push_front(55);
  st_original.push_front(55);
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_list_initializer_check, test2) {
  s21::List<double> st({11.11, 22.22, 33.33, 44.44, 88.88});
  std::list<double> st_original({11.11, 22.22, 33.33, 44.44, 88.88});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  st.push_back(5.5);
  st_original.push_back(5.5);
  st.push_front(55.55);
  st_original.push_front(55.55);
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_list_constr_copy_check, test1) {
  s21::List<double> st({11.11, 22.22, 33.33, 44.44, 88.88});
  std::list<double> st_original({11.11, 22.22, 33.33, 44.44, 88.88});
  s21::List<double> st_copy = st;
  std::list<double> st_original_copy = st_original;
  ASSERT_EQ(st_copy.front(), st_original_copy.front());
  ASSERT_EQ(st_copy.back(), st_original_copy.back());
  ASSERT_EQ(st_copy.size(), st_original_copy.size());
}

TEST(s21_list_oper_copy_check, test1) {
  s21::List<double> st({11.11, 22.22, 33.33, 44.44, 88.88});
  std::list<double> st_original({11.11, 22.22, 33.33, 44.44, 88.88});
  s21::List<double> st_copy;
  std::list<double> st_original_copy;
  st_copy = st;
  st_original_copy = st_original;
  ASSERT_EQ(st_copy.front(), st_original_copy.front());
  ASSERT_EQ(st_copy.back(), st_original_copy.back());
  ASSERT_EQ(st_copy.size(), st_original_copy.size());

  st.push_back(5.5);
  st_original.push_back(5.5);
  st.push_front(55.55);
  st_original.push_front(55.55);
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_list_constr_move_check, test1) {
  s21::List<double> st({11.11, 22.22, 33.33, 44.44, 88.88});
  std::list<double> st_original({11.11, 22.22, 33.33, 44.44, 88.88});
  s21::List<double> st_copy(std::move(st));
  std::list<double> st_original_copy(std::move(st_original));
  ASSERT_EQ(st_copy.front(), st_original_copy.front());
  ASSERT_EQ(st_copy.back(), st_original_copy.back());
  ASSERT_EQ(st_copy.size(), st_original_copy.size());

  st.push_front(0.95);
  st_original.push_front(0.95);
  st.push_back(0.125);
  st_original.push_back(0.125);
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_list_oper_move_check, test1) {
  s21::List<double> st({11.11, 22.22, 33.33, 44.44, 88.88});
  std::list<double> st_original({11.11, 22.22, 33.33, 44.44, 88.88});
  s21::List<double> st_copy;
  std::list<double> st_original_copy;
  st_copy = (std::move(st));
  st_original_copy = (std::move(st_original));
  ASSERT_EQ(st_copy.front(), st_original_copy.front());
  ASSERT_EQ(st_copy.back(), st_original_copy.back());
  ASSERT_EQ(st_copy.size(), st_original_copy.size());

  st.push_front(0.95);
  st_original.push_front(0.95);
  st.push_back(0.125);
  st_original.push_back(0.125);
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_list_pop_check, test1) {
  s21::List<int> st;
  std::list<int> st_original;
  st.push_back(5);
  st_original.push_back(5);
  st.push_back(55);
  st_original.push_back(55);
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
  st.pop_back();
  st_original.pop_back();
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
  st.pop_back();
  st_original.pop_back();

  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
  ASSERT_EQ(st.empty(), st_original.empty());
}

TEST(s21_list_pop_check, test2) {
  s21::List<int> st;
  std::list<int> st_original;
  st.push_front(5);
  st_original.push_front(5);
  st.push_front(55);
  st_original.push_front(55);
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
  st.pop_front();
  st_original.pop_front();
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
  st.pop_front();
  st_original.pop_front();
  ASSERT_EQ(st.size(), st_original.size());
  ASSERT_EQ(st.empty(), st_original.empty());
}

TEST(s21_list_reverse_check, test1) {
  s21::List<char> st;
  std::list<char> st_original;
  st.push_front('a');
  st_original.push_front('a');
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());

  st.push_back('b');
  st_original.push_back('b');
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());

  st.push_front('c');
  st_original.push_front('c');
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  st.reverse();
  st_original.reverse();
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  st.pop_front();
  st_original.pop_front();
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  st.reverse();
  st_original.reverse();
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_list_reverse_check, test2) {
  s21::List<int> st({1, 2, 3, 4, 5, 6, 7, 8, 9});
  std::list<int> st_original({1, 2, 3, 4, 5, 6, 7, 8, 9});
  st.reverse();
  st_original.reverse();
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<int>::iterator it = st.begin();
  std::list<int>::iterator it_original = st_original.begin();
  while (it != st.end()) {
    ASSERT_EQ(*it, *it_original);
    ++it;
    ++it_original;
  }

  it = st.end();
  it_original = st_original.end();
  --it;
  --it_original;
  while (it != st.begin()) {
    ASSERT_EQ(*it, *it_original);
    --it;
    --it_original;
  }
  ASSERT_EQ(*it, *it_original);
  --it;
  --it_original;
  --it;
  --it_original;
  ASSERT_EQ(*it, *it_original);
}

TEST(s21_list_reverse_check, test3) {
  s21::List<int> st({1});
  std::list<int> st_original({1});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
  st.reverse();
  st_original.reverse();
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<int>::iterator it = st.begin();
  std::list<int>::iterator it_original = st_original.begin();
  while (it != st.end()) {
    ASSERT_EQ(*it, *it_original);
    ++it;
    ++it_original;
  }
}

TEST(s21_list_erase_check, test1) {
  s21::List<int> st({1, 2, 3, 4, 5, 6, 7, 8, 9});
  std::list<int> st_original({1, 2, 3, 4, 5, 6, 7, 8, 9});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<int>::iterator it = st.begin();
  std::list<int>::iterator it_original = st_original.begin();
  st.erase(it);
  st_original.erase(it_original);
  it = st.begin();
  it_original = st_original.begin();
  while (it != st.end()) {
    ASSERT_EQ(*it, *it_original);
    ++it;
    ++it_original;
  }
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_list_erase_check, test2) {
  s21::List<int> st({1, 2, 3, 4, 5, 6, 7, 8, 9});
  std::list<int> st_original({1, 2, 3, 4, 5, 6, 7, 8, 9});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<int>::iterator it = st.end();
  std::list<int>::iterator it_original = st_original.end();
  --it;
  --it_original;
  st.erase(it);
  st_original.erase(it_original);
  it = st.begin();
  it_original = st_original.begin();
  while (it != st.end()) {
    ASSERT_EQ(*it, *it_original);
    ++it;
    ++it_original;
  }
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_list_erase_check, test3) {
  s21::List<int> st({1, 2, 3, 4, 5, 6, 7, 8, 9});
  std::list<int> st_original({1, 2, 3, 4, 5, 6, 7, 8, 9});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<int>::iterator it = st.end();
  std::list<int>::iterator it_original = st_original.end();
  for (int i = 1; i < 5; ++i) {
    --it;
    --it_original;
  }
  st.erase(it);
  st_original.erase(it_original);
  it = st.begin();
  it_original = st_original.begin();
  while (it != st.end()) {
    ASSERT_EQ(*it, *it_original);
    ++it;
    ++it_original;
  }
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_list_erase_check, test4) {
  s21::List<int> st({1, 2, 3, 4, 5, 6, 7, 8, 9});
  std::list<int> st_original({1, 2, 3, 4, 5, 6, 7, 8, 9});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<int>::iterator it = st.begin();
  std::list<int>::iterator it_original = st_original.begin();
  st.erase(it);
  st_original.erase(it_original);
  it = st.end();
  it_original = st_original.end();
  --it;
  --it_original;
  while (it != st.begin()) {
    ASSERT_EQ(*it, *it_original);
    --it;
    --it_original;
  }
  ASSERT_EQ(*it, *it_original);
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_list_erase_check, test5) {
  s21::List<int> st({1, 2, 3, 4, 5, 6, 7, 8, 9});
  std::list<int> st_original({1, 2, 3, 4, 5, 6, 7, 8, 9});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<int>::iterator it = st.end();
  std::list<int>::iterator it_original = st_original.end();
  --it;
  --it_original;
  st.erase(it);
  st_original.erase(it_original);
  it = st.end();
  it_original = st_original.end();
  --it;
  --it_original;
  while (it != st.begin()) {
    ASSERT_EQ(*it, *it_original);
    --it;
    --it_original;
  }
  ASSERT_EQ(*it, *it_original);
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_list_erase_check, test6) {
  s21::List<int> st({1, 2, 3, 4, 5, 6, 7, 8, 9});
  std::list<int> st_original({1, 2, 3, 4, 5, 6, 7, 8, 9});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<int>::iterator it = st.end();
  std::list<int>::iterator it_original = st_original.end();
  for (int i = 1; i < 5; ++i) {
    --it;
    --it_original;
  }
  st.erase(it);
  st_original.erase(it_original);
  it = st.end();
  it_original = st_original.end();
  --it;
  --it_original;
  while (it != st.begin()) {
    ASSERT_EQ(*it, *it_original);
    --it;
    --it_original;
  }
  ASSERT_EQ(*it, *it_original);
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_list_erase_check, test7) {
  s21::List<int> st({81});
  std::list<int> st_original({81});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<int>::iterator it = st.begin();
  std::list<int>::iterator it_original = st_original.begin();
  st.erase(it);
  st_original.erase(it_original);
  it = st.begin();
  it_original = st_original.begin();
  while (it != st.end()) {
    ASSERT_EQ(*it, *it_original);
    ++it;
    ++it_original;
  }
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_list_erase_check, test8) {
  s21::List<int> st({22});
  std::list<int> st_original({22});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<int>::iterator it = st.end();
  std::list<int>::iterator it_original = st_original.end();
  --it;
  --it_original;
  st.erase(it);
  st_original.erase(it_original);
  it = st.begin();
  it_original = st_original.begin();
  while (it != st.end()) {
    ASSERT_EQ(*it, *it_original);
    ++it;
    ++it_original;
  }
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_list_bool_check, test1) {
  s21::List<int> st({1, 2, 3, 4, 5, 6, 7, 8, 9});
  std::list<int> st_original({1, 2, 3, 4, 5, 6, 7, 8, 9});

  s21::List<int>::iterator it_1 = st.end();
  std::list<int>::iterator it_original_1 = st_original.end();
  --it_1;
  --it_original_1;

  s21::List<int>::iterator it_2 = st.end();
  std::list<int>::iterator it_original_2 = st_original.end();
  ASSERT_EQ((it_1 == it_2), (it_original_1 == it_original_2));
  ASSERT_EQ((it_1 != it_2), (it_original_1 != it_original_2));

  --it_2;
  --it_original_2;
  while (it_1 != st.end()) {
    ASSERT_EQ((it_1 == it_2), (it_original_1 == it_original_2));
    ASSERT_EQ((it_1 != it_2), (it_original_1 != it_original_2));
    ++it_1;
    ++it_original_1;
    ++it_2;
    ++it_original_2;
  }
}

TEST(s21_list_bool_check, test2) {
  s21::List<int> st({1, 2, 3, 4, 5, 6, 7, 8, 9});
  std::list<int> st_original({1, 2, 3, 4, 5, 6, 7, 8, 9});

  s21::List<int>::iterator it_1 = st.end();
  std::list<int>::iterator it_original_1 = st_original.end();
  --it_1;
  --it_original_1;
  s21::List<int>::iterator it_2 = it_1;
  std::list<int>::iterator it_original_2 = it_original_1;
  while (it_1 != st.end()) {
    ASSERT_EQ((it_1 == it_2), (it_original_1 == it_original_2));
    ASSERT_EQ((it_1 != it_2), (it_original_1 != it_original_2));
    ++it_1;
    ++it_original_1;
    ++it_2;
    ++it_original_2;
  }
}

TEST(s21_list_empty_check, test) {
  s21::List<int> st;
  std::list<int> st_original;
  ASSERT_EQ(st.size(), st_original.size());
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.empty(), st_original.empty());
}

TEST(s21_list_begin_check, test1) {
  s21::List<int> st;
  st.push_back(1);
  st.push_back(2);
  st.push_back(3);
  st.push_back(4);
  std::list<int> st_original({1, 2, 3, 4});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<int>::iterator it = st.begin();
  std::list<int>::iterator it_original = st_original.begin();
  ASSERT_EQ(*it, *it_original);

  ++it;
  ++it_original;
  ASSERT_EQ(*it, *it_original);

  ++it;
  ++it_original;
  ASSERT_EQ(*it, *it_original);

  ++it;
  ++it_original;
  ASSERT_EQ(*it, *it_original);

  ++it;
  ++it_original;

  ++it;
  ++it_original;
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_list_end_check, test1) {
  s21::List<double> st;
  st.push_front(4.4);
  st.push_front(3.3);
  st.push_front(2.2);
  st.push_front(1.1);
  std::list<double> st_original({1.1, 2.2, 3.3, 4.4});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<double>::iterator it = st.end();
  std::list<double>::iterator it_original = st_original.end();
  --it;
  --it_original;
  ASSERT_EQ(*it, *it_original);

  --it;
  --it_original;
  ASSERT_EQ(*it, *it_original);

  --it;
  --it_original;
  ASSERT_EQ(*it, *it_original);

  --it;
  --it_original;
  ASSERT_EQ(*it, *it_original);

  --it;
  --it_original;

  --it;
  --it_original;
  ASSERT_EQ(*it, *it_original);
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
}

TEST(s21_list_it_check, test1) {
  s21::List<char> st;
  st.push_front('d');
  st.push_front('c');
  st.push_front('b');
  st.push_front('a');
  std::list<char> st_original({'a', 'b', 'c', 'd'});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<char>::iterator it = st.begin();
  std::list<char>::iterator it_original = st_original.begin();

  for (; it != st.end(); ++it) {
    ASSERT_EQ(*it, *it_original);
    ++it_original;
  }
}

TEST(s21_list_it_check, test2) {
  s21::List<int> st;
  st.push_back(1);
  st.push_back(2);
  st.push_back(3);
  st.push_back(4);
  st.push_back(5);
  std::list<int> st_original({1, 2, 3, 4, 5});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<int>::iterator it = st.begin();
  std::list<int>::iterator it_original = st_original.begin();

  for (; it != st.end(); ++it) {
    ASSERT_EQ(*it, *it_original);
    ++it_original;
  }
}

TEST(s21_list_insert_check, test1) {
  s21::List<int> st;
  st.push_back(1);
  st.push_back(2);
  st.push_back(3);
  st.push_back(4);
  st.push_back(5);
  std::list<int> st_original({1, 2, 3, 4, 5});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<int>::iterator it = st.begin();
  std::list<int>::iterator it_original = st_original.begin();

  st.insert(it, 88);
  st_original.insert(it_original, 88);
  ASSERT_EQ(*it, *it_original);
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  it = st.begin();
  it_original = st_original.begin();
  for (; it != st.end(); ++it) {
    ASSERT_EQ(*it, *it_original);
    ++it_original;
  }
}

TEST(s21_list_insert_check, test2) {
  s21::List<int> st;
  st.push_back(1);
  st.push_back(2);
  st.push_back(3);
  st.push_back(4);
  st.push_back(5);
  std::list<int> st_original({1, 2, 3, 4, 5});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<int>::iterator it = st.begin();
  std::list<int>::iterator it_original = st_original.begin();
  ++it;
  ++it;
  ++it_original;
  ++it_original;
  st.insert(it, 88);
  st_original.insert(it_original, 88);
  ASSERT_EQ(*it, *it_original);
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  it = st.begin();
  it_original = st_original.begin();
  for (; it != st.end(); ++it) {
    ASSERT_EQ(*it, *it_original);
    ++it_original;
  }
}

TEST(s21_list_insert_check, test3) {
  s21::List<int> st;
  st.push_back(1);
  st.push_back(2);
  st.push_back(3);
  st.push_back(4);
  st.push_back(5);
  std::list<int> st_original({1, 2, 3, 4, 5});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<int>::iterator it = st.end();
  std::list<int>::iterator it_original = st_original.end();
  st.insert(it, 88);
  st_original.insert(it_original, 88);
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  it = st.begin();
  it_original = st_original.begin();
  for (; it != st.end(); ++it) {
    ASSERT_EQ(*it, *it_original);
    ++it_original;
  }
}

TEST(s21_list_insert_check, test4) {
  s21::List<char> st({'a', 'b', 'c', 'd'});
  std::list<char> st_original({'a', 'b', 'c', 'd'});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<char>::iterator it = st.end();
  std::list<char>::iterator it_original = st_original.end();
  --it;
  --it_original;
  st.insert(it, 'P');
  st_original.insert(it_original, 'P');
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  it = st.begin();
  it_original = st_original.begin();
  for (; it != st.end(); ++it) {
    ASSERT_EQ(*it, *it_original);
    ++it_original;
  }
}

TEST(s21_list_insert_check, test5) {
  s21::List<int> st;
  st.push_back(1);
  st.push_back(2);
  st.push_back(3);
  st.push_back(4);
  st.push_back(5);
  std::list<int> st_original({1, 2, 3, 4, 5});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<int>::iterator it = st.begin();
  std::list<int>::iterator it_original = st_original.begin();

  st.insert(it, 88);
  st_original.insert(it_original, 88);
  ASSERT_EQ(*it, *it_original);
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  it = st.end();
  it_original = st_original.end();
  --it;
  --it_original;
  for (; it != st.begin(); --it) {
    ASSERT_EQ(*it, *it_original);
    --it_original;
  }
  ASSERT_EQ(*it, *it_original);
}

TEST(s21_list_insert_check, test6) {
  s21::List<int> st;
  st.push_back(1);
  st.push_back(2);
  st.push_back(3);
  st.push_back(4);
  st.push_back(5);
  std::list<int> st_original({1, 2, 3, 4, 5});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<int>::iterator it = st.begin();
  std::list<int>::iterator it_original = st_original.begin();
  ++it;
  ++it;
  ++it_original;
  ++it_original;
  st.insert(it, 88);
  st_original.insert(it_original, 88);
  ASSERT_EQ(*it, *it_original);
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  it = st.end();
  it_original = st_original.end();
  --it;
  --it_original;
  for (; it != st.begin(); --it) {
    ASSERT_EQ(*it, *it_original);
    --it_original;
  }
  ASSERT_EQ(*it, *it_original);
}

TEST(s21_list_insert_check, test7) {
  s21::List<int> st;
  st.push_back(1);
  st.push_back(2);
  st.push_back(3);
  st.push_back(4);
  st.push_back(5);
  std::list<int> st_original({1, 2, 3, 4, 5});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<int>::iterator it = st.end();
  std::list<int>::iterator it_original = st_original.end();
  st.insert(it, 88);
  st_original.insert(it_original, 88);
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  it = st.end();
  it_original = st_original.end();
  --it;
  --it_original;
  for (; it != st.begin(); --it) {
    ASSERT_EQ(*it, *it_original);
    --it_original;
  }
  ASSERT_EQ(*it, *it_original);
}

TEST(s21_list_insert_check, test8) {
  s21::List<char> st({'a', 'b', 'c', 'd'});
  std::list<char> st_original({'a', 'b', 'c', 'd'});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<char>::iterator it = st.end();
  std::list<char>::iterator it_original = st_original.end();
  --it;
  --it_original;
  st.insert(it, 'P');
  st_original.insert(it_original, 'P');
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  it = st.end();
  it_original = st_original.end();
  --it;
  --it_original;
  for (; it != st.begin(); --it) {
    ASSERT_EQ(*it, *it_original);
    --it_original;
  }
  ASSERT_EQ(*it, *it_original);
}

TEST(s21_list_insert_check, test9) {
  s21::List<char> st({'a'});
  std::list<char> st_original({'a'});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<char>::iterator it = st.end();
  std::list<char>::iterator it_original = st_original.end();
  --it;
  --it_original;
  st.insert(it, 'P');
  st_original.insert(it_original, 'P');
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  it = st.begin();
  it_original = st_original.begin();
  for (; it != st.end(); ++it) {
    ASSERT_EQ(*it, *it_original);
    ++it_original;
  }
}

TEST(s21_list_insert_check, test10) {
  s21::List<char> st({'a'});
  std::list<char> st_original({'a'});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<char>::iterator it = st.end();
  std::list<char>::iterator it_original = st_original.end();
  st.insert(it, 'P');
  st_original.insert(it_original, 'P');
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  it = st.begin();
  it_original = st_original.begin();
  for (; it != st.end(); ++it) {
    ASSERT_EQ(*it, *it_original);
    ++it_original;
  }
}

TEST(s21_list_insert_check, test11) {
  s21::List<char> st({'a'});
  std::list<char> st_original({'a'});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<char>::iterator it = st.begin();
  std::list<char>::iterator it_original = st_original.begin();
  st.insert(it, 'P');
  st_original.insert(it_original, 'P');
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  it = st.begin();
  it_original = st_original.begin();
  for (; it != st.end(); ++it) {
    ASSERT_EQ(*it, *it_original);
    ++it_original;
  }
}

TEST(s21_list_insert_check, test12) {
  s21::List<int> st;
  std::list<int> st_original;
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<int>::iterator it = st.begin();
  std::list<int>::iterator it_original = st_original.begin();
  st.insert(it, 88);
  st_original.insert(it_original, 88);
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  it = st.end();
  it_original = st_original.end();
  --it;
  --it_original;
  for (; it != st.begin(); --it) {
    ASSERT_EQ(*it, *it_original);
    --it_original;
  }
  ASSERT_EQ(*it, *it_original);
}

TEST(s21_list_insert_check, test13) {
  s21::List<char> st;
  std::list<char> st_original;
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<char>::iterator it = st.end();
  std::list<char>::iterator it_original = st_original.end();
  --it;
  --it_original;
  st.insert(it, 'P');
  st_original.insert(it_original, 'P');
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  it = st.begin();
  it_original = st_original.begin();
  for (; it != st.end(); ++it) {
    ASSERT_EQ(*it, *it_original);
    ++it_original;
  }
}

TEST(s21_list_insert_check, test14) {
  s21::List<int> st;
  std::list<int> st_original;
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<int>::iterator it = st.end();
  std::list<int>::iterator it_original = st_original.end();
  st.insert(it, 88);
  st_original.insert(it_original, 88);
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  it = st.end();
  it_original = st_original.end();
  --it;
  --it_original;
  for (; it != st.begin(); --it) {
    ASSERT_EQ(*it, *it_original);
    --it_original;
  }
  ASSERT_EQ(*it, *it_original);
}

TEST(s21_list_insert_check, test15) {
  s21::List<char> st({'a'});
  std::list<char> st_original({'a'});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<char>::iterator it = st.begin();
  std::list<char>::iterator it_original = st_original.begin();
  st.insert(it, 'P');
  st_original.insert(it_original, 'P');
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  st.insert(it, 'w');
  st_original.insert(it_original, 'w');
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  it = st.begin();
  it_original = st_original.begin();
  for (; it != st.end(); ++it) {
    ASSERT_EQ(*it, *it_original);
    ++it_original;
  }
}

TEST(s21_list_insert_check, test16) {
  s21::List<int> st({1, 1, 2, 3, 3, 3, 4});
  std::list<int> st_original({1, 1, 2, 3, 3, 3, 4});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
  s21::List<int>::iterator it = st.begin();
  std::list<int>::iterator it_original = st_original.begin();
  ++it;
  ++it_original;
  st.insert(it, 44);
  st_original.insert(it_original, 44);
  st.insert(it, 44);
  st_original.insert(it_original, 44);
  st.insert(it, 44);
  st_original.insert(it_original, 44);
  ASSERT_EQ(*it, *it_original);
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  it = st.begin();
  it_original = st_original.begin();
  while (it != st.end()) {
    ASSERT_EQ(*it, *it_original);
    ++it;
    ++it_original;
  }
  it = st.end();
  it_original = st_original.end();
  while (it != st.begin()) {
    --it;
    --it_original;
    ASSERT_EQ(*it, *it_original);
  }
}

TEST(s21_list_swap_check, test1) {
  s21::List<int> st_1({1, 2, 3, 4, 5});
  s21::List<int> st_2({6, 7, 8, 9, 0, 10, 11});
  std::list<int> st_original_1({1, 2, 3, 4, 5});
  std::list<int> st_original_2({6, 7, 8, 9, 0, 10, 11});
  st_1.swap(st_2);
  st_original_1.swap(st_original_2);
  ASSERT_EQ(st_1.front(), st_original_1.front());
  ASSERT_EQ(st_1.back(), st_original_1.back());
  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.front(), st_original_2.front());
  ASSERT_EQ(st_2.back(), st_original_2.back());
  ASSERT_EQ(st_2.size(), st_original_2.size());

  s21::List<int>::iterator it = st_1.begin();
  std::list<int>::iterator it_original = st_original_1.begin();

  for (; it != st_1.end(); ++it) {
    ASSERT_EQ(*it, *it_original);
    ++it_original;
  }

  it = st_2.begin();
  it_original = st_original_2.begin();

  for (; it != st_2.end(); ++it) {
    ASSERT_EQ(*it, *it_original);
    ++it_original;
  }
}

TEST(s21_list_swap_check, test2) {
  s21::List<int> st_2({1, 2, 3, 4, 5});
  s21::List<int> st_1({6, 7, 8, 9, 0, 10, 11});
  std::list<int> st_original_2({1, 2, 3, 4, 5});
  std::list<int> st_original_1({6, 7, 8, 9, 0, 10, 11});
  st_1.swap(st_2);
  st_original_1.swap(st_original_2);
  ASSERT_EQ(st_1.front(), st_original_1.front());
  ASSERT_EQ(st_1.back(), st_original_1.back());
  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.front(), st_original_2.front());
  ASSERT_EQ(st_2.back(), st_original_2.back());
  ASSERT_EQ(st_2.size(), st_original_2.size());

  s21::List<int>::iterator it = st_1.end();
  std::list<int>::iterator it_original = st_original_1.end();
  --it;
  --it_original;
  for (; it != st_1.begin(); --it) {
    ASSERT_EQ(*it, *it_original);
    --it_original;
  }

  it = st_2.end();
  it_original = st_original_2.end();
  --it;
  --it_original;

  for (; it != st_2.begin(); --it) {
    ASSERT_EQ(*it, *it_original);
    --it_original;
  }
  ASSERT_EQ(*it, *it_original);
}
TEST(s21_list_swap_check, test3) {
  s21::List<int> st_2({1});
  s21::List<int> st_1({6, 7, 8, 9, 0, 10, 11});
  std::list<int> st_original_2({1});
  std::list<int> st_original_1({6, 7, 8, 9, 0, 10, 11});
  st_1.swap(st_2);
  st_original_1.swap(st_original_2);
  ASSERT_EQ(st_1.front(), st_original_1.front());
  ASSERT_EQ(st_1.back(), st_original_1.back());
  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.front(), st_original_2.front());
  ASSERT_EQ(st_2.back(), st_original_2.back());
  ASSERT_EQ(st_2.size(), st_original_2.size());

  s21::List<int>::iterator it = st_1.end();
  std::list<int>::iterator it_original = st_original_1.end();
  --it;
  --it_original;
  for (; it != st_1.begin(); --it) {
    ASSERT_EQ(*it, *it_original);
    --it_original;
  }

  it = st_2.end();
  it_original = st_original_2.end();
  --it;
  --it_original;

  for (; it != st_2.begin(); --it) {
    ASSERT_EQ(*it, *it_original);
    --it_original;
  }
  ASSERT_EQ(*it, *it_original);
}

TEST(s21_list_splice_check, test1) {
  s21::List<int> st_1({1, 2, 3, 4, 5});
  s21::List<int> st_2({6, 7, 8, 9, 0, 10, 11});
  std::list<int> st_original_1({1, 2, 3, 4, 5});
  std::list<int> st_original_2({6, 7, 8, 9, 0, 10, 11});
  ASSERT_EQ(st_1.front(), st_original_1.front());
  ASSERT_EQ(st_1.back(), st_original_1.back());
  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.front(), st_original_2.front());
  ASSERT_EQ(st_2.back(), st_original_2.back());
  ASSERT_EQ(st_2.size(), st_original_2.size());

  s21::List<int>::iterator it = st_1.end();
  std::list<int>::iterator it_original = st_original_1.end();

  st_1.splice(it, st_2);
  st_original_1.splice(it_original, st_original_2);
  ASSERT_EQ(st_1.front(), st_original_1.front());
  ASSERT_EQ(st_1.back(), st_original_1.back());
  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.front(), st_original_2.front());
  ASSERT_EQ(st_2.back(), st_original_2.back());
  ASSERT_EQ(st_2.size(), st_original_2.size());

  it = st_1.begin();
  it_original = st_original_1.begin();
  while (it_original != st_original_1.end()) {
    ASSERT_EQ(*it, *it_original);
    ++it;
    ++it_original;
  }

  it = st_2.begin();
  it_original = st_original_2.begin();

  for (; it != st_2.end(); ++it) {
    ASSERT_EQ(*it, *it_original);
    ++it_original;
  }
}

TEST(s21_list_splice_check, test2) {
  s21::List<int> st_1({1, 2, 3, 4, 5});
  s21::List<int> st_2({6, 7, 8, 9, 0, 10, 11});
  std::list<int> st_original_1({1, 2, 3, 4, 5});
  std::list<int> st_original_2({6, 7, 8, 9, 0, 10, 11});
  ASSERT_EQ(st_1.front(), st_original_1.front());
  ASSERT_EQ(st_1.back(), st_original_1.back());
  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.front(), st_original_2.front());
  ASSERT_EQ(st_2.back(), st_original_2.back());
  ASSERT_EQ(st_2.size(), st_original_2.size());

  s21::List<int>::iterator it = st_1.begin();
  std::list<int>::iterator it_original = st_original_1.begin();

  st_1.splice(it, st_2);
  st_original_1.splice(it_original, st_original_2);
  ASSERT_EQ(st_1.front(), st_original_1.front());
  ASSERT_EQ(st_1.back(), st_original_1.back());
  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.front(), st_original_2.front());
  ASSERT_EQ(st_2.back(), st_original_2.back());
  ASSERT_EQ(st_2.size(), st_original_2.size());

  it = st_1.end();
  it_original = st_original_1.end();
  --it;
  --it_original;
  while (it_original != st_original_1.begin()) {
    ASSERT_EQ(*it, *it_original);
    --it;
    --it_original;
  }
  ASSERT_EQ(*it, *it_original);

  it = st_2.end();
  it_original = st_original_2.end();

  for (; it != st_2.end(); ++it) {
    ASSERT_EQ(*it, *it_original);
    --it_original;
  }
  ASSERT_EQ(*it, *it_original);
}

TEST(s21_list_splice_check, test3) {
  s21::List<int> st_1;
  s21::List<int> st_2({6, 7, 8, 9, 0, 10, 11});
  std::list<int> st_original_1;
  std::list<int> st_original_2({6, 7, 8, 9, 0, 10, 11});
  ASSERT_EQ(st_1.front(), st_original_1.front());
  ASSERT_EQ(st_1.back(), st_original_1.back());
  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.front(), st_original_2.front());
  ASSERT_EQ(st_2.back(), st_original_2.back());
  ASSERT_EQ(st_2.size(), st_original_2.size());

  s21::List<int>::iterator it = st_1.end();
  std::list<int>::iterator it_original = st_original_1.end();

  st_1.splice(it, st_2);
  st_original_1.splice(it_original, st_original_2);
  ASSERT_EQ(st_1.front(), st_original_1.front());
  ASSERT_EQ(st_1.back(), st_original_1.back());
  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.front(), st_original_2.front());
  ASSERT_EQ(st_2.back(), st_original_2.back());
  ASSERT_EQ(st_2.size(), st_original_2.size());

  it = st_1.begin();
  it_original = st_original_1.begin();
  while (it_original != st_original_1.end()) {
    ASSERT_EQ(*it, *it_original);
    ++it;
    ++it_original;
  }

  it = st_2.begin();
  it_original = st_original_2.begin();

  for (; it != st_2.end(); ++it) {
    ASSERT_EQ(*it, *it_original);
    ++it_original;
  }
}

TEST(s21_list_splice_check, test4) {
  s21::List<int> st_1({1, 2, 3, 4, 5});
  s21::List<int> st_2;
  std::list<int> st_original_1({1, 2, 3, 4, 5});
  std::list<int> st_original_2;
  ASSERT_EQ(st_1.front(), st_original_1.front());
  ASSERT_EQ(st_1.back(), st_original_1.back());
  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.front(), st_original_2.front());
  ASSERT_EQ(st_2.back(), st_original_2.back());
  ASSERT_EQ(st_2.size(), st_original_2.size());

  s21::List<int>::iterator it = st_1.end();
  std::list<int>::iterator it_original = st_original_1.end();

  st_1.splice(it, st_2);
  st_original_1.splice(it_original, st_original_2);
  ASSERT_EQ(st_1.front(), st_original_1.front());
  ASSERT_EQ(st_1.back(), st_original_1.back());
  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.front(), st_original_2.front());
  ASSERT_EQ(st_2.back(), st_original_2.back());
  ASSERT_EQ(st_2.size(), st_original_2.size());

  it = st_1.begin();
  it_original = st_original_1.begin();
  while (it_original != st_original_1.end()) {
    ASSERT_EQ(*it, *it_original);
    ++it;
    ++it_original;
  }

  it = st_2.begin();
  it_original = st_original_2.begin();

  for (; it != st_2.end(); ++it) {
    ASSERT_EQ(*it, *it_original);
    ++it_original;
  }
}

TEST(s21_list_unique_check, test1) {
  s21::List<char> st({'b', 'b', 'b', 'd'});
  std::list<char> st_original({'b', 'b', 'b', 'd'});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  st.unique();
  st_original.unique();
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<char>::iterator it = st.begin();
  std::list<char>::iterator it_original = st_original.begin();
  while (it != st.end()) {
    ASSERT_EQ(*it, *it_original);
    ++it;
    ++it_original;
  }
}

TEST(s21_list_unique_check, test2) {
  s21::List<int> st({1, 1, 2, 3, 4});
  std::list<int> st_original({1, 1, 2, 3, 4});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  st.unique();
  st_original.unique();
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<int>::iterator it = st.begin();
  std::list<int>::iterator it_original = st_original.begin();
  while (it != st.end()) {
    ASSERT_EQ(*it, *it_original);
    ++it;
    ++it_original;
  }
  it = st.end();
  it_original = st_original.end();
  while (it != st.begin()) {
    --it;
    --it_original;
    ASSERT_EQ(*it, *it_original);
  }
}

TEST(s21_list_unique_check, test3) {
  s21::List<int> st({1, 1, 2, 3, 3, 3, 4});
  std::list<int> st_original({1, 1, 2, 3, 3, 3, 4});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  st.unique();
  st_original.unique();
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<int>::iterator it = st.begin();
  std::list<int>::iterator it_original = st_original.begin();
  while (it != st.end()) {
    ASSERT_EQ(*it, *it_original);
    ++it;
    ++it_original;
  }
  it = st.end();
  it_original = st_original.end();
  while (it != st.begin()) {
    --it;
    --it_original;
    ASSERT_EQ(*it, *it_original);
  }
}

TEST(s21_list_unique_check, test4) {
  s21::List<int> st({1, 2, 4, 4});
  std::list<int> st_original({1, 2, 4, 4});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  st.unique();
  st_original.unique();
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<int>::iterator it = st.begin();
  std::list<int>::iterator it_original = st_original.begin();
  while (it != st.end()) {
    ASSERT_EQ(*it, *it_original);
    ++it;
    ++it_original;
  }
  it = st.end();
  it_original = st_original.end();
  while (it != st.begin()) {
    --it;
    --it_original;
    ASSERT_EQ(*it, *it_original);
  }
}

TEST(s21_list_unique_check, test5) {
  s21::List<int> st({1, 2, 1, 2});
  std::list<int> st_original({1, 2, 1, 2});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  st.unique();
  st_original.unique();
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  s21::List<int>::iterator it = st.begin();
  std::list<int>::iterator it_original = st_original.begin();
  while (it != st.end()) {
    ASSERT_EQ(*it, *it_original);
    ++it;
    ++it_original;
  }
  it = st.end();
  it_original = st_original.end();
  while (it != st.begin()) {
    --it;
    --it_original;
    ASSERT_EQ(*it, *it_original);
  }
}

TEST(s21_list_sort_check, test1) {
  s21::List<int> st({7, 3, 4, 2, 6, 9, 11, 1});
  std::list<int> st_original({7, 3, 4, 2, 6, 9, 11, 1});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  st.sort();
  st_original.sort();
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
  s21::List<int>::iterator it = st.begin();
  std::list<int>::iterator it_original = st_original.begin();

  while (it != st.end()) {
    ASSERT_EQ(*it, *it_original);
    ++it;
    ++it_original;
  }
  it = st.end();
  it_original = st_original.end();
  while (it != st.begin()) {
    --it;
    --it_original;
    ASSERT_EQ(*it, *it_original);
  }
}

TEST(s21_list_sort_check, test) {
  s21::List<int> st({7});
  std::list<int> st_original({7});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  st.sort();
  st_original.sort();
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
  s21::List<int>::iterator it = st.begin();
  std::list<int>::iterator it_original = st_original.begin();

  while (it != st.end()) {
    ASSERT_EQ(*it, *it_original);
    ++it;
    ++it_original;
  }
  it = st.end();
  it_original = st_original.end();
  while (it != st.begin()) {
    --it;
    --it_original;
    ASSERT_EQ(*it, *it_original);
  }
}

TEST(s21_list_sort_check, test3) {
  s21::List<double> st({-25.7, -334.2, 0., 329.715, 7100000.25, -955538.336,
                        -0.55555555587, 799});
  std::list<double> st_original({-25.7, -334.2, 0., 329.715, 7100000.25,
                                 -955538.336, -0.55555555587, 799});
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());

  st.sort();
  st_original.sort();
  ASSERT_EQ(st.front(), st_original.front());
  ASSERT_EQ(st.back(), st_original.back());
  ASSERT_EQ(st.size(), st_original.size());
  s21::List<double>::iterator it = st.begin();
  std::list<double>::iterator it_original = st_original.begin();

  while (it != st.end()) {
    ASSERT_DOUBLE_EQ(*it, *it_original);
    ++it;
    ++it_original;
  }
  it = st.end();
  it_original = st_original.end();
  while (it != st.begin()) {
    --it;
    --it_original;
    ASSERT_DOUBLE_EQ(*it, *it_original);
  }
}

TEST(s21_list_merge_check, test1) {
  s21::List<int> st_1({1, 3, 4, 6, 8, 11, 14, 22});
  s21::List<int> st_2({2, 5, 7, 9, 16, 17, 24, 25});
  std::list<int> st_original_1({1, 3, 4, 6, 8, 11, 14, 22});
  std::list<int> st_original_2({2, 5, 7, 9, 16, 17, 24, 25});
  ASSERT_EQ(st_1.front(), st_original_1.front());
  ASSERT_EQ(st_1.back(), st_original_1.back());
  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.front(), st_original_2.front());
  ASSERT_EQ(st_2.back(), st_original_2.back());
  ASSERT_EQ(st_2.size(), st_original_2.size());

  st_1.merge(st_2);
  st_original_1.merge(st_original_2);
  ASSERT_EQ(st_1.front(), st_original_1.front());
  ASSERT_EQ(st_1.back(), st_original_1.back());
  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.front(), st_original_2.front());
  ASSERT_EQ(st_2.back(), st_original_2.back());
  ASSERT_EQ(st_2.size(), st_original_2.size());

  s21::List<int>::iterator it = st_1.begin();
  std::list<int>::iterator it_original = st_original_1.begin();
  while (it != st_1.end()) {
    ASSERT_EQ(*it, *it_original);
    ++it;
    ++it_original;
  }
  it = st_1.end();
  it_original = st_original_1.end();
  while (it != st_1.begin()) {
    --it;
    --it_original;
    ASSERT_EQ(*it, *it_original);
  }

  it = st_2.end();
  it_original = st_original_2.end();
  while (it != st_2.end()) {
    ASSERT_EQ(*it, *it_original);
    ++it;
    ++it_original;
  }
  it = st_2.end();
  it_original = st_original_2.end();
  while (it != st_2.begin()) {
    --it;
    --it_original;
    ASSERT_EQ(*it, *it_original);
  }
}

TEST(s21_list_merge_check, test2) {
  s21::List<int> st_1({1});
  s21::List<int> st_2({2, 5, 7, 9, 16, 17, 24, 25});
  std::list<int> st_original_1({1});
  std::list<int> st_original_2({2, 5, 7, 9, 16, 17, 24, 25});
  ASSERT_EQ(st_1.front(), st_original_1.front());
  ASSERT_EQ(st_1.back(), st_original_1.back());
  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.front(), st_original_2.front());
  ASSERT_EQ(st_2.back(), st_original_2.back());
  ASSERT_EQ(st_2.size(), st_original_2.size());

  st_1.merge(st_2);
  st_original_1.merge(st_original_2);
  ASSERT_EQ(st_1.front(), st_original_1.front());
  ASSERT_EQ(st_1.back(), st_original_1.back());
  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.front(), st_original_2.front());
  ASSERT_EQ(st_2.back(), st_original_2.back());
  ASSERT_EQ(st_2.size(), st_original_2.size());

  s21::List<int>::iterator it = st_1.begin();
  std::list<int>::iterator it_original = st_original_1.begin();
  while (it != st_1.end()) {
    ASSERT_EQ(*it, *it_original);
    ++it;
    ++it_original;
  }
  it = st_1.end();
  it_original = st_original_1.end();
  while (it != st_1.begin()) {
    --it;
    --it_original;
    ASSERT_EQ(*it, *it_original);
  }

  it = st_2.end();
  it_original = st_original_2.end();
  while (it != st_2.end()) {
    ASSERT_EQ(*it, *it_original);
    ++it;
    ++it_original;
  }
  it = st_2.end();
  it_original = st_original_2.end();
  while (it != st_2.begin()) {
    --it;
    --it_original;
    ASSERT_EQ(*it, *it_original);
  }
}

TEST(s21_list_merge_check, test3) {
  s21::List<int> st_1({151});
  s21::List<int> st_2({2, 5, 7, 9, 16, 17, 24, 25});
  std::list<int> st_original_1({151});
  std::list<int> st_original_2({2, 5, 7, 9, 16, 17, 24, 25});
  ASSERT_EQ(st_1.front(), st_original_1.front());
  ASSERT_EQ(st_1.back(), st_original_1.back());
  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.front(), st_original_2.front());
  ASSERT_EQ(st_2.back(), st_original_2.back());
  ASSERT_EQ(st_2.size(), st_original_2.size());

  st_1.merge(st_2);
  st_original_1.merge(st_original_2);
  ASSERT_EQ(st_1.front(), st_original_1.front());
  ASSERT_EQ(st_1.back(), st_original_1.back());
  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.front(), st_original_2.front());
  ASSERT_EQ(st_2.back(), st_original_2.back());
  ASSERT_EQ(st_2.size(), st_original_2.size());

  s21::List<int>::iterator it = st_1.begin();
  std::list<int>::iterator it_original = st_original_1.begin();
  while (it != st_1.end()) {
    ASSERT_EQ(*it, *it_original);
    ++it;
    ++it_original;
  }
  it = st_1.end();
  it_original = st_original_1.end();
  while (it != st_1.begin()) {
    --it;
    --it_original;
    ASSERT_EQ(*it, *it_original);
  }

  it = st_2.end();
  it_original = st_original_2.end();
  while (it != st_2.end()) {
    ASSERT_EQ(*it, *it_original);
    ++it;
    ++it_original;
  }
  it = st_2.end();
  it_original = st_original_2.end();
  while (it != st_2.begin()) {
    --it;
    --it_original;
    ASSERT_EQ(*it, *it_original);
  }
}

TEST(s21_list_merge_check, test) {
  s21::List<int> st_1;
  s21::List<int> st_2({2, 5, 7, 9, 16, 17, 24, 25});
  std::list<int> st_original_1;
  std::list<int> st_original_2({2, 5, 7, 9, 16, 17, 24, 25});
  ASSERT_EQ(st_1.front(), st_original_1.front());
  ASSERT_EQ(st_1.back(), st_original_1.back());
  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.front(), st_original_2.front());
  ASSERT_EQ(st_2.back(), st_original_2.back());
  ASSERT_EQ(st_2.size(), st_original_2.size());

  st_1.merge(st_2);
  st_original_1.merge(st_original_2);
  ASSERT_EQ(st_1.front(), st_original_1.front());
  ASSERT_EQ(st_1.back(), st_original_1.back());
  ASSERT_EQ(st_1.size(), st_original_1.size());
  ASSERT_EQ(st_2.front(), st_original_2.front());
  ASSERT_EQ(st_2.back(), st_original_2.back());
  ASSERT_EQ(st_2.size(), st_original_2.size());

  s21::List<int>::iterator it = st_1.begin();
  std::list<int>::iterator it_original = st_original_1.begin();
  while (it != st_1.end()) {
    ASSERT_EQ(*it, *it_original);
    ++it;
    ++it_original;
  }
  it = st_1.end();
  it_original = st_original_1.end();
  while (it != st_1.begin()) {
    --it;
    --it_original;
    ASSERT_EQ(*it, *it_original);
  }

  it = st_2.end();
  it_original = st_original_2.end();
  while (it != st_2.end()) {
    ASSERT_EQ(*it, *it_original);
    ++it;
    ++it_original;
  }
  it = st_2.end();
  it_original = st_original_2.end();
  while (it != st_2.begin()) {
    --it;
    --it_original;
    ASSERT_EQ(*it, *it_original);
  }
}

TEST(s21_list_max_size_check, test1) {
  s21::List<double> st({11.11, 22.22, 33.33, 44.44, 88.88});
  std::list<double> st_original({11.11, 22.22, 33.33, 44.44, 88.88});
  ASSERT_EQ(st.max_size(), st_original.max_size());
}

TEST(s21_list_max_size_check, test2) {
  s21::List<long long int> st;
  std::list<long long int> st_original;
  ASSERT_EQ(st.max_size(), st_original.max_size());
}
