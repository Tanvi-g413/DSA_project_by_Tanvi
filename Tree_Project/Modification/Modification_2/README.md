#  Recursive Evaluation of an Arithmetic Expression Tree

## 1. Problem Statement

Write a recursive C++ program to evaluate an arithmetic expression represented using a binary expression tree. The program should support addition, subtraction, multiplication, and division, and handle division-by-zero and invalid operators.

## 2. Objective

- To understand the structure of a binary expression tree.
- To evaluate arithmetic expressions using recursion.
- To perform arithmetic operations using tree nodes.
- To understand base conditions and recursive function calls.
- To handle division-by-zero and invalid operator errors.
- To calculate the final value of an arithmetic expression.

## 3. Approach

- Define a "Node" structure containing data, a left pointer, and a right pointer.
- Create a binary expression tree representing "(5 + 3) * 2".
- Define a recursive function named "evaluate()" to calculate the expression.
- Return zero if the current node is "nullptr".
- If the current node is a leaf node, convert its character into an integer and return its value.
- Recursively evaluate the left and right subtrees.
- Check the operator stored in the current node.
- Perform addition, subtraction, multiplication, or division as required.
- Check for division by zero and invalid operators.
- Return the calculated result and display the final answer.
- Use "deleteTree()" to release dynamically allocated memory.

## 4. Complexity Analysis

Let "n" be the number of nodes in the expression tree and "h" be its height.

- Time Complexity: O(n), because each node is visited once.
- Auxiliary Space Complexity: O(h), due to recursive function calls.
- Tree Construction: O(n), because each node is created once.
- Memory Complexity: O(n) for storing the expression tree.

## 5. Advantages

- Evaluates arithmetic expressions systematically.
- Uses recursion to simplify tree processing.
- Supports multiple arithmetic operators.
- Includes basic error handling for division by zero and invalid operators.
- Improves understanding of binary trees and recursive algorithms.

## 6. Applications

- Arithmetic expression evaluation.
- Expression trees in compiler design.
- Calculator applications.
- Mathematical expression processing.
- Learning recursion and tree-based data structures.

## 7. Sample Output

Expression: (5 + 3) * 2
Result: 16

## 8. Conclusion

Thus, the recursive evaluation of an arithmetic expression tree is implemented using C++. The program evaluates arithmetic operations by recursively processing the left and right subtrees and applying the operator at the root. It demonstrates the use of recursion, binary trees, arithmetic operations, and basic error handling.
