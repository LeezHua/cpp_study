#include "SalesData.hpp"

SalesData::SalesData(const string &id, uint num, double sum) noexcept {
  m_id = id;
  m_num = num;
  m_sum = sum;
}

SalesData::SalesData(const string &id) noexcept : SalesData(id, 0, 0) {}

const string &SalesData::get_id() const noexcept { return m_id; }

uint SalesData::get_num() const noexcept { return m_num; }

void SalesData::inc_num(uint n) noexcept { m_num += n; }

double SalesData::get_sum() const noexcept { return m_sum; };

void SalesData::inc_sum(double s) noexcept { m_sum += s; }