#ifndef _SUMMARY_HPP
#define _SUMMARY_HPP

#include "cpplang.hpp"
#include "SpinLock.hpp"
#include "SalesData.hpp"

class Summary final {
public:
    using this_type = Summary;
    using map_type = std::map<string, SalesData>;
    using minmax_sales_type = std::pair<string, string>;

private:
    mutable SpinLock m_lock;
    map_type m_sales;

public:
    Summary() = default;
    ~Summary() = default;

    Summary(const this_type&) = delete;
    Summary& operator = (const this_type&) = delete;

public:
    void add_sales(const SalesData& sd);
    minmax_sales_type minmax_sales() const;
};

#endif