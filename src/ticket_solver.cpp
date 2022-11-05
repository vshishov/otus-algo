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





// int recurse(int N, int sumA=0, int sumB=0) {
//     int count = 0;

//     if (N == 0) {
//         if (sumA == sumB) {
//             return 1;
//         }
//         return 0;
//     }

//     for (int a = 0; a < 10; ++a) 
//         for (int b = 0; b < 10; ++b) {
//             count += recurse(N - 1, sumA + a, sumB + b);
//         }

//     return count;
// }

// int main_() {
//     const auto MAX_TICKETS = 1000000;
//     int sum = 0;
//     for (int i = 0; i < MAX_TICKETS; ++i) {
//         auto left = i / 1000;
//         auto right = i % 1000;
//         if (get_sum_digits(left) == get_sum_digits(right)) {
//             // std::cout << i << " yes" << std::endl;
//             ++sum;
//         }
//     }
//     std::cout << "Tickets: " << sum << std::endl;

//      std::cout << "Tickets2: " << recurse(3) << std::endl;
//     return 0;
// }