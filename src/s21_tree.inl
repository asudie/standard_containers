using namespace s21;

template <typename key_type, typename mapped_type>
class BinaryTree<key_type, mapped_type>::Iterator {
 public:
  friend class BinaryTree;

  Iterator(NodeTree* ptr_ = nullptr, NodeTree* ptr_empty_ = nullptr)
      : ptr_(ptr_), ptr_empty_(ptr_empty_) {}

  NodeTree* get_ptr() const { return ptr_; }

  reference operator*() const noexcept {
    if (ptr_)
      return ptr_->data;
    else
      return ptr_empty_->data;
  }

  value_type* operator->() {
    if (ptr_)
      return &(ptr_->data);
    else
      return &(ptr_empty_->data);
  }

  Iterator& operator++() noexcept {
    if (!ptr_)
      ptr_ = ptr_empty_;
    else if (ptr_->right) {
      ptr_ = ptr_->right;
      while (ptr_->left) ptr_ = ptr_->left;
    } else {
      NodeTree* parent_new = ptr_->parent;
      while (parent_new && ptr_ == parent_new->right) {
        ptr_ = parent_new;
        parent_new = parent_new->parent;
      }
      ptr_ = parent_new;
    }
    return *this;
  }

  Iterator operator++(int) noexcept {
    Iterator tmp(*this);
    operator++();
    return tmp;
  }

  Iterator& operator--() noexcept {
    if (!ptr_)
      ptr_ = ptr_empty_->parent;
    else if (ptr_->left) {
      ptr_ = ptr_->left;
      while (ptr_->right) ptr_ = ptr_->right;
    } else {
      NodeTree* parent_new = ptr_->parent;
      while (parent_new && ptr_ == parent_new->left) {
        ptr_ = parent_new;
        parent_new = parent_new->parent;
      }
      ptr_ = parent_new;
    }
    return *this;
  }

  Iterator operator--(int) noexcept {
    Iterator tmp(*this);
    operator--();
    return tmp;
  }

  bool operator==(const Iterator& it) const noexcept {
    return (ptr_ == it.ptr_);
  }

  bool operator!=(const Iterator& it) const noexcept {
    return (ptr_ != it.ptr_);
  }

 private:
  NodeTree* ptr_;
  NodeTree* ptr_empty_;
};

template <typename key_type, typename mapped_type>
class BinaryTree<key_type, mapped_type>::ConstIterator {
 public:
  friend class BinaryTree;
  friend class Iterator;

  ConstIterator(NodeTree* const_ptr_ = nullptr,
                NodeTree* const_ptr_empty_ = nullptr)
      : const_ptr_(const_ptr_), const_ptr_empty_(const_ptr_empty_) {}

  ConstIterator(Iterator i)
      : const_ptr_(i.ptr_), const_ptr_empty_(i.ptr_empty_) {}

  NodeTree* get_const_ptr() const { return const_ptr_; }

  const_reference operator*() const noexcept {
    if (const_ptr_)
      return const_ptr_->data;
    else
      return const_ptr_empty_->data;
  }

  const value_type* operator->() const {
    if (const_ptr_)
      return &(const_ptr_->data);
    else
      return &(const_ptr_empty_->data);
  }

  ConstIterator& operator++() noexcept {
    if (!const_ptr_)
      const_ptr_ = const_ptr_empty_;
    else if (const_ptr_->right) {
      const_ptr_ = const_ptr_->right;
      while (const_ptr_->left) const_ptr_ = const_ptr_->left;
    } else {
      NodeTree* parent_new = const_ptr_->parent;
      while (parent_new && const_ptr_ == parent_new->right) {
        const_ptr_ = parent_new;
        parent_new = parent_new->parent;
      }
      const_ptr_ = parent_new;
    }
    return *this;
  }

  ConstIterator operator++(int) noexcept {
    ConstIterator tmp(*this);
    operator++();
    return tmp;
  }

