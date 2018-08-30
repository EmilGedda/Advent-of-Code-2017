cmake_minimum_required(VERSION 3.12)
project(AdventOfCode CXX)

file(GLOB_RECURSE srcs CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*_*.cpp")
foreach(file ${srcs})

    # Add target for day
    get_filename_component(_target ${file} NAME_WE)
    add_executable(${_target} ${file} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
    message(STATUS "Adding target: ${_target}")
    target_compile_features(${_target} PRIVATE cxx_std_20)
    target_compile_options(${_target} PRIVATE -march=native -Wall -Wextra -pedantic)
    target_include_directories(${_target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

    # Create test target 
    string(REPLACE "_" ";" _testparts ${_target})
    list(GET _testparts 0 _test)
    message(STATUS "Adding test: ${_test}.txt")
    add_custom_target("test_${_target}"
        COMMAND $<TARGET_FILE:${_target}> < ${CMAKE_CURRENT_SOURCE_DIR}/tests/${_test}.txt
        DEPENDS ${_target}    
    )

endforeach()
