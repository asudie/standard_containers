#ifndef S21_MULTISET_H_
#define S21_MULTISET_H_
#include <initializer_list>
#include <iostream>

#include "s21_set.h"
#include "s21_tree.h"

template <class Key>
class Multiset : public BinaryTree<Key, const Key*> {
 public:
  using Tree = BinaryTree<Key, const Key*>;
  using NodeTree = typename Tree::NodeTree;
  using key_type = Key;
  using value_type = Key;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;
  using ConstIterator = typename Set<Key>::ConstIteratorSet;
  using Iterator = typename Set<Key>::IteratorSet;

  Iterator begin() noexcept { return Tree::begin(); }
  ConstIterator begin() const noexcept { return Tree::begin(); }
  Iterator end() noexcept { return Tree::end(); }
  ConstIterator end() const noexcept { return Tree::end(); }

  Multiset() : Tree::BinaryTree() {}

  Multiset(std::initializer_list<value_type> const& items)
      : Tree::BinaryTree() {
    for (auto& it : items) {
      this->insert(it);
    }
  }
  Multiset(const Multiset& ms) : Tree::BinaryTree(ms) {}
  Multiset(Multiset&& ms) noexcept : Tree::BinaryTree(std::move(ms)) {}

  ~Multiset() {}

  Iterator lower_bound(const Key& key) {
    Iterator it = find(key);
    return it;
  }

  Iterator upper_bound(const Key& key) {
    Iterator it = find(key);
    while ((*it <= key) && (it != this->end())) {
      ++it;
    }
    return it;
  }

  std::pair<Iterator, Iterator> equal_range(const Key& key) {
    auto lower = lower_bound(key);
    auto upper = upper_bound(key);
    return std::pair<Iterator, Iterator>(lower, upper);
  }

  size_type count(const Key& key) {
    Iterator it = this->begin();
    size_type count_elem = 0;
    while (it != this->end()) {
      if (*it == key) {
        ++count_elem;
      }
      ++it;
    }
    return count_elem;
  }
  Iterator find(const Key& key) {
    return Iterator(this->FindNode(this->get_root(), key),
                    this->get_empty_node());
  }
  ConstIterator find(const Key& key) const {
    return ConstIterator(this->FindNode(this->get_root(), key),
                         this->get_empty_node());
  }

  Iterator insert(const value_type& value) {
    NodeTree* node = Tree::FindNode(this->get_root(), value);
    Iterator it = this->begin();
    this->set_root(Tree::InsertNode(this->get_root(), {value, &value}));
    this->get_empty_node()->parent = Tree::FindMaxNode(this->get_root());
    node = Tree::FindNode(this->get_root(), value);
    it.set_ptr(node);
    return it;
  }

 private:
  using Tree::at;
  using Tree::operator[];
  using Tree::insert;
  using Tree::insert_or_assign;
};

#endif  // S21_MULTISET_H_