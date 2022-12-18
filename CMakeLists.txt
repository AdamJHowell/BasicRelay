cmake_minimum_required(VERSION 3.24)
project(BasicRelay)

set(CMAKE_CXX_STANDARD 17)

add_executable(BasicRelay BasicRelay.ino BasicRelay.ino)

set_target_properties( BasicRelay PROPERTIES LINKER_LANGUAGE CXX )
