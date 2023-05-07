cmake_minimum_required(VERSION 3.10)

project(Painter)

find_package(OpenMP REQUIRED)

include_directories()
#include_directories($ENV{UniversalCRTSdkDir}/Include/ucrt)
#include_directories($ENV{UniversalCRTSdkDir}/Include/10.0.10056.0/ucrt)
#include_directories($ENV{UniversalCRTSdkDir}/Include/10.0.19041.0/um)

add_executable(Painter WIN32 src/main.cpp src/painter.cpp src/wndproc.cpp)

target_link_libraries(Painter OpenMP::OpenMP_CXX)

