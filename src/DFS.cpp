#include "DFS.h"
#include "Graph.h"
#include "SearchResults.h"

#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

SearchResults DFS::search(const Graph& graph, int start, int target) {

    auto startTime = chrono::high_resolution_clock::now();

    SearchResults result;

    if (!graph.hasNode(start) || !graph.hasNode(target)) {
        auto endTime = chrono::high_resolution_clock::now();

        result.runtimeMs = chrono::duration<double, milli>(endTime - startTime).count();

        return result;
    }

    unordered_set<int> visited;
    unordered_map<int, int> parent;

    vector<pair<int, size_t>> stack;

    visited.insert(start);
    result.visitedOrder.push_back(start);

    stack.push_back({start, 0});

    while (!stack.empty()) {

        int current = stack.back().first;

        if (current == target) {
            result.found = true;
            break;
        }

        const vector<int>& neighbors = graph.getNeighbors(current);

        size_t& nextNeighbor = stack.back().second;
        if (nextNeighbor >= neighbors.size()) {
            stack.pop_back();
            continue;
        }

        int neighbor = neighbors[nextNeighbor];

        nextNeighbor++;

        result.edgesExamined++;

        if (visited.find(neighbor) == visited.end()) {

            visited.insert(neighbor);

            parent[neighbor] = current;

            result.visitedOrder.push_back(neighbor);

            stack.push_back({neighbor, 0});
        }
    }

    result.nodesVisited = result.visitedOrder.size();

    if (result.found) {

        int current = target;

        while (current != start) {
            result.path.push_back(current);
            current = parent[current];
        }

        result.path.push_back(start);

        reverse(result.path.begin(), result.path.end());
    }

    auto endTime = chrono::high_resolution_clock::now();

    result.runtimeMs =
        chrono::duration<double, milli>(endTime - startTime).count();

    return result;
}