#include <iostream>
#include <string>
#include <vector>
#include "GraphVisual.h"
#include "SearchResults.h"

using namespace std;

#include "Bridges.h"
#include "GraphAdjList.h"
#include "DataSource.h"

using namespace bridges;

//the BRIDGES bacon number template was used as a starting template for this visualizer

void convertGraph(std::unordered_map<int, std::vector<int>> &graph, GraphAdjList<int, int> *convertedGraph) {
  //convert vertices
  for (const auto &itr : graph) {
    int vertex = itr.first;
    convertedGraph->addVertex(vertex);
    convertedGraph->getVertex(vertex)->setLabel(to_string(vertex));
    convertedGraph->getVertex(vertex)->setColor(Color("black"));
  }

  //convert edges
  for (const auto &itr : graph) {
    int from = itr.first;
    //loop through neighbors
    for (int to : itr.second) {
      convertedGraph->addEdge(from, to);
      convertedGraph->getLinkVisualizer(from, to)->setColor(Color("red"));
    }
  }
}

void visualizeGraph(std::unordered_map<int, std::vector<int>> &graph, SearchResults &results) {
  //initialize BRIDGES
  Bridges bridges(103, "CountMakkula", "1010610796120");
  bridges.setTitle("DFS vs BFS");
  bridges.setDescription("Shows the difference between a DFS and a BFS for two given nodes.");
  std::cout << "Initialized BRIDGES" << std::endl;

  //set up and convert graph
  GraphAdjList<int> bridgesGraph;
  convertGraph(graph, &bridgesGraph);
  std::cout << "Converted graph" << std::endl;

  //if the search was successful, print out the path
  if (results.found) {
    const std::vector<int> &path = results.path;
    for (int i = 1; i < path.size(); i++) {
      int vertex = path[i-1];
      cout << "Vertex: " << vertex << endl;
      cout << "Next: " << path[i] << endl;
      bridgesGraph.getVisualizer(vertex)->setColor(Color("blue"));
      bridgesGraph.getVisualizer(vertex)->setSize(30.0);

      bridgesGraph.getLinkVisualizer(vertex, path[i])->setColor(Color("blue"));
      bridgesGraph.getLinkVisualizer(vertex, path[i])->setThickness(4.0);
    }
  std::cout << "Colored path" << endl;
  }

  //generate visual
  bridges.setDataStructure(&bridgesGraph);
  bridges.visualize();
}
