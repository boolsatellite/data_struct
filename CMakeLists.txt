cmake_minimum_required(VERSION 3.0.0)
project(data_struct VERSION 0.1.0 LANGUAGES C CXX)

aux_source_directory(. SRC_LIST)

foreach(source ${SRC_LIST})
    set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
    message(STATUS ${source})
    string(REGEX MATCHALL "[0-9A-Za-z_]*.cc" tmp1 ${source})
    message(STATUS ${tmp1})
    string(REGEX REPLACE ".cc" "" target ${tmp1})
    message(STATUS ${target})
    add_executable(${target} ${source})
endforeach()

add_subdirectory(leetcode)