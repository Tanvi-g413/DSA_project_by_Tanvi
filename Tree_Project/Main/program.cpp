#include <iostream>
using namespace std;

// Structure of a binary tree node
struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Recursive postorder traversal
void postorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    // Traverse left subtree
    postorder(root->left);

    // Traverse right subtree
    postorder(root->right);

    // Visit root node
    cout << root->data << " ";
}

int main() {
    // Create expression tree for (A+B)*C
    Node* root = new Node('*');

    root->left = new Node('+');
    root->right = new Node('C');

    root->left->left = new Node('A');
    root->left->right = new Node('B');

    cout << "Postorder Traversal: ";
    postorder(root);

    cout << endl;
    return 0;
}
