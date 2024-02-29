#ifndef _SALESDATA_HPP
#define _SALESDATA_HPP

#include "cpplang.hpp"
#include <msgpack.hpp>

class SalesData final {
#if 0
  using string = std::string;
#endif
  using this_type = SalesData;

private:
  string m_id = "";
  uint m_num = 0;
  double m_sum = 0;

public:
  MSGPACK_DEFINE(m_id, m_num, m_sum);

public:
  SalesData() = default;
  ~SalesData() = default;

  SalesData(const string &id, uint num, double sum) noexcept;
  SalesData(const string &id) noexcept;

  SalesData(const this_type &) = default;
  SalesData &operator=(const this_type &) = default;

  SalesData(this_type &&) = default;
  SalesData &operator=(this_type &&) = default;

public:
  const string &get_id() const noexcept;
  uint get_num() const noexcept;
  void inc_num(uint n) noexcept;
  double get_sum() const noexcept;
  void inc_sum(double s) noexcept;
};

#endif