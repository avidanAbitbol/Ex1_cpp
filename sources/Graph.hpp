#pragma once

#include <vector>
#include <tuple> // For std::tuple

#ifndef CPP_EX4_GRAPH_HPP
#define CPP_EX4_GRAPH_HPP

namespace ariel {
    /**
     * @brief Class representing a graph.
     */
    class Graph {
    public:
        /**
         * @brief Default constructor.
         */
        Graph();

        /**
         * @brief Load the graph from an adjacency matrix.
         *
         * @param graph The adjacency matrix representing the graph.
         * @throw std::invalid_argument If the input matrix is not a square matrix.
         */
        void loadGraph(const std::vector<std::vector<int>>& graph);

        /**
         * @brief Print information about the graph.
         */
        void printGraph() const;

        /**
         * @brief Get the adjacency matrix of the graph.
         *
         * @return The adjacency matrix.
         */
        const std::vector<std::vector<int>>& getGraph() const;

        /**
         * @brief Get the number of vertices in the graph.
         *
         * @return The number of vertices.
         */
        std::size_t vertices() const;

        /**
         * @brief Get the adjacency list of a vertex.
         *
         * @param index The index of the vertex.
         * @return The adjacency list of the vertex.
         * @throw std::out_of_range If the index is out of range.
         */
        const std::vector<int>& adj(int index) const;

        /**
         * @brief Get the list of edges in the graph.
         *
         * @return The list of edges.
         */
        std::vector<std::tuple<int, int, int>> edges() const;

        /**
         * @brief Count the total number of edges in the graph.
         *
         * @return The total number of edges.
         */
        int countEdges() const;

    private:
        std::vector<std::vector<int>> graph; // Adjacency matrix
        std::size_t numVertices; // Number of vertices

        /**
         * @brief Check if a given matrix is square (has the same number of rows and columns).
         *
         * @param matrix The matrix to check.
         * @return True if the matrix is square, false otherwise.
         */
        bool isSquareMatrix(const std::vector<std::vector<int>>& matrix) const;
    };
} // namespace ariel

#endif //CPP_EX4_GRAPH_HPP
