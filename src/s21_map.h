#ifndef S21_MAP_H_
#define S21_MAP_H_
#include <cstddef>
#include <exception>
#include <initializer_list>
#include <iostream>

#include "s21_tree.h"

template <class Key, class T>
class Map : public BinaryTree<Key, T> {
 public:
  using Tree = BinaryTree<Key, T>;
  using NodeTree = typename Tree::NodeTree;
  using Iterator = typename Tree::Iterator;
  using ConstIterator = typename Tree::ConstIterator;
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;

  Map() : Tree::BinaryTree(){};
  Map(std::initializer_list<value_type> const& items) : Tree::BinaryTree() {
    for (auto& it : items) {
      if (!(this->contains(it.first))) Tree::insert(it);
    }
  }
  Map(const Map& map) : Tree::BinaryTree(map){};
  Map(Map&& map) : Tree::BinaryTree(std::move(map)){};
  ~Map() override = default;
  Map& operator=(const Map& map) = default;
  Map& operator=(Map&& map) = default;

  std::pair<Iterator, bool> insert(const value_type& value) {
    auto node = this->FindNode(this->get_root(), value.first);
    if (node) return {Iterator(node, this->get_empty_node()), false};
    return Tree::insert(value);
  }
  std::pair<Iterator, bool> insert(const Key& key, const T& obj) {
    auto node = this->FindNode(this->get_root(), key);
    if (node) return {Iterator(node, this->get_empty_node()), false};
    return Tree::insert(key, obj);
  }
  std::pair<Iterator, bool> insert_or_assign(const Key& key, const T& obj) {
    auto node = this->FindNode(this->get_root(), key);
    if (!(this->contains(key))) return Tree::insert_or_assign(key, obj);
    return {Iterator(node, this->get_empty_node()), false};
  }
};

#endif  // S21_MAP_H_
