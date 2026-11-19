# Graph-Algorithm
Prim's___Dijkstra____Krushkal
Graph Network Optimization
Graph Network Optimization using Prim's, Kruskal's & Dijkstra's Algorithms

A C program that analyzes a connected, undirected, weighted graph to find the minimum-cost network, calculate the shortest path between two vertices, and evaluate the impact of removing a specific edge.

Input

N M
u v w
u v w
...
Source Destination
U V

- N = Number of vertices
- M = Number of edges
- u, v = Connected vertices
- w = Edge weight
- Source, Destination = Shortest path endpoints
- U, V = Edge to be removed

Algorithms Used

- Prim's Algorithm: Finds the Minimum Spanning Tree (MST) with minimum total cost.
- Kruskal's Algorithm: Finds the MST using edge sorting and Disjoint Set Union (DSU).
- Dijkstra's Algorithm: Finds the shortest path between the source and destination.

Program Operations

- Calculate MST using Prim's Algorithm.
- Calculate MST using Kruskal's Algorithm.
- Find the shortest path using Dijkstra's Algorithm.
- Remove a specified edge from the original graph.
- Recalculate MST and shortest path after edge removal.
- Check graph connectivity and detect disconnection.

Output

- Prim's MST and total cost.
- Kruskal's MST and total cost.
- Shortest path and distance.
- Updated MST after edge removal.
- Updated shortest path after edge removal.
- Connectivity status and appropriate messages if the graph becomes disconnected.

Time & Space Complexity

Let V = Number of vertices and E = Number of edges.

Algorithm| Time Complexity| Extra Space
Prim's| O(V²)| O(V)
Kruskal's| O(E log E)| O(V + E)
Dijkstra's| O(V²)| O(V)
Connectivity Check (DFS)| O(V + E)| O(V)

Notes:

- Prim's Algorithm builds an MST by repeatedly selecting the minimum-weight edge connecting a visited vertex to an unvisited vertex.
- Kruskal's Algorithm sorts edges and uses DSU to avoid cycles while building the MST.
- Dijkstra's Algorithm calculates the shortest path using non-negative edge weights.
- After removing an edge, all required algorithms are executed again on the modified graph.
- If the removed edge disconnects the graph, an MST cannot be formed for all vertices, and the program displays an appropriate message.

Advantages

- Minimizes total network installation cost.
- Compares two MST algorithms.
- Finds the shortest communication route.
- Identifies the impact of connection failure.
- Detects network disconnection.
- Helps understand practical applications of graph algorithms.

Applications

- Computer network design.
- Road and transportation networks.
- Telecommunication systems.
- Electrical power distribution.
- Network infrastructure planning.

Programming Language

C
