cmake_minimum_required(VERSION 3.12)
project(algebraic_algo)

include_directories("include/")

add_executable(
  algebraic_algo
  src/main.cpp
  src/power_solver.cpp
  src/prime_solver.cpp
  src/fibonacci_solver.cpp
  src/tester.cpp
)
