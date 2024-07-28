#include <gtest/gtest.h>

#include "s21_containersplus.h"

TEST(multiset_tests_constr, test1) {
  s21::Multiset<int> my_ms;
  std::multiset<int> orig_ms;
  ASSERT_EQ(my_ms.size(), orig_ms.size());
}
TEST(multiset_tests_constr, test2) {
  s21::Multiset<int> my_ms;
  s21::Multiset<int> copy_my_ms(my_ms);
  std::multiset<int> orig_ms;
  std::multiset<int> copy_orig_ms(orig_ms);
  ASSERT_EQ(copy_my_ms.size(), copy_orig_ms.size());
}
TEST(multiset_tests_move, test1) {
  s21::Multiset<int> my_ms;
  s21::Multiset<int> copy_my_ms(std::move(my_ms));
  std::multiset<int> orig_ms;
  std::multiset<int> copy_orig_ms(std::move(orig_ms));
  ASSERT_EQ(copy_my_ms.size(), copy_orig_ms.size());
}
TEST(multiset_tests_insert, test1) {
  s21::Multiset<int> my_ms;
  std::multiset<int> orig_ms;
  my_ms.insert('b');
  my_ms.insert('a');
  my_ms.insert('c');
  my_ms.insert('b');
  my_ms.insert('a');
  my_ms.insert('c');
  orig_ms.insert('b');
  orig_ms.insert('a');
  orig_ms.insert('c');
  orig_ms.insert('b');
  orig_ms.insert('a');
  orig_ms.insert('c');
  ASSERT_EQ(my_ms.size(), orig_ms.size());
}
TEST(multiset_tests_move, test2) {
  s21::Multiset<int> const my_ms;
  s21::Multiset<int> copy_my_ms(std::move(my_ms));
  std::multiset<int> const orig_ms;
  std::multiset<int> copy_orig_ms(std::move(orig_ms));
  ASSERT_EQ(copy_my_ms.size(), copy_orig_ms.size());
}
TEST(multiset_tests_copy, test1) {
  s21::Multiset<int> my_ms{1, 2, 3, 4, 5, 6, 7};
  s21::Multiset<int> new_my_ms = my_ms;
  s21::Multiset<int> orig_ms{1, 2, 3, 4, 5, 6, 7};
  s21::Multiset<int> new_orig_ms = orig_ms;
  ASSERT_EQ(new_my_ms.size(), new_orig_ms.size());
}
TEST(multiset_tests_begin, test1) {
  s21::Multiset<int> my_ms;
  std::multiset<int> orig_ms;
  my_ms.insert('a');
  my_ms.insert('b');
  my_ms.insert('c');
  my_ms.insert('b');
  my_ms.insert('a');
  my_ms.insert('c');
  orig_ms.insert('a');
  orig_ms.insert('b');
  orig_ms.insert('c');
  orig_ms.insert('b');
  orig_ms.insert('a');
  orig_ms.insert('c');
  ASSERT_EQ(*my_ms.begin(), *orig_ms.begin());
}
TEST(multiset_tests_max_size, test1) {
  s21::Multiset<int> my_ms{1, 2, 3, 4, 5, 6};
  ASSERT_EQ(my_ms.max_size(),
            SIZE_MAX / (sizeof(s21::Multiset<int>::Tree::NodeTree)) / 2);
}
TEST(multiset_tests_lower_bound, test1) {
  s21::Multiset<int> my_ms{1, 2, 3, 4, 5, 6};
  std::multiset<int> orig_ms{1, 2, 3, 4, 5, 6};
  auto it_m = my_ms.lower_bound(3);
  std::multiset<int>::iterator it_or;
  it_or = orig_ms.lower_bound(3);
  ASSERT_TRUE(*it_m == *it_or);
}

TEST(multiset_tests_lower_bound, test2) {
  s21::Multiset<char> t({'a', 'b', 'c', 'd', 'e', 'f', 'g'});
  std::multiset<char> t_original({'a', 'b', 'c', 'd', 'e', 'f', 'g'});
  auto it_m = t.lower_bound('e');
  std::multiset<char>::iterator it_or = t_original.lower_bound('e');
  ASSERT_TRUE(*it_m == *it_or);
}

