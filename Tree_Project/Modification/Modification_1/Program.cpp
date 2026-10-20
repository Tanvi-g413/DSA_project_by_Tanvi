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

// Preorder Traversal: Root, Left, Right
void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder Traversal: Left, Root, Right
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder Traversal: Left, Right, Root
void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
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
    // Create expression tree for (A+B)*C
    Node* root = new Node('*');

    root->left = new Node('+');
    root->right = new Node('C');

    root->left->left = new Node('A');
    root->left->right = new Node('B');

    cout << "Preorder Traversal: ";
    preorder(root);

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    cout << endl;

    deleteTree(root);

    return 0;
}
