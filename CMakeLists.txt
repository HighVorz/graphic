cmake_minimum_required(VERSION 3.10)

project(Painter)

include_directories()
include_directories($ENV{UniversalCRTSdkDir}/Include/ucrt)
include_directories($ENV{UniversalCRTSdkDir}/Include/10.0.10056.0/ucrt)

add_executable(Painter WIN32 src/main.cpp src/painter.cpp)