  ConstIterator& operator--() noexcept {
    if (!const_ptr_)
      const_ptr_ = const_ptr_empty_->parent;
    else if (const_ptr_->left) {
      const_ptr_ = const_ptr_->left;
      while (const_ptr_->right) const_ptr_ = const_ptr_->right;
    } else {
      NodeTree* parent_new = const_ptr_->parent;
      while (parent_new && const_ptr_ == parent_new->left) {
        const_ptr_ = parent_new;
        parent_new = parent_new->parent;
      }
      const_ptr_ = parent_new;
    }
    return *this;
  }

  ConstIterator operator--(int) noexcept {
    ConstIterator tmp(*this);
    operator--();
    return tmp;
  }

  bool operator==(const ConstIterator& it) const noexcept {
    return (const_ptr_ == it.const_ptr_);
  }

  bool operator!=(const ConstIterator& it) const noexcept {
    return (const_ptr_ != it.const_ptr_);
  }

 private:
  const NodeTree* const_ptr_;
  const NodeTree* const_ptr_empty_;
};

template <typename key_type, typename mapped_type>
typename BinaryTree<key_type, mapped_type>::Iterator
BinaryTree<key_type, mapped_type>::begin() noexcept {
  NodeTree* min_node = FindMinNode(root_);
  NodeTree* empty = empty_node_;
  return Iterator(min_node, empty);
}
template <typename key_type, typename mapped_type>
typename BinaryTree<key_type, mapped_type>::ConstIterator
BinaryTree<key_type, mapped_type>::begin() const noexcept {
  NodeTree* min_node = FindMinNode(root_);
  NodeTree* empty = empty_node_;
  return ConstIterator(min_node, empty);
}

template <typename key_type, typename mapped_type>
typename BinaryTree<key_type, mapped_type>::ConstIterator
BinaryTree<key_type, mapped_type>::end() const noexcept {
  NodeTree* empty = empty_node_;
  return ConstIterator(nullptr, empty);
}
template <typename key_type, typename mapped_type>
typename BinaryTree<key_type, mapped_type>::Iterator
BinaryTree<key_type, mapped_type>::end() noexcept {
  NodeTree* empty = empty_node_;
  return Iterator(nullptr, empty);
}
template <typename key_type, typename mapped_type>
BinaryTree<key_type, mapped_type>::BinaryTree() : root_(nullptr), size_(0) {
  empty_node_ = new NodeTree{value_type(), root_, nullptr, nullptr, 0};
}

template <typename key_type, typename mapped_type>
BinaryTree<key_type, mapped_type>::BinaryTree(
    std::initializer_list<value_type> const& items)
    : BinaryTree() {
  for (const auto& element : items) insert(element);
  empty_node_->parent = FindMaxNode(root_);
}

template <typename key_type, typename mapped_type>
BinaryTree<key_type, mapped_type>::BinaryTree(const BinaryTree& tree)
    : BinaryTree() {
  *this = tree;
}

template <typename key_type, typename mapped_type>
BinaryTree<key_type, mapped_type>::BinaryTree(BinaryTree&& tree)
    : BinaryTree() {
  swap(tree);
}

template <typename key_type, typename mapped_type>
BinaryTree<key_type, mapped_type>::~BinaryTree() {
  clear();
  delete empty_node_;
}

template <typename key_type, typename mapped_type>
BinaryTree<key_type, mapped_type>& BinaryTree<key_type, mapped_type>::operator=(
    const BinaryTree& tree) {
  if (this != &tree) {
    clear();
    root_ = CopyNode(tree.root_);
    empty_node_->parent = FindMaxNode(root_);
  }
  return *this;
}

template <typename key_type, typename mapped_type>
BinaryTree<key_type, mapped_type>& BinaryTree<key_type, mapped_type>::operator=(
    BinaryTree&& tree) {
  swap(tree);
  return *this;
}

