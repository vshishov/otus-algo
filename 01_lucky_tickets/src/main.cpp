#include <iostream>

#include "tester.hpp"
#include "ticket_solver.hpp"


int get_sum_digits(int value) {
    int sum = 0;
    while (value > 0) {
        sum += value % 10;
        value /= 10;
    } 
    return sum;
}

int recurse(int N, int sumA=0, int sumB=0) {
    int count = 0;

    if (N == 0) {
        if (sumA == sumB) {
            return 1;
        }
        return 0;
    }

    for (int a = 0; a < 10; ++a) 
        for (int b = 0; b < 10; ++b) {
            count += recurse(N - 1, sumA + a, sumB + b);
        }

    return count;
}

int main(int argc, char** argv) {

    tester::Tester tester;

    tester.Run(std::make_shared<solver::TicketSolver>(), argv[1]);
    
    return 0;
}
