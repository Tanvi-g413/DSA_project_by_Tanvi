###  Algorithm: Modified Program — A, B and C Combined

Step 1: Start.

Step 2: Input the number of villages and roads .

Step 3: Store each road with its source, destination, and weight.

Step 4: Input the source and destination of the edge to be updated and enter its new weight.

Step 5: Update the edge weight if the specified edge exists. Otherwise, retain the original weights.

Step 6: Sort all roads in ascending order of weight.

Step 7: Initialize the parent array, total cost to 0, and selected roads count to 0.

Step 8: Select the road with the minimum weight.

Step 9: Check whether adding the road forms a cycle.

Step 10: If no cycle is formed, add the road to the MST, update the total cost, and display the selected edge with its weight and running total cost. Otherwise, discard the road.

Step 11: Repeat Steps 8–10 until roads are selected or all roads are checked.

Step 12: Display all selected roads and the final minimum total construction cost.

Step 13: If roads are selected, display that a spanning tree can be formed and all villages are connected. Otherwise, display that the graph is disconnected and a spanning tree cannot be formed.

Step 14: Stop.
