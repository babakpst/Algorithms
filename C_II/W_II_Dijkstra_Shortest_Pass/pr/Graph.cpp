/*

Babak Poursartip
05/8/2019

Assignment II, course II

*/

#include "Graph.h"

//=================================================================================================
Graph::Graph():numVertices(0), numEdges(0), FileName(" "){
  std::cout << "\n Creating graph with default values ... \n";
}

//=================================================================================================
Graph::Graph(int numVertices, std::string FileName):numVertices{numVertices}, FileName{FileName}{
  std::cout << "\n Creating the graph object ... \n";
  edges = new std::list <std::pair<int, int>>[numVertices];
  ShortestDistance.resize(numVertices,INT_MAX);
}

//=================================================================================================
void Graph::readGraph(){
  std::cout << "\n Reading graph from file: " << FileName << "\n";

  // open the input file
  std::cout << " Opening the input file ... \n";
  std::ifstream inputFile(FileName);
  
  std::string line;
  std::string temp;
  int count = 0; // counts number of vertices in the file
    while (std::getline(inputFile, line)){
      count++;
      std::cout << "lineaa: " << line.at(line.length()-1) << "z\n";
      //if (line.at(line.length()-1) == "\0")       std::cout << "yes yes\n";
      line.pop_back();
      std:: stringstream iss(line);

      std::cout << "line: " << line << "\n";


      int src;    // the vertix no (from)- source
      int dest;   // the vertix no (to)- destination
      int weight; // the weight of the edge

      std::getline(iss, temp, ' ');
      src = std::stoi(temp);

      std::cout << " ---reading vertix: " << src << "\n";
     
        while (std::getline(iss, temp,',')){
          dest = std::stoi(temp);
          std::getline(iss, temp, ' ');
          weight = std::stoi(temp);
          std::cout << "reading " << src << " " << dest << " " << weight << "\n";
          if (src > dest) addEdge(src-1, dest-1, weight);
        }
    }

  inputFile.close();
  std::cout << " read the graph from the input file, successfully! \n";
}

//=================================================================================================
void Graph::addEdge(int src, int dest, int weight){
  edges[src].push_back(std::make_pair(dest, weight));
  edges[dest].push_back(std::make_pair(src, weight));
}

//=================================================================================================
void Graph::printGraph(){
  for (int i=0; i<numVertices; ++i){
    std::cout << " vertix: " << i << "\n";
      for (std::list<std::pair<int,int>>:: iterator itr=edges[i].begin(); itr!=edges[i].end(); ++itr){
        std::cout << " src: " << i << " dest: "<<(*itr).first <<" weight: "<< (*itr).second <<"\n";
    }
}
}


// ================================================================================================
void Graph::findShortestPath(int source){

  std::cout << " Finding the shortest path of the weighted graph ... \n ";

    // Holds the processed vertices
  std::set<std::pair <int, int> > ProcessedVertices;

  source--; // numbers start from zero
  // set the distance of source to zero
  ShortestDistance[source] = 0;
 
  ProcessedVertices.insert(std::make_pair(0, source));

  // searching for the shortest path
  while (!ProcessedVertices.empty()){

    // The first vertex in Set is the minimum distance vertex, extract it from set. 
    std::pair<int, int> tmp = *(ProcessedVertices.begin()); 
    ProcessedVertices.erase(ProcessedVertices.begin()); 

    //vertex label is stored in second of pair (it has to be done this way to keep the vertices 
    // sorted distance (distance must be first item in pair) 
    int u = tmp.second; 

    // 'i' is used to get all adjacent vertices of a vertex 
    std::list< std::pair<int, int> >::iterator i; 
    for (i = edges[u].begin(); i != edges[u].end(); ++i) 
    { 
        // Get vertex label and weight of current adjacent of u. 
        int v = (*i).first; 
        int weight = (*i).second; 

        //  If there is shorter path to v through u. 
        if (ShortestDistance[v] > ShortestDistance[u] + weight) 
        { 
            /*  If distance of v is not INF then it must be in 
                our set, so removing it and inserting again 
                with updated less distance.   
                Note : We extract only those vertices from Set 
                for which distance is finalized. So for them,  
                we would never reach here.  */
            if (ShortestDistance[v] != INT_MAX) 
            ProcessedVertices.erase(ProcessedVertices.find(std::make_pair(ShortestDistance[v],v))); 

            // Updating distance of v 
            ShortestDistance[v] = ShortestDistance[u] + weight; 
            ProcessedVertices.insert(std::make_pair(ShortestDistance[v], v)); 
        } 
    } 


  }

}


// ================================================================================================
void Graph::printShortestDistance(){
std::cout << " Here are the shortest distances to the source: \n";
for (int i = 0; i<numVertices; ++i) 
           std::cout << " vertix: " << i+1 << " : " << ShortestDistance[i] << "\n";


}
