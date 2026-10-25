# Village Road Construction Using Kruskal's Algorithm 

## Problem Statement

Modify the Kruskal's algorithm program to update edge weights, display selected edges with running total cost, and detect disconnected graphs.

## Objective

To enhance Kruskal's algorithm by supporting edge weight updates, tracking cumulative cost, and checking graph connectivity.

## Approach

1. Input villages and weighted roads.
2. Update the cost of a specified edge and apply Kruskal's algorithm again.
3. Sort edges by increasing weight.
4. Select edges that do not form a cycle and display each edge with its weight and running total cost.
5. Check whether all villages are connected and a spanning tree can be formed.

## Complexity

- Time Complexity: O(E log E) for sorting and processing edges.
- Space Complexity: O(V + E) for storing vertices, edges, and parent information.

## Conclusion

The modified program updates road costs, displays the running total construction cost, and detects disconnected graphs to determine whether a minimum spanning tree can be formed.
