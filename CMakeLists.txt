cmake_minimum_required(VERSION 3.0.0)
project(data_struct LANGUAGES C CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(leetcode)
add_subdirectory(study)
add_subdirectory(JZ_offer)
add_subdirectory(hot_100)

add_executable(main main.cc)
target_link_libraries(main libfmt.a)