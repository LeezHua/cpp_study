#include "SalesData.hpp"
#include "cpplang.hpp"
#include <msgpack.hpp>
#include <msgpack/v3/unpack_decl.hpp>

// TODO: deal with exceptions.
class SalesDataPacker final {

public:
  static msgpack::sbuffer pack(const SalesData &sd) {
    msgpack::sbuffer sbuf;
    msgpack::pack(sbuf, sd);
    return sbuf;
  }

  static SalesData unpack(const msgpack::sbuffer sbuf) {
    SalesData sd;
    auto handle = msgpack::unpack(sbuf.data(), sbuf.size());
    auto obj = handle.get();
    obj.convert(sd);
    return sd;
  }
};