#include "ticket_solver.hpp"

#include <algorithm>
#include <math.h>
#include <iostream>
#include <vector>

namespace solver
{

std::string TicketSolver::Solve(const std::string& input)
{
  return std::to_string(FindLuckyTickets(std::stoi(input)));
}

Array TicketSolver::FillNextArray(const Array& array) {
  auto new_size = array.size() + 9;
  Array new_array(new_size, 0);
  for (int i = 0; i < new_size; ++i) {
    int new_value = 0;
    for (int j = 0; j < 10; ++j) {
      auto ind = i - j;
      if (ind >= 0 and ind < array.size()) {
        new_value += array[ind];
      }
    }
    new_array[i] = new_value;

  }  
  return new_array;
}


uint64_t TicketSolver::FindLuckyTickets(int n) {
  Array array(10, 1);

  for (int i = 0; i < (n - 1); ++i) {
    array = FillNextArray(array);
  }

  uint64_t count = 0;
  for(const auto& i : array) {
    count += i * i;
  }
  return count;
}

} // namespace solver
