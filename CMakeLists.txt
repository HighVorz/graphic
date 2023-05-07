cmake_minimum_required(VERSION 3.10)

project(Painter)

find_package(OpenMP REQUIRED)

include_directories()


add_executable(Painter WIN32 src/main.cpp src/painter.cpp src/wndproc.cpp)

target_link_libraries(Painter OpenMP::OpenMP_CXX)

