#include "isolver.hpp"

#include <vector>

namespace solver
{

using Array = std::vector<uint64_t>;

class TicketSolver : public ISolver {
public:
  std::string Solve(const std::string& input) override;

private:
  uint64_t FindLuckyTickets(int n);
  Array FillNextArray(const Array& arr);
};

} // namespace solver