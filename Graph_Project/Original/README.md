# Village Road Construction Using Kruskal's Algorithm

## Problem Statement

Develop a C++ program to represent villages as vertices and proposed roads as weighted edges. Apply Kruskal's algorithm to connect the villages with minimum total road-building cost. Display the selected roads and determine whether all villages can be connected.

## Objective

To implement Kruskal's algorithm to find the Minimum Spanning Tree (MST) and minimize the total cost of connecting villages.

## Approach

1. Represent each village as a vertex and each proposed road as a weighted edge.
2. Sort all edges in ascending order of cost.
3. Select the minimum-cost edge that does not form a cycle.
4. Repeat until "V - 1" edges are selected or no more edges can be added.
5. Display the selected roads, total cost, and whether all villages are connected.

## Complexity

- Time Complexity: O(E log E), where E is the number of edges.
- Space Complexity: O(V + E), where V is the number of vertices and E is the number of edges.

## Conclusion

Kruskal's algorithm selects roads with minimum total construction cost and determines whether all villages can be connected. If the graph is disconnected, a spanning tree connecting every village is not possible.
