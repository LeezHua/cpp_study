cmake_minimum_required(VERSION 3.0.0)
project(BookStoreClient VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

add_executable(${PROJECT_NAME} main.cpp SpinLock.cpp Zmq.cpp SalesData.cpp Packer.cpp)
add_executable(client Client.cpp)
add_executable(service Service.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
