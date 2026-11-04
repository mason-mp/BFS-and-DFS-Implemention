#ifndef DFS_H
#define DFS_H

#include "SearchResults.h"
#include "Graph.h"

class DFS {
public:
    static SearchResults search(const Graph& graph, int start, int target);
};

#endif