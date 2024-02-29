#ifndef _SPINLOCK_HPP
#define _SPINLOCK_HPP

#include "cpplang.hpp"

class SpinLock final {

private:
  // The initialization of atomic_flag must use an initialization list,
  // couldn't be assigned a bool value directly.
  std::atomic_flag m_lock = {false};

public:
  using this_type = SpinLock;

  SpinLock() = default;
  ~SpinLock() = default;

  SpinLock(const this_type &) = delete;
  SpinLock &operator=(const this_type &) = delete;

public:
  void lock() noexcept;
  bool try_lock() noexcept;
  void unlock() noexcept;
};

class SpinLockGuard final {

private:
  SpinLock &m_lock;

public:
  using this_type = SpinLockGuard;

  SpinLockGuard(const this_type &) = delete;
  SpinLockGuard &operator=(const this_type &) = delete;

  SpinLockGuard(SpinLock &lock) noexcept;
  ~SpinLockGuard() noexcept;
};

#endif