cmake_minimum_required(VERSION 3.16)


find_package(Boost 1.71.0 REQUIRED COMPONENTS system thread)
include_directories(${Boost_INCLUDE_DIRS})


add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)

add_subdirectory(server)
add_subdirectory(client)


