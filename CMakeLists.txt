cmake_minimum_required(VERSION 3.10)
project(leetcode_cpp)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 生成 compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 添加头文件目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 递归查找所有源文件
file(GLOB_RECURSE SOURCES "src/*.cpp")

# 为每个源文件创建可执行文件
foreach(source ${SOURCES})
    # 获取不带扩展名的文件名
    get_filename_component(name ${source} NAME_WE)
    add_executable(${name} ${source})
endforeach()
