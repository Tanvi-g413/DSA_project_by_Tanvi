# Recursive Postorder Traversal of a Binary Tree

## 1. Problem Statement

Write a recursive C++ program to perform postorder traversal of a binary tree representing an arithmetic expression. The program visits the left subtree first, followed by the right subtree, and finally the root node.

## 2. Objective

- To understand the concept and structure of a binary tree.
- To learn how arithmetic expressions are represented using binary trees.
- To implement postorder traversal using recursion in C++.
- To traverse the tree in Left–Right–Root order.
- To understand recursive functions and base conditions.
- To display the nodes of a binary tree in postorder sequence.
- To understand how postorder traversal represents an arithmetic expression in postfix notation.

## 3. Approach

A binary tree is created to represent the arithmetic expression "(A+B)*C". Each node stores a character and contains pointers to its left and right children.

A recursive function named "postorder()" is used to traverse the tree. If the current node is "NULL", the function returns. Otherwise, it recursively visits the left subtree, then the right subtree, and finally prints the current node's data.

The resulting traversal is "A B + C *", which represents the expression in postfix notation.

## 4. Complexity Analysis

Let "n" be the total number of nodes in the binary tree.

- Time Complexity: O(n), because each node is visited exactly once.
- Space Complexity: O(h) auxiliary space for the recursive call stack, where "h" is the height of the tree.
- Worst-Case Space Complexity: O(n), when the tree is skewed.
- Best-Case Space Complexity: O(log n) for a balanced binary tree.

## 5. Advantages

- Simple and easy to implement using recursion.
- Demonstrates the Left–Right–Root traversal technique.
- Helps understand binary tree structures and recursive function calls.
- Converts an expression tree into postfix notation.
- Provides a foundation for understanding expression evaluation and other tree operations.

## 6. Conclusion

Thus, recursive postorder traversal of a binary tree is successfully implemented using C++. The program visits the left subtree, followed by the right subtree, and finally the root node. It demonstrates the use of recursion in tree traversal and shows how an arithmetic expression tree can be represented in postfix notation.
