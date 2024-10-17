# 设置 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 项目名称
project(GradeManagementSystem)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 设置项目的源文件路径
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

# 添加 include 路径
include_directories(${INCLUDE_DIR})

# 查找所有源文件
file(GLOB SRC_FILES "${SRC_DIR}/*.cpp")

# 生成可执行文件
add_executable(grade_management_system ${SRC_FILES})

# 将生成的可执行文件保存到 bin 目录中
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
