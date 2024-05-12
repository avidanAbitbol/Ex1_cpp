/*
 * Demo program for Exercise 2.
 * Author: Benjamin Saldman.
 */

#include "sources/Graph.hpp"
#include "sources/Algorithms.hpp"
using ariel::Algorithms;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{
    ariel::Graph g;

    // Case 1: Simple Connected Graph
    cout << "Case 1: Simple Connected Graph" << endl;
    vector<vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g.loadGraph(graph1);

    g.printGraph();
    cout << "Is Connected: " << Algorithms::isConnected(g) << endl;
    cout << "Shortest Path (0 to 2): " << Algorithms::shortestPath(g, 0, 2) << endl;
    cout << "Contains Cycle: " << Algorithms::isContainsCycle(g) << endl;
    cout << "Is Bipartite: " << Algorithms::isBipartite(g) << endl;
    cout << endl;

    // Case 2: Non-Connected Graph with a Cycle
    cout << "Case 2: Non-Connected Graph with a Cycle" << endl;
    vector<vector<int>> graph2 = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);

    g.printGraph();
    cout << "Is Connected: " << Algorithms::isConnected(g) << endl;
    cout << "Shortest Path (0 to 4): " << Algorithms::shortestPath(g, 0, 4) << endl;
    cout << "Contains Cycle: " << Algorithms::isContainsCycle(g) << endl;
    cout << "Is Bipartite: " << Algorithms::isBipartite(g) << endl;
    cout << endl;

    // Case 3: Simple Connected Weighted Graph
    cout << "Case 3: Simple Connected Weighted Graph" << endl;
    vector<vector<int>> graph3 = {
            {0, 1, 0, 0, 3},
            {1, 0, 2, 0, 0},
            {0, 2, 0, 4, 0},
            {0, 0, 4, 0, 5},
            {3, 0, 0, 5, 0}};
    g.loadGraph(graph3);

    g.printGraph();
    cout << "Is Connected: " << Algorithms::isConnected(g) << endl;
    cout << "Shortest Path (0 to 4): " << Algorithms::shortestPath(g, 0, 4) << endl;
    cout << "Contains Cycle: " << Algorithms::isContainsCycle(g) << endl;
    cout << "Is Bipartite: " << Algorithms::isBipartite(g) << endl;
    cout << endl;

    // Case 4: Invalid Graph (Non-Square Matrix)
    cout << "Case 4: Invalid Graph (Non-Square Matrix)" << endl;
    vector<vector<int>> graph4 = {
            {0, 1, 2, 0},
            {1, 0, 3, 0},
            {2, 3, 0, 4},
            {0, 0, 4, 0},
            {0, 0, 0, 5}};
    try
    {
        g.loadGraph(graph4);
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl;
    }
    cout << endl;

    // Case 5: Fully Connected Graph
    cout << "Case 5: Fully Connected Graph" << endl;
    vector<vector<int>> graph5 = {
            {0, 1, 1, 1},
            {1, 0, 1, 1},
            {1, 1, 0, 1},
            {1, 1, 1, 0}};
    g.loadGraph(graph5);

    g.printGraph();
    cout << "Is Connected: " << Algorithms::isConnected(g) << endl;
    cout << "Shortest Path (0 to 3): " << Algorithms::shortestPath(g, 0, 3) << endl;
    cout << "Contains Cycle: " << Algorithms::isContainsCycle(g) << endl;
    cout << "Is Bipartite: " << Algorithms::isBipartite(g) << endl;
    cout << endl;

    // Case 6: Sparse Graph
    cout << "Case 6: Sparse Graph" << endl;
    vector<vector<int>> graph6 = {
            {0, 1, 0, 0, 0},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 1, 0},
            {0, 0, 1, 0, 1},
            {0, 0, 0, 1, 0}};
    g.loadGraph(graph6);

    g.printGraph();
    cout << "Is Connected: " << Algorithms::isConnected(g) << endl;
    cout << "Shortest Path (0 to 4): " << Algorithms::shortestPath(g, 0, 4) << endl;
    cout << "Contains Cycle: " << Algorithms::isContainsCycle(g) << endl;
    cout << "Is Bipartite: " << Algorithms::isBipartite(g) << endl;
    cout << endl;

    // Case 7: Graph with Multiple Components
    cout << "Case 7: Graph with Multiple Components" << endl;
    vector<vector<int>> graph7 = {
            {0, 1, 0, 0, 0},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 1, 0, 1},
            {0, 0, 1, 1, 0}};
    g.loadGraph(graph7);

    g.printGraph();
    cout << "Is Connected: " << Algorithms::isConnected(g) << endl;
    cout << "Shortest Path (0 to 4): " << Algorithms::shortestPath(g, 0, 4) << endl;
    cout << "Contains Cycle: " << Algorithms::isContainsCycle(g) << endl;
    cout << "Is Bipartite: " << Algorithms::isBipartite(g) << endl;
    cout << endl;

    return 0;
}
