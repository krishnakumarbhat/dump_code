#include "highfive/highfive.hpp"
#include <numeric>
#include <vector>

int main()
{
   HighFive::File file("foo.h5", HighFive::File::Truncate);
   std::vector<int> data(50);
   std::iota(data.begin(), data.end(), 0);
   file.createDataSet("grp/data", data);
}
