#ifndef S21_VECTOR_H_
#define S21_VECTOR_H_
#include <initializer_list>
#include <iostream>
#include <limits>

template <typename T>
class Vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  Vector() : size_(0), capacity_(0), array_(nullptr) {}
  explicit Vector(size_type n) : size_(n), capacity_(n) {
    memory_allocation(capacity_);
  }
  Vector(std::initializer_list<value_type> const &items) {
    memory_allocation(items.size());
    size_ = items.size();
    capacity_ = items.size();
    for (auto i = items.begin(), it = 0; i != items.end(); ++i, ++it) {
      array_[it] = *i;
    }
  }
  Vector(const Vector &v) : Vector() { copy(v); }
  Vector(Vector &&v) : Vector() { this = std::move(v); }
  ~Vector() { memory_clearning(); }
  Vector<T> &operator=(Vector &&v) {
    if (this != &v) {
      swap(v);
    }
    return *this;
  }
  Vector<T> &operator=(const Vector &v) {
    if (this != &v) {
      memory_clearning();
      copy(v);
    }
    return *this;
  }

  reference at(size_type pos) {
    if (pos >= size_) {
      throw std::out_of_range("Out of range, /(T_T)\\");
    }
    return array_[pos];
  }
  const_reference at(size_type pos) const {
    if (pos >= size_) {
      throw std::out_of_range("Out of range, /(T_T)\\");
    }
    return array_[pos];
  }
  reference operator[](size_type pos) noexcept { return array_[pos]; }
  const_reference operator[](size_type pos) const noexcept {
    return array_[pos];
  }
  reference front() noexcept { return array_[0]; }
  const_reference front() const noexcept { return array_[0]; }
  reference back() noexcept { return array_[size_ - 1]; }
  const_reference back() const noexcept { return array_[size_ - 1]; }
  T *data() noexcept { return array_; }
  const T *data() const noexcept { return array_; }

  iterator begin() noexcept { return array_; }
  const_iterator begin() const noexcept { return array_; }
  iterator end() noexcept { return (array_ + (size_)); }
  const_iterator end() const noexcept { return (array_ + (size_)); }

  bool empty() const noexcept { return size_ == 0; }
  size_type size() const noexcept { return size_; }

  size_type max_size() const noexcept {
    return std::numeric_limits<std::ptrdiff_t>::max() / sizeof(value_type);
  }

  void reserve(size_type size) {
    if (size > capacity_) {
      if (size > max_size()) {
        throw std::out_of_range("Out of range, /(T_T)\\");
      }
      redefinition_with_copy(size);
    }
  }

  size_type capacity() const noexcept { return capacity_; }

  void shrink_to_fit() { redefinition_with_copy(size_); }

  void clear() { size_ = 0; }

  iterator insert(const_iterator pos, const_reference value) {
    if (size_ >= capacity_) {
      if (capacity_ == 0) {
        reserve(1);
      } else {
        reserve(capacity_ * 2);
      }
    }
    for (size_type i = size_, j = (size_ + 1); i < pos; --i, --j) {
      array_[j] = array_[i];
    }
    ++size_;
    array_[pos] = value;
    return (array_);
  }

  void erase(iterator pos) {
    size_type pos_ = pos - array_;
    for (size_type i = pos_, j = pos_; i < size_; ++i, ++j) {
      if (i == pos_) {
        ++i;
      }
      array_[j] = array_[i];
    }
    --size_;
  }

  void push_back(const_reference value) {
    if (size_ >= capacity_) {
      reserve(capacity_ == 0 ? 1 : capacity_ * 2);
    }
    array_[size_] = value;
    ++size_;
  }
  void pop_back() { --size_; }

  void swap(Vector &other) {
    if (this != &other) {
      std::swap(size_, other.size_);
      std::swap(capacity_, other.capacity_);
      std::swap(array_, other.array_);
    }
  }

 private:
  void copy(const Vector<T> &value) {
    size_ = value.size_;
    capacity_ = value.capacity_;
    memory_allocation(capacity_);
    for (long unsigned int i = 0; i < size_; ++i) {
      array_[i] = value.array_[i];
    }
  }
  void memory_clearning() {
    std::allocator<value_type>().deallocate(array_, capacity_);
    array_ = nullptr;
  }
  void memory_allocation(const size_type n) {
    array_ = std::allocator<value_type>().allocate(n);
  }
  void zero_padding(const size_type n) {
    for (auto i = 0; i < n; ++i) {
      array_[i] = 0;
    }
  }
  void redefinition_with_copy(const size_type size) {
    auto temp = std::allocator<value_type>().allocate(size);
    for (size_type i = 0; i < size_; ++i) {
      temp[i] = array_[i];
    }
    std::allocator<value_type>().deallocate(array_, capacity_);
    array_ = temp;
    capacity_ = size;
  }

  size_type size_;
  size_type capacity_;
  value_type *array_;
};
#endif  // S21_VECTOR_H_
