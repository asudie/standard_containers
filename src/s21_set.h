#ifndef S21_SET_H_
#define S21_SET_H_

#include <cstddef>
#include <initializer_list>
#include <iostream>

#include "s21_tree.h"

template <typename Key>
class Set : public BinaryTree<Key, const Key*> {
 public:
  using Tree = BinaryTree<Key, const Key*>;
  using NodeTree = typename Tree::NodeTree;
  using key_type = Key;
  using mapped_type = const Key*;
  using value_type = Key;
  using reference = const value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;

  class IteratorSet : protected Tree::iterator {
   public:
    IteratorSet() : Tree::iterator() {}
    IteratorSet(typename Tree::iterator it) : Tree::iterator(it) {}
    IteratorSet(NodeTree* ptr_ = nullptr, NodeTree* ptr_empty_ = nullptr)
        : Tree::iterator(ptr_, ptr_empty_) {}

    NodeTree* get_ptr() const { return Tree::iterator::get_ptr(); }
    void set_ptr(NodeTree* update_ptr) { ptr_ = update_ptr; }

    reference operator*() const noexcept {
      return Tree::iterator::operator*().first;
    }

    value_type* operator->() {
      auto temp = Tree::iterator::operator->();
      return temp.first;
    }

    IteratorSet& operator++() noexcept {
      Tree::iterator::operator++();
      return *this;
    }

    IteratorSet operator++(int) noexcept {
      return Tree::iterator::operator++(0);
    }

    IteratorSet& operator--() noexcept {
      Tree::iterator::operator--();
      return *this;
    }

    IteratorSet operator--(int) noexcept {
      return Tree::iterator::operator--(0);
    }

    bool operator==(const IteratorSet& it) const noexcept {
      return Tree::iterator::operator==(it);
    }

    bool operator!=(const IteratorSet& it) const noexcept {
      return Tree::iterator::operator!=(it);
    }

   private:
    NodeTree* ptr_;
    NodeTree* ptr_empty_;
  };

  class ConstIteratorSet : protected Tree::ConstIterator {
   public:
    ConstIteratorSet() : Tree::ConstIterator() {}
    ConstIteratorSet(typename Tree::ConstIterator it)
        : Tree::ConstIterator(it) {}
    ConstIteratorSet(NodeTree* ptr_ = nullptr, NodeTree* ptr_empty_ = nullptr)
        : Tree::ConstIterator(ptr_, ptr_empty_) {}
    NodeTree* get_ptr() { return Tree::ConstIterator::get_const_ptr(); }
    void set_ptr(NodeTree* update_ptr) { ptr_ = update_ptr; }

    const_reference operator*() const noexcept {
      return Tree::ConstIterator::operator*().first;
    }
    value_type* operator->() {
      auto temp = Tree::ConstIterator::operator->();
      return temp.first;
    }
    ConstIteratorSet& operator++() noexcept {
      Tree::ConstIterator::operator++();
      return *this;
    }
    ConstIteratorSet& operator--() noexcept {
      Tree::ConstIterator::operator--();
      return *this;
    }
    bool operator==(const ConstIteratorSet& it) const noexcept {
      return Tree::ConstIterator::operator==(it);
    }
    bool operator!=(const ConstIteratorSet& it) const noexcept {
      return Tree::ConstIterator::operator!=(it);
    }

   private:
    NodeTree* ptr_;
    NodeTree* ptr_empty_;
  };

  using Iterator = IteratorSet;

  Set() : Tree() {}

  Set(std::initializer_list<value_type> const& items) : Set() {
    for (const auto& element : items) insert(element);
  }

  Set(const Set& s) : Tree(s) {}

  Set(Set&& s) : Tree(std::move(s)) {}

  Set& operator=(const Set& s) {
    Tree::operator=(s);
    return *this;
  }

  Set& operator=(Set&& s) noexcept {
    Tree::operator=(std::move(s));
    return *this;
  }

  int size() { return Tree::size(); }

  IteratorSet find(const Key& key) {
    IteratorSet it = this->begin();
    while (it != this->end()) {
      if (*it == key) {
        return it;
      }
      ++it;
    }
    return it;
  }

  ConstIteratorSet find(const Key& key) const {
    return ConstIteratorSet(this->FindNode(this->get_root(), key),
                            this->get_empty_node());
  }

  std::pair<IteratorSet, bool> insert(const value_type& value) {
    auto node = this->FindNode(this->get_root(), value);
    if (node) return {IteratorSet(node, this->get_empty_node()), false};
    return Tree::insert({value, &value});
  }

 private:
  using Tree::FindNode;
  using Tree::FindNodeToInsert;
  using Tree::get_empty_node;
  using Tree::insert_or_assign;
  using Tree::operator[];
  using Tree::at;
};

#endif  // S21_SET_H_
