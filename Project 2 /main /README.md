# Postorder Traversal of an Expression Tree in C++

 ## Problem Statement

Write a C++ program to construct a binary expression tree for the expression "(A+B)*C" and perform postorder traversal using recursion.

In postorder traversal, the nodes are visited in the following order:

Left Subtree → Right Subtree → Root

The program should display the postorder traversal of the expression tree and release the allocated memory after execution.

## Approach

1. Create a Node Structure: Define a binary tree node containing a character data field and pointers to the left and right child nodes.

2. Construct the Expression Tree: Create the root node "*", with "+" as its left child and "C" as its right child. The "+" node contains "A" as its left child and "B" as its right child.

3. Perform Postorder Traversal: Use a recursive function to:
   
   - Traverse the left subtree.
   - Traverse the right subtree.
   - Print the current root node.

4. Delete the Tree: Use a recursive function to delete all nodes and free the dynamically allocated memory.

5. Display the Output: Print the postorder traversal of the expression tree.



## complexity Analysis

Let "n" be the total number of nodes in the binary tree.

- Time Complexity: "O(n)" — Every node is visited once during postorder traversal. Deleting the tree also takes "O(n)" time.

- Space Complexity: "O(h)" auxiliary space for the recursive call stack, where "h" is the height of the tree. In the worst case, this is "O(n)".

For a balanced binary tree, the recursive stack space is "O(log n)".

## Conclusion

The program successfully constructs an expression tree for "(A+B)*C" and performs postorder traversal using recursion. It displays the output as "A B + C *", demonstrating the Left-Right-Root traversal technique. The program also deletes the tree to release dynamically allocated memory.
