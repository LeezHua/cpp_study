#ifndef _ZMQ_HPP
#define _ZMQ_HPP

#include "cpplang.hpp"
#include <zmq.hpp>

template <int thread_num = 1> class ZmqContext final {

  static_assert(thread_num > 0, "thread_num > 0");

  static zmq::context_t context;

public:
  ZmqContext() = default;
  ~ZmqContext() = default;

public:

  static zmq::socket_t recv_sock(int hwm = 1000, int linger = 10);

  static zmq::socket_t send_sock(int hwm = 1000, int linger = 10);
};

#endif