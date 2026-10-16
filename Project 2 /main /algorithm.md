## Algorithm: Postorder Traversal of an Expression Tree

Step 1: Start.

Step 2: Define a structure "Node" containing data, a left pointer, and a right pointer.

Step 3: Create an expression tree for "(A+B)*C" with "*" as the root node, "+" as its left child, and "C" as its right child. Set "A" and "B" as the left and right children of "+", respectively.

Step 4: Call the recursive function "postorder(root)".

Step 5: If "root == NULL", return.

Step 6: Traverse the left subtree by calling "postorder(root->left)".

Step 7: Traverse the right subtree by calling "postorder(root->right)".

Step 8: Print the data of the current root node.

Step 9: Display the postorder traversal: "A B + C *".

Step 10: Call "deleteTree(root)" to release the allocated memory.

Step 11: Stop.
