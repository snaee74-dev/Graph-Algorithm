# Graph Algorithms: MST and Shortest Path (CSE 208 Lab Report 01)

A C program that works on a connected, undirected, weighted graph. It finds the minimum cost network using Prim's and Kruskal's algorithms, finds the cheapest route using Dijkstra's algorithm, and then repeats everything after one connection becomes unavailable.

## Features
- Minimum cost network (MST) using **Kruskal's Algorithm** (with Union-Find)
- Minimum cost network (MST) using **Prim's Algorithm**
- Shortest path from source to destination using **Dijkstra's Algorithm**
- Source-to-destination path traced inside each MST using **DFS**
- Edge removal: the given connection is deleted and all three algorithms run again
- Prints `Not Possible` if removing the connection disconnects the source from the destination

## Input Format (graph.txt)
```
N M
u v w        (M lines, undirected edge with positive weight)
source destination
removeU removeV
```
- N = number of vertices (numbered 0 to N-1)
- M = number of edges

## How to Run
```
gcc main.c -o main
./main
```
Keep `graph.txt` in the same folder as `main.c`.

## Sample Input and Output

### Case 1
**Input**
```
6 8
0 2 2
2 3 2
0 1 2
1 3 2
3 5 2
4 5 4
0 4 5
0 5 5
0 5
3 5
```
**Output**
```
Shortest Path: 0 -> 5 (Cost: 5)
Kruskal Path: 0 -> 2 -> 3 -> 5 (Cost: 6)
Prim Path: 0 -> 1 -> 3 -> 5 (Cost: 6)
After Removing Edge (3,5):
Updated Shortest Path: 0 -> 5 (Cost: 5)
Updated Kruskal Path: 0 -> 4 -> 5 (Cost: 9)
Updated Prim Path: 0 -> 4 -> 5 (Cost: 9)
```

### Case 2
**Input**
```
4 3
0 1 2
1 2 3
2 3 4
0 3
1 2
```
**Output**
```
Shortest Path: 0 -> 1 -> 2 -> 3 (Cost: 9)
Kruskal Path: 0 -> 1 -> 2 -> 3 (Cost: 9)
Prim Path: 0 -> 1 -> 2 -> 3 (Cost: 9)
After Removing Edge (1,2):
Updated Shortest Path: Not Possible
Updated Kruskal Path: Not Possible
Updated Prim Path: Not Possible
```

## Time & Space Complexity

| Part | Time | Extra Space |
|---|---|---|
| Dijkstra | O(V^2) | O(V) |
| Prim | O(V^2) | O(V) |
| Kruskal | O(E log E) | O(V + E) |
| DFS (path in MST) | O(V^2) | O(V^2) |
| Edge removal | O(E) | O(E) |

## Notes
- Prim's and Kruskal's can give different MSTs when edge weights are equal, so the MST path can differ from the shortest path (see Case 1).
- The graph is stored as an adjacency matrix, so an undirected edge is removed by setting both `graph[u][v]` and `graph[v][u]` to 0.


