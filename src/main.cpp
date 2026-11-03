#include <iostream>
#include <random>
#include "Graph.h"
#include "SearchResults.h"
#include "GraphVisual.h"
#include "BFS.h"


//Right now main just makes a temp graph to test
int main() {
    Graph graph;
    //make vertices
    for (int i = 1; i < 101; i++) {
        cout << "Vertex: " << i << endl;
        graph.addNode(i);
    }
    //form edges
    std::random_device seed;
    std::mt19937 rng(seed());
    std::uniform_int_distribution<int> gen(1, 100); // uniform, unbiased
    for (int i = 1; i < 100; i++) {
        cout << "From: " << i << endl;
        //int to = gen(rng);
        int to = i+1;
        //while (to == i) {
          //  to = gen(rng);
        //}
        //cout << "To: " << to << endl;
        graph.addEdge(i, to);
    }

    int from = gen(rng);
    int to = gen(rng);
    while (from == to) {//reroll if same
        to = gen(rng);
    }
    SearchResults searchResults = BFS::search(graph, from, to);
    cout << "Search successful" << endl;
    std::unordered_map<int, std::vector<int>> adjList = graph.getAdjacencyList();
    cout << "Got adjlist" << endl;
    visualizeGraph(adjList, searchResults);
    cout << "Graph visualized!" << endl;
    return 0;
}