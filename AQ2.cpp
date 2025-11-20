#include <iostream>

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

bool searchRecursive(Node* root, int key) {
    if (root == nullptr) {
        return false;
    }
    if (key == root->data) {
        return true;
    } else if (key < root->data) {
        return searchRecursive(root->left, key);
    } else {
        return searchRecursive(root->right, key);
    }
}

bool searchIterative(Node* root, int key) {
    Node* current = root;
    while (current != nullptr) {
        if (key == current->data) {
            return true;
        } else if (key < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}

int findMax(Node* root) {
    if (root == nullptr) {
        std::cout << "Tree is empty." << std::endl;
        return -1;
    }
    Node* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current->data;
}

int findMin(Node* root) {
    if (root == nullptr) {
        std::cout << "Tree is empty." << std::endl;
        return -1;
    }
    Node* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current->data;
}

Node* findMinNode(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

Node* inOrderSuccessor(Node* root, Node* node) {
    if (node->right != nullptr) {
        return findMinNode(node->right);
    }
    Node* successor = nullptr;
    Node* current = root;
    while (current != nullptr) {
        if (node->data < current->data) {
            successor = current;
            current = current->left;
        } else if (node->data > current->data) {
            current = current->right;
        } else {
            break;
        }
    }
    return successor;
}

Node* findMaxNode(Node* node) {
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

Node* inOrderPredecessor(Node* root, Node* node) {
    if (node->left != nullptr) {
        return findMaxNode(node->left);
    }
    Node* predecessor = nullptr;
    Node* current = root;
    while (current != nullptr) {
        if (node->data > current->data) {
            predecessor = current;
            current = current->right;
        } else if (node->data < current->data) {
            current = current->left;
        } else {
            break;
        }
    }
    return predecessor;
}

void inOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    Node* root = createNode(8);
    root->left = createNode(3);
    root->right = createNode(10);
    root->left->left = createNode(1);
    root->left->right = createNode(6);
    root->left->right->left = createNode(4);
    root->left->right->right = createNode(7);
    root->right->right = createNode(14);
    root->right->right->left = createNode(13);

    int key = 6;
    std::cout << "Recursive search for " << key << ": " << (searchRecursive(root, key) ? "Found" : "Not Found") << std::endl;
    std::cout << "Iterative search for " << key << ": " << (searchIterative(root, key) ? "Found" : "Not Found") << std::endl;

    key = 5;
    std::cout << "Recursive search for " << key << ": " << (searchRecursive(root, key) ? "Found" : "Not Found") << std::endl;
    std::cout << "Iterative search for " << key << ": " << (searchIterative(root, key) ? "Found" : "Not Found") << std::endl;

    std::cout << "Maximum element: " << findMax(root) << std::endl;
    std::cout << "Minimum element: " << findMin(root) << std::endl;

    Node* targetNode = root->left->right;

    Node* succ = inOrderSuccessor(root, targetNode);
    std::cout << "In-order successor of " << targetNode->data << ": ";
    if (succ) std::cout << succ->data << std::endl; else std::cout << "None" << std::endl;

    Node* pred = inOrderPredecessor(root, targetNode);
    std::cout << "In-order predecessor of " << targetNode->data << ": ";
    if (pred) std::cout << pred->data << std::endl; else std::cout << "None" << std::endl;

    std::cout << "In-order Traversal: ";
    inOrderTraversal(root);
    std::cout << std::endl;

    return 0;
}