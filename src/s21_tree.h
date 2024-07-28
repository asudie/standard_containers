#ifndef S21_TREE_H_
#define S21_TREE_H_
#include <cstddef>
#include <exception>
#include <initializer_list>
#include <iostream>

template <typename Key, typename T>
class BinaryTree {
 public:
  class Iterator;
  class ConstIterator;
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;
  using iterator = Iterator;
  using const_iterator = ConstIterator;

  struct NodeTree {
    value_type data;
    NodeTree* parent;
    NodeTree* left;
    NodeTree* right;
    int height;
  };
  BinaryTree();
  BinaryTree(std::initializer_list<value_type> const& items);
  BinaryTree(const BinaryTree& tree);
  BinaryTree(BinaryTree&& tree);
  virtual ~BinaryTree();
  BinaryTree& operator=(const BinaryTree& tree);
  BinaryTree& operator=(BinaryTree&& tree);
  const mapped_type& at(const key_type& key) const;
  mapped_type& at(const key_type& key);
  mapped_type& operator[](const key_type& key);

  Iterator begin() noexcept;
  ConstIterator begin() const noexcept;
  Iterator end() noexcept;
  ConstIterator end() const noexcept;

  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;
  void clear();
  std::pair<Iterator, bool> insert(const value_type& value);
  std::pair<Iterator, bool> insert(const key_type& key, const mapped_type& obj);
  std::pair<Iterator, bool> insert_or_assign(const key_type& key,
                                             const mapped_type& obj);
  NodeTree* InsertNode(NodeTree* node, const value_type& value);
  bool contains(const key_type& key) const;

  void erase(const key_type& key);
  void erase(Iterator pos);

  void swap(BinaryTree& tree);
  void merge(BinaryTree& tree);
  NodeTree* FindNode(NodeTree* node, const key_type& key) const;
  NodeTree* FindNodeToInsert(NodeTree* node, const key_type& key);
  NodeTree* FindMaxNode(NodeTree* node) const;

  NodeTree* get_root() const { return root_; }
  NodeTree* get_empty_node() const { return empty_node_; }
  void set_root(NodeTree* update_root) { root_ = update_root; }

 private:
  int GetHeight(NodeTree* node) const;
  int BalanceFactor(NodeTree* node) const;
  void UpdateHeight(NodeTree* node);
  NodeTree* RotateRight(NodeTree* node);
  NodeTree* RotateLeft(NodeTree* node);
  NodeTree* Balance(NodeTree* node);
  NodeTree* BalanceUntilRoot(NodeTree* node);
  void DeleteNode(NodeTree* node);
  NodeTree* FindMinNode(NodeTree* node) const;
  NodeTree* DeleteMinNode(NodeTree* node);
  NodeTree* RemoveNode(NodeTree* node, const key_type& key);

  NodeTree* SearchKeyOrNode(NodeTree* node, const key_type& key);
  NodeTree* CopyNode(NodeTree* node);

  NodeTree* root_;
  NodeTree* empty_node_;
  size_type size_;
};

#include "s21_tree.inl"

#endif  // S21_TREE_H_