TEST(multiset_tests_upper_bound, test1) {
  s21::Multiset<char> t({'a', 'b', 'c', 'd', 'e', 'f', 'g'});
  std::multiset<char> t_original({'a', 'b', 'c', 'd', 'e', 'f', 'g'});
  auto it_m = t.upper_bound('e');
  std::multiset<char>::iterator it_or = t_original.upper_bound('e');
  ASSERT_TRUE(*it_m == *it_or);
}

TEST(multiset_tests_equal_range, test1) {
  s21::Multiset<char> t({'a', 'b', 'c', 'd', 'e', 'f', 'g'});
  std::multiset<char> t_original({'a', 'b', 'c', 'd', 'e', 'f', 'g'});
  auto it_m = t.equal_range('e');
  auto it_or = t_original.equal_range('e');
  ASSERT_TRUE(*it_m.first == *it_or.first);
  ASSERT_TRUE(*it_m.second == *it_or.second);
}
TEST(multiset_tests_upper_bound, test2) {
  s21::Multiset<char> t({1, 2, 3, 4, 5, 6, 7, 8, 9});
  std::multiset<char> t_original({1, 2, 3, 4, 5, 6, 7, 8, 9});
  auto it_m = t.upper_bound(5);
  std::multiset<char>::iterator it_or = t_original.upper_bound(5);
  ASSERT_TRUE(*it_m == *it_or);
  --it_m;
  --it_or;
}
TEST(multiset_tests_count, test1) {
  s21::Multiset<int> t({5, 6, 0, 4, 7, 3, 8, 5, 2, 9, 1, 0});
  std::multiset<int> t_original({5, 6, 0, 4, 7, 3, 8, 5, 2, 9, 1, 0});
  auto temp_my = t.count(0);
  auto temp_or = t_original.count(0);
  ASSERT_EQ(temp_my, temp_or);
}
TEST(multiset_tests_find, test1) {
  s21::Multiset<int> t({5, 6, 0, 4, 7, 3, 8, 5, 2, 9, 1, 0});
  std::multiset<int> t_original({5, 6, 0, 4, 7, 3, 8, 5, 2, 9, 1, 0});
  auto temp_my = t.find(6);
  auto temp_or = t_original.find(6);
  ASSERT_TRUE(*temp_my == *temp_or);
}
TEST(multiset_tests_find, test2) {
  s21::Multiset<char> t({'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'});
  std::multiset<char> t_original({'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'});
  auto temp_my = t.find('d');
  auto temp_or = t_original.find('d');
  ASSERT_TRUE(*temp_my == *temp_or);
}

TEST(multiset_tests_find, test3) {
  s21::Multiset<int> t({5, 6, 0, 4, 7, 3, 8, 5, 2, 9, 1, 0});
  std::multiset<int> t_original({5, 6, 0, 4, 7, 3, 8, 5, 2, 9, 1, 0});
  auto temp_my = --t.find(10);
  auto temp_or = --t_original.find(10);
  ASSERT_EQ(*temp_my, *temp_or);
}

TEST(multiset_tests_end, test1) {
  s21::Multiset<int> t({5, 6, 0, 4, 7, 3, 8, 5, 2, 9, 1, 5});
  std::multiset<int> t_original({5, 6, 0, 4, 7, 3, 8, 5, 2, 9, 1, 5});
  auto end_my = --t.end();
  auto end_or = --t_original.end();
  ASSERT_EQ(*end_my, *end_or);
}

TEST(multiset_tests_max_size, test2) {
  s21::Multiset<int> t({5, 6, 0, 4, 7, 3, 8, 5, 2, 9, 1, 0});
  ASSERT_EQ(t.max_size(),
            SIZE_MAX / (sizeof(s21::Multiset<int>::Tree::NodeTree)) / 2);
}

