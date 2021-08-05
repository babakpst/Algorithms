#include <vector>
#include <bitset>
#include <string>

const int c_num_bits = 24;

using TSPArr = std::vector<std::vector<float>>;
using TSPPaths = std::vector<std::vector<float>>;
using TSPBitSet = std::bitset<c_num_bits>;
using std::string;

class TSP
{
public:
    TSP();
    void ReadInputFile(const string& sInputFile);
    float GetTSPMinPath();

private:
   TSPPaths paths_arr;
   int num_vertices {0};
   TSPArr results_arr;

};
