# 设置所需的最低CMake版本为3.29，以确保兼容性和功能性
cmake_minimum_required(VERSION 3.29)

# 定义项目名称为planning
project(planning)

# 设置C++标准为C++17，以便编译器使用C++17标准进行编译
set(CMAKE_CXX_STANDARD 17)

# 设置所有生成的可执行文件的输出目录为项目根目录下的bin文件夹
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# 搜索src目录下的所有源文件，并将它们的文件路径存储到变量SRC_LISTS中
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LISTS)

# 使用SRC_LISTS中的源文件创建一个名为common的共享库
add_library(common
  SHARED # 指定生成共享库
  ${SRC_LISTS} # 包含在SRC_LISTS中的所有源文件
)

# 将include目录添加到common库的头文件搜索路径中，供公共访问
target_include_directories(common
  PUBLIC # 指定该目录在链接到common库的目标中也会被包含
  ${PROJECT_SOURCE_DIR}/include # 头文件目录路径
)

# 设置可执行文件的输出路径为项目根目录下的bin文件夹
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 创建一个名为planning_main的可执行文件，源文件为planning_main.cpp
add_executable(planning_main planning_main.cpp)

# 将include目录添加到planning_main可执行文件的头文件搜索路径中，供公共访问
target_include_directories(planning_main
  PUBLIC # 指定该目录在链接到planning_main可执行文件的目标中也会被包含
  ${PROJECT_SOURCE_DIR}/include # 头文件目录路径
)

# 将common库链接到planning_main可执行文件中，供公共访问
target_link_libraries(planning_main
  PUBLIC # 指定该库在链接到planning_main可执行文件的目标中也会被包含
  common # 链接的库名称
)
