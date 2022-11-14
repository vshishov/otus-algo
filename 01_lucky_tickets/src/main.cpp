#include "tester.hpp"
#include "ticket_solver.hpp"

int main(int argc, char** argv) {
    tester::Tester tester;
    tester.Run(std::make_shared<solver::TicketSolver>(), argv[1]);
    return 0;
}
