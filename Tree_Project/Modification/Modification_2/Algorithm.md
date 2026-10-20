### Algorithm: Recursive Evaluation of an Arithmetic Expression Tree

Step 1: Start the program.

Step 2: Include the `<iostream>` header file.

Step 3: Define a structure named `Node` containing `data`, `left`, and `right` pointers.

Step 4: Create a binary expression tree representing `(5 + 3) * 2`.

Step 5: Define a recursive function named `evaluate()`.

Step 6: Check whether the current node is `nullptr`. If true, return zero.

Step 7: Check whether the current node is a leaf node. If true, convert its character into an integer and return the value.

Step 8: Recursively evaluate the left subtree.

Step 9: Recursively evaluate the right subtree.

Step 10: Check the operator stored in the current node.

Step 11: Perform addition, subtraction, multiplication, or division according to the operator.

Step 12: Before performing division, check whether the right subtree value is zero.

Step 13: If the divisor is zero, display an error message and return zero.

Step 14: If the operator is invalid, display an error message and return zero.

Step 15: Return the calculated result.

Step 16: Display the arithmetic expression and its final evaluated result.

Step 17: Define and call `deleteTree()` to release the allocated memory.

Step 18: Stop the program.
