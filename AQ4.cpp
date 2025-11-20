#include <iostream>
#include <climits>

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

bool isBSTUtil(Node* root, long long minVal, long long maxVal) {
    if (root == nullptr) {
        return true;
    }
    if (root->data <= minVal || root->data >= maxVal) {
        return false;
    }
    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

void inOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    Node* root1 = createNode(50);
    root1->left = createNode(30);
    root1->right = createNode(70);
    root1->left->left = createNode(20);
    root1->left->right = createNode(40);
    root1->right->left = createNode(60);
    root1->right->right = createNode(80);

    std::cout << "Tree 1 (Valid BST): ";
    inOrder(root1);
    std::cout << "\nIs BST? " << (isBST(root1) ? "Yes" : "No") << std::endl;

    Node* root2 = createNode(50);
    root2->left = createNode(30);
    root2->right = createNode(70);
    root2->left->left = createNode(20);
    root2->left->right = createNode(60);
    root2->right->left = createNode(40);
    root2->right->right = createNode(80);

    std::cout << "\nTree 2 (Invalid BST): ";
    inOrder(root2);
    std::cout << "\nIs BST? " << (isBST(root2) ? "Yes" : "No") << std::endl;

    return 0;
}