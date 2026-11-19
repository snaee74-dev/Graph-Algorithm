# Graph-Algorithm
Prim's___Dijkstra____Krushkal
Graph Network Optimization

#Problem Description

You are given a connected, undirected, weighted graph consisting of N vertices and M edges. Each vertex represents a location, and each edge represents a possible connection between two locations with an associated installation cost.

The goal is to develop a C program that analyzes the network and finds the most cost-effective way to connect all locations while also determining the shortest communication route between a given source and destination.

#The program performs the following tasks:

1. Minimum Spanning Tree (MST): Find the minimum-cost network that connects all vertices.
2. Shortest Path: Determine the shortest path between the given source and destination vertices.
3. Edge Removal Analysis: Remove a specified edge from the original graph and recalculate the minimum spanning tree and shortest path.
4. Connectivity Check: Check whether the graph remains connected after removing the specified edge. If the graph becomes disconnected, display an appropriate message.

#Input Format

- The first line contains two integers "N" and "M", representing the number of vertices and edges.
- The next "M" lines contain three integers "u", "v", and "w", representing an undirected edge and its weight.
- The next line contains the source and destination vertices.
- The final line specifies the edge that will be removed.

#Objective

To analyze graph connectivity, minimize network installation costs, calculate shortest communication routes, and observe how removing a connection affects the overall network.

#Programming Language

- C