TEST(multiset_tests_swap, test1) {
  s21::Multiset<int> t({5, 6, 0, 4, 7, 3, 8, 5, 2, 9, 1, 0});
  s21::Multiset<int> t1({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
  std::multiset<int> t_original({5, 6, 0, 4, 7, 3, 8, 5, 2, 9, 1, 0});
  std::multiset<int> t2_original({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
  t.swap(t1);
  t_original.swap(t2_original);
  ASSERT_EQ(*t.find(10), *t_original.find(10));
  ASSERT_EQ(*t1.find(0), *t2_original.find(0));
}
TEST(multiset_tests_find, test4) {
  const s21::Multiset<int> t({5, 6, 0, 4, 7, 3, 8, 5, 2, 9, 1, 0});
  const std::multiset<int> t_original({5, 6, 0, 4, 7, 3, 8, 5, 2, 9, 1, 0});
  ASSERT_EQ(*t.find(3), *t_original.find(3));
}
TEST(multiset_tests_merge, test1) {
  s21::Multiset<double> t(
      {5.5, 6.6, 0.0, 4.4, 7.7, 3.3, 8.8, 5.5, 2.2, 9.9, 1.1, 0.0});
  s21::Multiset<double> t1({10.10, 11.11, 12.12});
  std::multiset<double> t_original(
      {5.5, 6.6, 0.0, 4.4, 7.7, 3.3, 8.8, 5.5, 2.2, 9.9, 1.1, 0.0});
  std::multiset<double> t2_original({10.10, 11.11, 12.12});
  t.merge(t1);
  t_original.merge(t2_original);
  ASSERT_EQ(t.size(), t_original.size());
}
TEST(multiset_tests_erase, test1) {
  s21::Multiset<int> t({10, 11, 12});
  std::multiset<int> t_original({10, 11, 12});
  auto it_m = t.find(10);
  auto it_or = t_original.find(10);
  t.erase(*it_m);
  t_original.erase(it_or);
  it_m = t.begin();
  it_or = t_original.begin();
  while (it_or != t_original.end()) {
    ++it_m;
    ++it_or;
  }
  ASSERT_EQ(t.size(), t_original.size());
}
TEST(multiset_tests_contains, test1) {
  s21::Multiset<int> t({5, 6, 0, 4, 7, 3, 8, 5, 2, 9, 1, 0});
  ASSERT_EQ(t.contains(0), true);
}
TEST(multiset_tests_contains, test2) {
  s21::Multiset<int> t({5, 6, 0, 4, 7, 3, 8, 5, 2, 9, 1, 0});
  ASSERT_EQ(t.contains(2), true);
}
TEST(multiset_tests_contains, test3) {
  s21::Multiset<int> t({5, 6, 0, 7, 3, 8, 5, 2, 9, 1, 0});
  ASSERT_EQ(t.contains(4), false);
}
TEST(multiset_tests_iter, test1) {
  const s21::Multiset<int> t({10, 11, 12});
  const std::multiset<int> t_original({10, 11, 12});
  auto it_m = t.find(10);
  auto it_or = t_original.find(10);
  ASSERT_EQ(*it_m, *it_or);
}
TEST(multiset_tests_iter, test2) {
  const s21::Multiset<int> t({10, 11, 12});
  const std::multiset<int> t_original({10, 11, 12});
  auto it_m = t.find(12);
  auto it_or = t_original.find(12);
  it_m = t.end();
  it_or = t_original.end();
  while (it_or != t_original.begin()) {
    --it_m;
    --it_or;
  }
  ASSERT_EQ(t.size(), t_original.size());
}
TEST(multiset_tests_iter, test3) {
  const s21::Multiset<int> t({10, 11, 12});
  const s21::Multiset<int> t_original({10, 11, 12});
  auto it_m = t.find(11);
  auto it_or = t_original.find(11);
  if (it_m == it_or) {
    ASSERT_EQ(t.size(), t_original.size());
  }
  ASSERT_EQ(t.size(), t_original.size());
}
TEST(multiset_tests_iter, test4) {
  s21::Multiset<int> t({10, 11, 12});
  s21::Multiset<int> t_original({10, 11, 12});
  auto it_m = t.find(11);
  auto it_or = t_original.find(11);
  if (it_m == it_or) {
    ASSERT_EQ(t.size(), t_original.size());
  }
  ASSERT_EQ(t.size(), t_original.size());
}
TEST(multiset_tests_iter, test5) {
  const s21::Multiset<int> t({10, 11, 12});
  const std::multiset<int> t_original({10, 11, 12});
  EXPECT_EQ(*t.begin(), *t_original.begin());
}
