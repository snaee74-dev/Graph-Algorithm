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
