#ifndef BFS_AND_DFS_IMPLEMENTION_GRAPHVISUAL_H
#define BFS_AND_DFS_IMPLEMENTION_GRAPHVISUAL_H

#include <iostream>
#include "Bridges.h"
#include "GraphAdjList.h"
#include "DataSource.h"
#include "SearchResults.h"

void convertGraph(std::unordered_map<int, std::vector<int>> &graph, bridges::GraphAdjList<int, int> *convertedGraph);
void visualizeGraph(std::unordered_map<int, std::vector<int>> &graph, SearchResults &results);

#endif //BFS_AND_DFS_IMPLEMENTION_GRAPHVISUAL_H