#include "Summary.hpp"
#include "SpinLock.hpp"
#include "cpplang.hpp"

void Summary::add_sales(const SalesData &sd) {
  SpinLockGuard lock_guard(m_lock);

  const string &id = sd.get_id();
  auto iter = m_sales.find(id);
  if (iter == m_sales.end())
    m_sales[id] = sd;
  else {
    iter->second.inc_num(sd.get_num());
    iter->second.inc_sum(sd.get_sum());
  }
}

Summary::minmax_sales_type Summary::minmax_sales() const {
  SpinLockGuard lock_guard(m_lock);

  if (m_sales.empty())
    return minmax_sales_type();

  auto res = std::minmax_element(
      m_sales.begin(), m_sales.end(), [](const auto &a, const auto &b) {
        return a.second.get_num() < b.second.get_num();
      });

  auto min_pos = res.first;
  auto max_pos = res.second;

  return {min_pos->second.get_id(), max_pos->second.get_id()};
}