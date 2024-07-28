#ifndef S21_ARRAY_H_
#define S21_ARRAY_H_

#include <initializer_list>
#include <limits>

template <class T, size_t N>
class Array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  Array(){};
  Array(std::initializer_list<T> const &items) {
    if (N < items.size()) {
      throw std::out_of_range("It is soooo baaad...");
    }
    for (auto iter = items.begin(), i = 0; iter != items.end(); ++iter, ++i) {
      array_[i] = *iter;
    }
  }

  Array(const Array &a) { std::copy(a.array_, a.array_ + N, array_); }
  Array(Array &&a) { std::copy(a.array_, a.array_ + N, array_); }
  ~Array(){};

  Array<T, N> &operator=(const Array<T, N> &a) {
    if (this != &a) {
      std::copy(a.array_, a.array_ + N, array_);
    }
    return *this;
  }
  Array<T, N> &operator=(Array<T, N> &&a) {
    if (this != &a) {
      std::copy(a.array_, a.array_ + N, array_);
    }
    return *this;
  }

  reference operator[](size_type pos) { return array_[pos]; }
  const_reference operator[](size_type pos) const { return array_[pos]; }
  reference front() { return array_[0]; }
  const_reference front() const { return array_[0]; }
  reference back() { return array_[N - 1]; }
  const_reference back() const { return array_[N - 1]; }
  iterator data() noexcept { return array_; }
  const_iterator data() const noexcept { return array_; }

  iterator begin() noexcept { return array_; }
  const_iterator begin() const noexcept { return const_iterator(data()); }
  iterator end() noexcept { return array_ + N; }
  const_iterator end() const noexcept { return const_iterator(data() + N); }

  reference at(size_type pos) {
    if (pos >= N) {
      throw std::out_of_range("It is soooo baaad...");
    }
    return array_[pos];
  }
  const_reference at(size_type pos) const {
    if (pos >= N) {
      throw std::out_of_range("It is soooo baaad...");
    }
    return array_[pos];
  }
  bool empty() const noexcept { return N == 0; }
  size_type size() const noexcept { return N; }
  size_type max_size() const noexcept { return N; }

  void swap(Array &other) noexcept {
    if (this != &other) {
      std::swap(array_, other.array_);
    }
  }

  void fill(const_reference value) {
    for (size_type i = 0; i < N; ++i) {
      array_[i] = value;
    }
  }

 private:
  T array_[N];
};

#endif  // S21_ARRAY_H_
