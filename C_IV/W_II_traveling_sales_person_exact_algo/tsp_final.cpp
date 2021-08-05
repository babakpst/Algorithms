#include "tsp.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <memory>
#include <sstream>
#include <fstream>

class CoOrd
{
public:
    CoOrd(float x=0.0, float y=0.0) : x_val{x}, y_val{y} {}

    float x_val;
    float y_val;
};

using std::cout;

TSP::TSP()
{ }

void TSP::ReadInputFile(const string& sInputFile)
{
    std::ifstream ips(sInputFile);

    if(! ips.is_open())
        return;

    string sLine;

    getline(ips, sLine);

    std::stringstream ssFLine(sLine);

    ssFLine >> num_vertices;

    paths_arr.resize(num_vertices);
    for(auto& elem : paths_arr)
        elem.resize(num_vertices);

    std::vector<CoOrd> vertex_coord(num_vertices);
    auto nIndex {0};

    while(getline(ips, sLine))
    {
        std::stringstream ssCoOrd(sLine);

        float x_val {0.0}, y_val {0.0};

        ssCoOrd >> x_val >> y_val;

        vertex_coord[nIndex++] = CoOrd {x_val, y_val};
    }
    ips.close();


    // generate the path matrix
    for(int i = 0; i < num_vertices; i++)
    {
        for(int j = 0; j < num_vertices; j++)
        {
            if(i == j)
            {
                paths_arr[i][j] = 0;
                continue;
            }

            float path_len = sqrt( pow((vertex_coord[i].x_val - vertex_coord[j].x_val), 2)
                                 + pow((vertex_coord[i].y_val - vertex_coord[j].y_val), 2) );

            paths_arr[i][j] = (path_len);
        }
    }

   results_arr.resize(static_cast<int>( pow(2, static_cast<float>(num_vertices-1)) ));

   for(auto& elem : results_arr)
      elem.resize(num_vertices-1, std::numeric_limits<int>::max());

    return;
}

float TSP::GetTSPMinPath()
{
   TSPBitSet vertices_bits;

   // this loop controls the size of the vertex combinations
   for(int subset_size = 1; subset_size <= num_vertices-1; subset_size++)
   {
      std::cout << subset_size << "/" <<num_vertices-1<< std::endl;
      std::vector<bool> v_comb(num_vertices-1);
      std::fill(v_comb.begin(), v_comb.begin() + subset_size, true);

      // each iteration generates a new combination of subset_size
      do 
      {
          vertices_bits.reset();
          for (int i = 0; i < num_vertices-1; ++i) 
          {
              if (v_comb[i]) {
                  vertices_bits.set(i);
              }
          }

          for(std::size_t i=0; i < vertices_bits.size(); ++i)
          {
             if(vertices_bits.test(i)) // this bit is set, means this vertex is in combination
             {
                TSPBitSet vertices_wo_i {vertices_bits};
                vertices_wo_i.reset(i);

                auto prev_soln_idx = vertices_wo_i.to_ulong();

                // now we can go through all bits in vertices_wo_i
                // for each vertex, use prev_soln_idx and vertex index to get previous solution
                // add the path from vertex to i and maintain min

                float soln_min_path = std::numeric_limits<int>::max();

                if(prev_soln_idx == 0)
                {
                    // this means the first iteration, so use the values from paths_arr
                    soln_min_path = paths_arr[0][i+1];
                }
                else
                {
                    for(std::size_t min_vertex=0; min_vertex < vertices_wo_i.size(); ++min_vertex)
                    {
                        if(vertices_wo_i.test(min_vertex))
                       {
                            if(results_arr[prev_soln_idx][min_vertex] != std::numeric_limits<int>::max())
                            {
                                auto this_min_path = results_arr[prev_soln_idx][min_vertex] + paths_arr[min_vertex+1][i+1];
                                if(this_min_path < soln_min_path)
                                    soln_min_path = this_min_path;
                            }
                       }
                    }
                }
                results_arr[vertices_bits.to_ulong()][i] = soln_min_path;
             }
          }
      } while (std::prev_permutation(v_comb.begin(), v_comb.end()));
   }

 
   std::cout << "done with the main loop \n";
 
   // vertices_bits has the last combination, which will have all vertices
   float final_min_path = std::numeric_limits<int>::max();
   for(auto final_loop = 0; final_loop < num_vertices-1; final_loop++)
   {


       std::cout << final_loop << "/" <<num_vertices-1<< std::endl;

       auto close_loop_path = results_arr[vertices_bits.to_ulong()][final_loop] + paths_arr[final_loop+1][0];
       if(close_loop_path < final_min_path)
           final_min_path = close_loop_path;
   }
//   std::cout << "Final Min path: " << final_min_path << "\n";

   return final_min_path;
}

int main()
{
    std::unique_ptr<TSP> pTSP {new TSP};

    //pTSP->ReadInputFile("tsp_5.txt");
    //pTSP->ReadInputFile("tsp_9.txt");
    pTSP->ReadInputFile("tsp.txt");
    cout << "Min Path is : " << pTSP->GetTSPMinPath() << "\n";

    return 0;
}