template <typename key_type, typename mapped_type>
typename BinaryTree<key_type, mapped_type>::NodeTree*
BinaryTree<key_type, mapped_type>::CopyNode(NodeTree* node) {
  if (!node) return nullptr;
  NodeTree* new_node =
      new NodeTree{node->data, node->parent, nullptr, nullptr, node->height};
  ++size_;
  new_node->left = CopyNode(node->left);
  new_node->right = CopyNode(node->right);
  return new_node;
}

template <typename key_type, typename mapped_type>
const mapped_type& BinaryTree<key_type, mapped_type>::at(
    const key_type& key) const {
  NodeTree* current = root_;
  if (FindNode(root_, key)) {
    while (current) {
      if (current->data.first == key) {
        return current->data.second;
      }
      if (key < current->data.first) {
        current = current->left;
      } else {
        current = current->right;
      }
    }
  }
  throw std::out_of_range("key not found");
}
template <typename key_type, typename mapped_type>
mapped_type& BinaryTree<key_type, mapped_type>::at(const key_type& key) {
  NodeTree* current = root_;
  while (current) {
    if (current->data.first == key) {
      return current->data.second;
    }
    if (key < current->data.first) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  throw std::out_of_range("key not found");
}

template <typename key_type, typename mapped_type>
mapped_type& BinaryTree<key_type, mapped_type>::operator[](
    const key_type& key) {
  NodeTree* find_node = FindNode(root_, key);
  if (!find_node) {
    root_ =
        InsertNode(root_, std::pair<key_type, mapped_type>(key, mapped_type()));
    empty_node_->parent = FindMaxNode(root_);
    find_node = FindNode(root_, key);
  }
  return find_node->data.second;
}

template <typename key_type, typename mapped_type>
bool BinaryTree<key_type, mapped_type>::empty() const noexcept {
  return size_ == 0;
}

template <typename key_type, typename mapped_type>
typename BinaryTree<key_type, mapped_type>::size_type
BinaryTree<key_type, mapped_type>::size() const noexcept {
  return size_;
}

template <typename key_type, typename mapped_type>
typename BinaryTree<key_type, mapped_type>::size_type
BinaryTree<key_type, mapped_type>::max_size() const noexcept {
  return SIZE_MAX / sizeof(NodeTree) / 2;
}

template <typename key_type, typename mapped_type>
void BinaryTree<key_type, mapped_type>::clear() {
  DeleteNode(root_);
  root_ = nullptr;
  size_ = 0;
  empty_node_->parent = root_;
}

template <typename key_type, typename mapped_type>
std::pair<typename s21::BinaryTree<key_type, mapped_type>::Iterator, bool>
s21::BinaryTree<key_type, mapped_type>::insert(const value_type& value) {
  NodeTree* node = FindNode(root_, value.first);
  Iterator it;
  if (node) {
    it.ptr_ = node;
    return std::pair<Iterator, bool>(it, false);
  }
  root_ = InsertNode(root_, value);
  empty_node_->parent = FindMaxNode(root_);
  node = FindNode(root_, value.first);
  it.ptr_ = node;
  return std::pair<Iterator, bool>(it, true);
}

template <typename key_type, typename mapped_type>
std::pair<typename s21::BinaryTree<key_type, mapped_type>::Iterator, bool>
s21::BinaryTree<key_type, mapped_type>::insert(const key_type& key,
                                               const mapped_type& obj) {
  NodeTree* node = FindNode(root_, key);
  Iterator it;
  if (node) {
    it.ptr_ = node;
    return std::pair<Iterator, bool>(it, false);
  }
  root_ = InsertNode(root_, std::pair<key_type, mapped_type>(key, obj));
  empty_node_->parent = FindMaxNode(root_);
  node = FindNode(root_, key);
  it.ptr_ = node;
  return std::pair<Iterator, bool>(it, true);
}

template <typename key_type, typename mapped_type>
std::pair<typename s21::BinaryTree<key_type, mapped_type>::Iterator, bool>
s21::BinaryTree<key_type, mapped_type>::insert_or_assign(
    const key_type& key, const mapped_type& obj) {
  NodeTree* node = FindNodeToInsert(root_, key);
  Iterator it;
  if (node) {
    node->data.second = obj;
    it.ptr_ = node;
    return std::pair<Iterator, bool>(it, false);
  }
  root_ = InsertNode(root_, std::pair<key_type, mapped_type>(key, obj));
  empty_node_->parent = FindMaxNode(root_);
  node = FindNodeToInsert(root_, key);
  it.ptr_ = node;
  return std::pair<Iterator, bool>(it, true);
}

template <typename key_type, typename mapped_type>
bool BinaryTree<key_type, mapped_type>::contains(const key_type& key) const {
  NodeTree* current = root_;
  while (current) {
    if (current->data.first == key) {
      return true;
    }
    if (key < current->data.first) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return false;
}

template <typename key_type, typename mapped_type>
void BinaryTree<key_type, mapped_type>::DeleteNode(NodeTree* node) {
  if (node) {
    if (node->left) DeleteNode(node->left);
    if (node->right) DeleteNode(node->right);
    delete node;
  }
}

template <typename key_type, typename mapped_type>
typename BinaryTree<key_type, mapped_type>::NodeTree*
BinaryTree<key_type, mapped_type>::FindMinNode(NodeTree* node) const {
  if (!node) return nullptr;
  return node->left ? FindMinNode(node->left) : node;
}

template <typename key_type, typename mapped_type>
typename BinaryTree<key_type, mapped_type>::NodeTree*
BinaryTree<key_type, mapped_type>::FindMaxNode(NodeTree* node) const {
  if (!node) return nullptr;
  return node->right ? FindMaxNode(node->right) : node;
}

template <typename key_type, typename mapped_type>
typename BinaryTree<key_type, mapped_type>::NodeTree*
BinaryTree<key_type, mapped_type>::FindNode(NodeTree* node,
                                            const key_type& key) const {
  if (!node || key == node->data.first) return node;
  if (key < node->data.first)
    return FindNode(node->left, key);
  else
    return FindNode(node->right, key);
}

template <typename key_type, typename mapped_type>
typename BinaryTree<key_type, mapped_type>::NodeTree*
BinaryTree<key_type, mapped_type>::FindNodeToInsert(NodeTree* node,
                                                    const key_type& key) {
  if (!node) return node;
  if (key < node->data.first)
    return FindNodeToInsert(node->left, key);
  else
    return FindNodeToInsert(node->right, key);
}

template <typename key_type, typename mapped_type>
typename BinaryTree<key_type, mapped_type>::NodeTree*
BinaryTree<key_type, mapped_type>::SearchKeyOrNode(NodeTree* node,
                                                   const key_type& key) {
  NodeTree* find_node = nullptr;
  NodeTree* current = node;
  while ((current)) {
    find_node = current;
    if (key < current->data.first)
      current = current->left;
    else
      current = current->right;
  }
  if (current) find_node = current;
  return find_node;
}

template <typename key_type, typename mapped_type>
typename BinaryTree<key_type, mapped_type>::NodeTree*
BinaryTree<key_type, mapped_type>::InsertNode(NodeTree* node,
                                              const value_type& value) {
  if (!node) {
    ++size_;
    return new NodeTree{value, nullptr, nullptr, nullptr, 1};
  }
  NodeTree* tmp = SearchKeyOrNode(node, value.first);

  ++size_;
  if (value.first < tmp->data.first)
    tmp->left = new NodeTree{value, tmp, nullptr, nullptr, 1};
  else
    tmp->right = new NodeTree{value, tmp, nullptr, nullptr, 1};
  UpdateHeight(tmp);
  return BalanceUntilRoot(tmp);
}

template <typename key_type, typename mapped_type>
typename BinaryTree<key_type, mapped_type>::NodeTree*
BinaryTree<key_type, mapped_type>::DeleteMinNode(NodeTree* node) {
  if (!node) return nullptr;
  NodeTree* min_node = FindMinNode(node);
  NodeTree* parent = min_node->parent;
  if (min_node == node) {
    if (node->right) {
      parent->right = node->right;
      node = node->right;
    } else {
      parent->right = nullptr;
      node = nullptr;
    }
  } else {
    if (min_node->right) {
      NodeTree* tmp = min_node->right;
      tmp->parent = parent;
      parent->left = tmp;
    } else {
      parent->left = nullptr;
    }
  }
  delete min_node;
  if (!node) return nullptr;
  while (parent) {
    UpdateHeight(parent);
    parent = parent->parent;
  }
  return Balance(node);
}

template <typename key_type, typename mapped_type>
void BinaryTree<key_type, mapped_type>::erase(const key_type& key) {
  root_ = RemoveNode(root_, key);
  empty_node_->parent = FindMaxNode(root_);
}

template <typename key_type, typename mapped_type>
void BinaryTree<key_type, mapped_type>::erase(Iterator pos) {
  key_type deleted_key = pos->first;
  root_ = RemoveNode(root_, deleted_key);
  empty_node_->parent = FindMaxNode(root_);
}

template <typename key_type, typename mapped_type>
void BinaryTree<key_type, mapped_type>::swap(BinaryTree& tree) {
  if (this != &tree) {
    NodeTree* tmp_root = root_;
    NodeTree* tmp_empty = empty_node_;
    size_type tmp_size = size_;
    root_ = tree.root_;
    empty_node_ = tree.empty_node_;
    size_ = tree.size_;
    tree.root_ = tmp_root;
    tree.empty_node_ = tmp_empty;
    tree.size_ = tmp_size;
  }
}

template <typename key_type, typename mapped_type>
void BinaryTree<key_type, mapped_type>::merge(BinaryTree& tree) {
  if (this != &tree) {
    iterator it = tree.begin();
    bool insert_key = false;
    key_type tmp_del = key_type();
    key_type tmp_next = key_type();
    while (it != tree.end()) {
      insert_key =
          insert(std::pair<key_type, mapped_type>(it->first, it->second))
              .second;
      if (insert_key) {
        tmp_del = it->first;
        ++it;
        tmp_next = it->first;
        tree.erase(tmp_del);
        it.ptr_ = FindNode(tree.root_, tmp_next);
      } else
        ++it;
    }
  }
}

template <typename key_type, typename mapped_type>
typename BinaryTree<key_type, mapped_type>::NodeTree*
BinaryTree<key_type, mapped_type>::RemoveNode(NodeTree* node,
                                              const key_type& key) {
  if (!node) return nullptr;
  NodeTree* del_node = FindNode(node, key);
  if (!del_node) return node;
  NodeTree* parent = del_node->parent;
  if ((!(del_node->left)) && (!(del_node->right))) {
    if (del_node == node) {
      node = nullptr;
    } else if ((parent != nullptr) && (del_node == parent->left)) {
      parent->left = nullptr;
    } else {
      parent->right = nullptr;
    }
  } else if (!del_node->left) {
    if (del_node == node) {
      node = del_node->right;
    } else if ((parent != nullptr) && (del_node == parent->left)) {
      parent->left = del_node->right;
    } else {
      parent->right = del_node->right;
    }
    del_node->right->parent = parent;
  } else if (!del_node->right) {
    if (del_node == node) {
      node = del_node->left;
    } else if ((parent != nullptr) && (del_node == parent->left)) {
      parent->left = del_node->left;
    } else {
      parent->right = del_node->left;
    }
    del_node->left->parent = parent;
  } else {
    NodeTree* tmp = FindMinNode(del_node->right);
    NodeTree* min_node = new NodeTree{tmp->data, parent, del_node->left,
                                      del_node->right, del_node->height};
    min_node->right = DeleteMinNode(del_node->right);
    min_node->left->parent = min_node;
    if (min_node->right) {
      min_node->right->parent = min_node;
    }
    if (parent) {
      if (parent->left == del_node) {
        parent->left = min_node;
      } else {
        parent->right = min_node;
      }
    } else {
      node = min_node;
    }
    UpdateHeight(min_node);
  }
  --size_;
  delete del_node;
  if (!node) return nullptr;
  if (parent) UpdateHeight(parent);
  return parent ? BalanceUntilRoot(parent) : Balance(node);
}

template <typename key_type, typename mapped_type>
int BinaryTree<key_type, mapped_type>::GetHeight(NodeTree* node) const {
  return node ? node->height : 0;
}

template <typename key_type, typename mapped_type>
int BinaryTree<key_type, mapped_type>::BalanceFactor(NodeTree* node) const {
  return node ? GetHeight(node->right) - GetHeight(node->left) : 0;
}

template <typename key_type, typename mapped_type>
void BinaryTree<key_type, mapped_type>::UpdateHeight(NodeTree* node) {
  const int leftHeight = GetHeight(node->left);
  const int rightHeight = GetHeight(node->right);
  if (leftHeight > rightHeight)
    node->height = leftHeight + 1;
  else
    node->height = rightHeight + 1;
}

template <typename key_type, typename mapped_type>
typename BinaryTree<key_type, mapped_type>::NodeTree*
BinaryTree<key_type, mapped_type>::RotateLeft(NodeTree* node) {
  NodeTree* tmp_parent = node->parent;
  NodeTree* tmp = node->right;
  node->right = tmp->left;
  if (tmp->left) tmp->left->parent = node;
  tmp->left = node;
  node->parent = tmp;
  tmp->parent = tmp_parent;
  if (tmp_parent) {
    if (tmp_parent->right == node)
      tmp_parent->right = tmp;
    else
      tmp_parent->left = tmp;
  }
  UpdateHeight(node);
  UpdateHeight(tmp);
  return tmp;
}

template <typename key_type, typename mapped_type>
typename BinaryTree<key_type, mapped_type>::NodeTree*
BinaryTree<key_type, mapped_type>::RotateRight(NodeTree* node) {
  NodeTree* tmp_parent = node->parent;
  NodeTree* tmp = node->left;
  node->left = tmp->right;
  if (tmp->right) tmp->right->parent = node;
  tmp->right = node;
  node->parent = tmp;
  tmp->parent = tmp_parent;
  if (tmp_parent) {
    if (tmp_parent->left == node)
      tmp_parent->left = tmp;
    else
      tmp_parent->right = tmp;
  }
  UpdateHeight(node);
  UpdateHeight(tmp);
  return tmp;
}

template <typename key_type, typename mapped_type>
typename BinaryTree<key_type, mapped_type>::NodeTree*
BinaryTree<key_type, mapped_type>::Balance(NodeTree* node) {
  UpdateHeight(node);
  if (BalanceFactor(node) == 2) {
    if (BalanceFactor(node->right) < 0) {
      node->right = RotateRight(node->right);
    }
    return RotateLeft(node);
  }
  if (BalanceFactor(node) == -2) {
    if (BalanceFactor(node->left) > 0) {
      node->left = RotateLeft(node->left);
    }
    return RotateRight(node);
  }
  return node;
}

template <typename key_type, typename mapped_type>
typename BinaryTree<key_type, mapped_type>::NodeTree*
BinaryTree<key_type, mapped_type>::BalanceUntilRoot(NodeTree* node) {
  NodeTree* parent = node->parent;
  while (parent) {
    if (parent->parent) {
      if (parent == parent->parent->left)
        parent->parent->left = Balance(parent);
      else
        parent->parent->right = Balance(parent);
      parent = parent->parent;
    } else
      return Balance(parent);
  }
  return Balance(node);
}
