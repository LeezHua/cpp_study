#include "SpinLock.hpp"

// Functions of class SpinLock

void SpinLock::lock() noexcept {
  while (true) {
    if (!m_lock.test_and_set())
      return;
    std::this_thread::yield();
  }
}

bool SpinLock::try_lock() noexcept { return !m_lock.test_and_set(); }

void SpinLock::unlock() noexcept { m_lock.clear(); }

// Functions of SpinLockGuard

SpinLockGuard::SpinLockGuard(SpinLock &lock) noexcept : m_lock(lock) {
  m_lock.lock();
}

SpinLockGuard::~SpinLockGuard() noexcept { m_lock.unlock(); }
