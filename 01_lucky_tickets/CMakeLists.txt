cmake_minimum_required(VERSION 3.12)
project(lucky_tickets)

include_directories("include/")

add_executable(
  lucky_tickets
  src/main.cpp
  src/ticket_solver.cpp
  src/tester.cpp
)
