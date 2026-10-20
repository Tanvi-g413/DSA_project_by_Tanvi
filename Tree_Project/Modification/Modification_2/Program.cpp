#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Evaluate the expression tree
int evaluate(Node* root) {
    if (root == NULL)
        return 0;

    // If the node is an operand
    if (root->left == NULL && root->right == NULL)
        return root->data - '0';

    // Evaluate left and right subtrees
    int leftValue = evaluate(root->left);
    int rightValue = evaluate(root->right);

    // Apply the operator
    switch (root->data) {
        case '+':
            return leftValue + rightValue;

        case '-':
            return leftValue - rightValue;

        case '*':
            return leftValue * rightValue;

        case '/':
            if (rightValue == 0) {
                cout << "Error: Division by zero!" << endl;
                return 0;
            }
            return leftValue / rightValue;

        default:
            cout << "Error: Invalid operator!" << endl;
            return 0;
    }
}

// Free allocated memory
void deleteTree(Node* root) {
    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    // Create expression tree for (5 + 3) * 2
    Node* root = new Node('*');

    root->left = new Node('+');
    root->right = new Node('2');

    root->left->left = new Node('5');
    root->left->right = new Node('3');

    cout << "Expression: (5 + 3) * 2" << endl;
    cout << "Result: " << evaluate(root) << endl;

    deleteTree(root);

    return 0;
}

