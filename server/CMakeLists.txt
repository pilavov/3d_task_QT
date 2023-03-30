cmake_minimum_required(VERSION 3.24)
project(server)

set(CMAKE_CXX_STANDARD 14)



add_executable(server server.cpp)
target_link_libraries(server ${Boost_LIBRARIES})


