cmake_minimum_required(VERSION 3.21)
project(cpp)

set(CMAKE_CXX_STANDARD 14)
set(SRC_LIST
        src/0001.cpp
        src/0146.cpp
        src/0203.cpp
        src/0208.cpp
        src/0704.cpp
        src/s2-063.cpp src/0707.cpp src/0206.cpp src/0024.cpp src/0025.cpp src/0019.cpp src/0160.cpp src/0142.cpp src/0141.cpp src/0021.cpp src/0234.cpp)

add_executable(${PROJECT_NAME} ${SRC_LIST})
