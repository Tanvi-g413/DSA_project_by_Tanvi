###  Algorithm: Original Program — Kruskal’s Algorithm

Step 1: Start.

Step 2: Input the number of villages and roads .

Step 3: Store each road with its source village, destination village, and construction cost.

Step 4: Sort all roads in ascending order of construction cost.

Step 5: Initialize the parent array for all villages, set the total cost to 0, and selected roads count to 0.

Step 6: Select the road with the minimum cost.

Step 7: Check whether the selected road forms a cycle.

Step 8: If it does not form a cycle, add the road to the Minimum Spanning Tree (MST) and update the total cost and selected roads count. Otherwise, discard it.

Step 9: Repeat Steps 6–8 until roads are selected or all roads are checked.

Step 10: Display the selected roads and minimum total construction cost.

Step 11: If roads are selected, display that all villages are connected; otherwise, display that all villages cannot be connected.

Step 12: Stop.

