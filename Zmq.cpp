#include "Zmq.hpp"
#include <zmq.hpp>

template <int thread_num>
zmq::context_t ZmqContext<thread_num>::context(thread_num);

// TODO: Is the default hwm 1000?
template <int threadf_num>
zmq::socket_t ZmqContext<threadf_num>::recv_sock(int hwm, int linger) {
  zmq::socket_t sock(context, ZMQ_PULL);    // TODO: deal with exception

  sock.set(zmq::sockopt::rcvhwm, hwm);
  sock.set(zmq::sockopt::linger, linger);

  return sock;
}

template <int thread_num>
zmq::socket_t ZmqContext<thread_num>::send_sock(int hwm, int linger) {
  zmq::socket_t sock(context, ZMQ_PUSH);    // TODO: deal with exception

  sock.set(zmq::sockopt::rcvhwm, hwm);
  sock.set(zmq::sockopt::linger, linger);

  return sock;
}

void zmq_test() { std::cout << "zmq tset passed!\n"; }