#include "doctest.h"
#include "sources/Algorithms.hpp"
#include "sources/Graph.hpp"

using namespace std;
using namespace ariel;
//working,0,failure,negative,big,small,edge cases.
TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
            {0, 1, 0, 0, 1},
            {1, 0, 1, 1, 0},
            {0, 1, 0, 0, 1},
            {0, 1, 0, 0, 0},
            {1, 0, 1, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 3}, B={1, 4}");
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}
TEST_CASE("Test disconnected graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 0},
            {0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}
TEST_CASE("Test shortest path between non-existent vertices")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 5) == "-1");
}
TEST_CASE("Test negative weight cycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {0, 0, -1},
            {-1, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::negativeCycle(g) == true);
}
TEST_CASE("Test large graph")
{
    ariel::Graph g;
    // Create a large graph (e.g., 1000 vertices and edges)
    vector<vector<int>> graph(1000, vector<int>(1000, 0)); // Initialize with 0s
    // Add edges to create a connected graph or other specific patterns
    // Load the graph into the graph object
    g.loadGraph(graph);
    // Test algorithms on the large graph
    CHECK(ariel::Algorithms::isConnected(g) == false);
}
TEST_CASE("Test graph with self-loops")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}};
    g.loadGraph(graph);
    // Test algorithm behavior with self-loops
    CHECK(ariel::Algorithms::isConnected(g) == false);
}
TEST_CASE("Test graph with negative weights")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 1, -2},
            {1, 0, 1},
            {-2, 1, 0}};
    g.loadGraph(graph);
    // Test algorithm behavior with negative weights
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->2");
}
TEST_CASE("Test graph with all vertices having self-loops")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}};
    g.loadGraph(graph);
    // Test algorithm behavior with all vertices having self-loops
    CHECK(ariel::Algorithms::isConnected(g) == false);
}
TEST_CASE("Test graph with multiple cycles")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 1, 1, 0},
            {1, 0, 0, 1},
            {1, 0, 0, 1},
            {0, 1, 1, 0}};
    g.loadGraph(graph);
    // Test algorithm behavior with multiple cycles
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}
TEST_CASE("Test graph with multiple negative weight cycles")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, -1, 0},
            {-1, 0, 1},
            {0, 1, 0}};
    g.loadGraph(graph);
    // Test algorithm behavior with multiple negative weight cycles
    CHECK(ariel::Algorithms::negativeCycle(g) == false);
}
TEST_CASE("Test graph with a single vertex")
{
    ariel::Graph g;
    vector<vector<int>> graph = {{0}};
    g.loadGraph(graph);
    // Test algorithm behavior with a single vertex
    CHECK(ariel::Algorithms::isConnected(g) == true);
}
TEST_CASE("Test graph with all vertices connected to one vertex")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 1, 1, 1},
            {1, 0, 0, 0},
            {1, 0, 0, 0},
            {1, 0, 0, 0}};
    g.loadGraph(graph);
    // Test algorithm behavior with all vertices connected to one vertex
    CHECK(ariel::Algorithms::isConnected(g) == true);
}
TEST_CASE("Test graph with no edges")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}
TEST_CASE("Test graph with no edges")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}
TEST_CASE("Test graph with a cycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {0, 0, 1},
            {1, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}
TEST_CASE("Test graph with a cycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {0, 0, 1},
            {1, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}
TEST_CASE("Test disconnected graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 0},
            {0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}
TEST_CASE("Test graph with negative edge weights")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, -1, 0},
            {-1, 0, 1},
            {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");
}
