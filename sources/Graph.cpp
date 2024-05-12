#include "Graph.hpp"
#include <iostream>
#include <stdexcept>
#include <unordered_set>

namespace ariel {

    // Constructor
    Graph::Graph() : numVertices(0) {}

    // Load the graph from an adjacency matrix
    void Graph::loadGraph(const std::vector<std::vector<int>>& graph) {
        // Check if the graph is a square matrix
        for (const auto& row : graph) {
            if (row.size() != graph.size()) {
                throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
            }
        }

        // Assign the graph and update the number of vertices
        this->graph = graph;
        this->numVertices = graph.size();
    }

    // Print information about the graph
    void Graph::printGraph() const {
        std::cout << "Graph with " << numVertices << " vertices and " << countEdges() << " edges." << std::endl;
    }

    // Get the adjacency matrix of the graph
    const std::vector<std::vector<int>>& Graph::getGraph() const {
        return graph;
    }

    // Get the number of vertices in the graph
    std::size_t Graph::vertices() const {
        return numVertices;
    }

    // Get the adjacency list of a vertex
    const std::vector<int>& Graph::adj(int index) const {
        if (index < 0 || static_cast<std::size_t>(index) >= numVertices) {
            throw std::out_of_range("Index out of range");
        }
        return graph[static_cast<std::size_t>(index)];
    }

    // Get the list of edges in the graph
    std::vector<std::tuple<int, int, int>> Graph::edges() const {
        std::vector<std::tuple<int, int, int>> edgeList;
        std::unordered_set<std::string> uniqueEdges;

        for (std::size_t i = 0; i < numVertices; ++i) {
            for (std::size_t j = 0; j < numVertices; ++j) {
                if (graph[i][j] != 0) {
                    std::string edge = std::to_string(i) + "-" + std::to_string(j);
                    std::string reverseEdge = std::to_string(j) + "-" + std::to_string(i);

                    // Avoid duplicate edges
                    if (uniqueEdges.find(reverseEdge) == uniqueEdges.end()) {
                        edgeList.emplace_back(i, j, graph[i][j]);
                        uniqueEdges.insert(edge);
                    }
                }
            }
        }
        return edgeList;
    }

    // Count the total number of edges in the graph
    int Graph::countEdges() const {
        return edges().size();
    }

    // Check if a given matrix is square (has the same number of rows and columns)
    bool Graph::isSquareMatrix(const std::vector<std::vector<int>>& matrix) const {
        size_t n = matrix.size();
        for (const auto& row : matrix) {
            if (row.size() != n) return false;
        }
        return true;
    }

} // namespace ariel
