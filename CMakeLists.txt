cmake_minimum_required(VERSION 3.16)
project(yaml_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找 yaml-cpp
find_package(yaml-cpp REQUIRED)

# 定义可执行目标：目标名 -> 源文件
add_executable(yaml_demo "作业1.cpp")

# 给目标链接 yaml-cpp
if(TARGET yaml-cpp::yaml-cpp)
    target_link_libraries(yaml_demo PRIVATE yaml-cpp::yaml-cpp)  # yaml-cpp 0.8+
else()
    target_link_libraries(yaml_demo PRIVATE yaml-cpp)            # yaml-cpp 0.7 (Ubuntu 22.04 自带)
endif()