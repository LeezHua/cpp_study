## bug

date: 2024/2/21

今天测试`msgpack`的用法时发现了一个非常离谱的bug。    
使用如下程序段测试**pack()**和**unpack()**功能，
```cpp
int main(int, char **) {
  std::vector<int> vec = {1, 2, 3, 4, 5};

  msgpack::sbuffer sbuf;
  msgpack::pack(sbuf, vec);

  std::vector<int> vec1;
  auto handle = msgpack::unpack(sbuf.data(), sbuf.size());
  auto obj = handle.get();
  obj.convert(vec1);

  assert(std::equal(begin(vec), end(vec), begin(vec1)));
}
```
这段程序正常运行。  
版本2
```cpp
int main(int, char **) {
  std::vector<int> vec = {1, 2, 3, 4, 5};

  msgpack::sbuffer sbuf;
  msgpack::pack(sbuf, vec);

  std::vector<int> vec1;
  auto obj = msgpack::unpack(sbuf.data(), sbuf.size()).get();
  obj.convert(vec1);

  assert(std::equal(begin(vec), end(vec), begin(vec1)));
}

```
这段程序在执行到**convert()**时会出错，终端输出如下：
```
terminate called after throwing an instance of 'msgpack::v1::type_error'
  what():  std::bad_cast
```
原因待检查.
