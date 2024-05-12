**Graph Algorithms Library**
This library provides a collection of algorithms for working with graphs in C++.
It includes algorithms for graph connectivity, cycle detection, bipartiteness, shortest path finding, and more.

**Table of Contents:**
1.Features
2.Installation
3.Usage
4.Documentation

**Features**

Graph Representation:
Description: Provides a class for representing and working with graphs efficiently.
Implementation: The graph representation class encapsulates the adjacency matrix representation of a graph. It includes methods for loading graphs, accessing adjacency information, counting vertices, and enumerating edges.


Connectivity:
Description: Determines whether a graph is connected, meaning that there is a path between every pair of vertices.
Implementation: This feature is implemented using a Breadth-First Search (BFS) algorithm. Starting from a vertex, BFS explores all reachable vertices, marking them as visited. If all vertices are visited, the graph is connected.

Cycle Detection:
Description: Identifies cycles in a graph, which are closed paths where a vertex is visited more than once.
Implementation: Cycle detection is performed using Depth-First Search (DFS). It explores each vertex and its neighbors, maintaining a stack to keep track of the visited vertices and checking for back edges to detect cycles.

Bipartiteness:
Description: Checks if a graph is bipartite, meaning its vertices can be divided into two disjoint sets such that no two vertices within the same set are adjacent.
Implementation: This feature utilizes graph coloring and BFS. It assigns colors to vertices in such a way that adjacent vertices have different colors. If a bipartition is possible, it returns the partition sets; otherwise, it indicates that the graph is not bipartite.

Shortest Path:
Description: Finds the shortest path between two vertices in a graph, i.e., the path with the minimum sum of edge weights.
Implementation: Shortest path computation is achieved using BFS. Starting from the source vertex, BFS explores neighboring vertices, updating the distance from the source. It maintains a parent array to reconstruct the shortest path once the destination vertex is reached.

Negative Cycle Detection:
Description: Detects negative weight cycles in a graph, which are cycles with a net negative weight.
Implementation: This feature utilizes the Bellman-Ford algorithm. It iteratively relaxes the edges of the graph, checking for any vertex whose distance can be further reduced. If a relaxation occurs after the last iteration, a negative weight cycle exists.

**Installation**
To use this library in your project, follow these steps:

Clone the repository to your local machine:
```
git clone https://github.com/your-username/graph-algorithms-library.git
```

By Using the Makefile
Building Executables:

To build the demo executable, run 'make demo'.
To build the test executable, run 'make test'.

Running Demos and Tests:

After building, you can run the demo executable with ./demo.
Similarly, you can run the test executable with ./test.
Running Code Analysis:

To run clang-tidy for code analysis, use 'make tidy'.
To run Valgrind for memory checking, use 'make valgrind'.
Cleaning Up:

To clean up object files and executables, run make clean.

Additional Tips
Ensure that your source files (*.cpp) and header files (*.hpp) are placed in the sources directory.
Update the CXXVERSION variable if you're using a different C++ standard.
Modify the CXXFLAGS variable to include additional compiler flags if needed.
Customize the tidy rule to include specific checks or exclude certain checks as per your project requirements.


**Usage**
To use the algorithms provided by this library, first create a graph object using the Graph class, then call the desired algorithm functions from the Algorithms class.

Example usage with a new main:
Include the necessary header files in your project:

```
#include "Algorithms.hpp"
#include "Graph.hpp"
```
Compile your project with the library:

```
clang++ -std=c++2a -Werror -Ipath/to/graph-algorithms-library/sources main.cpp -o ma
```

```
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <iostream>

int main() {
    // Create a graph
    ariel::Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
    graph.loadGraph(adjacencyMatrix);

    // Check if the graph is connected
    bool connected = ariel::Algorithms::isConnected(graph);
    std::cout << "Is the graph connected? " << (connected ? "Yes" : "No") << std::endl;

    // Find the shortest path between vertices 0 and 2
    std::string shortestPath = ariel::Algorithms::shortestPath(graph, 0, 2);
    std::cout << "Shortest path from vertex 0 to vertex 2: " << shortestPath << std::endl;

    return 0;
}
```
