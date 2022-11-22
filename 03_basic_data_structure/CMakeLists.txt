cmake_minimum_required(VERSION 3.12)
project(basic_data_structure)

include_directories("include/")

add_executable(
  basic_data_structure
  src/main.cpp
  src/tester.cpp
)
