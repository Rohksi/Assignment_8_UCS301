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

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return createNode(key);
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    return root;
}

Node* findMinNode(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int maxDepth(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

int minDepth(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    if (root->left == nullptr) {
        return minDepth(root->right) + 1;
    }
    if (root->right == nullptr) {
        return minDepth(root->left) + 1;
    }
    int leftMin = minDepth(root->left);
    int rightMin = minDepth(root->right);
    return (leftMin < rightMin ? leftMin : rightMin) + 1;
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
    Node* root = nullptr;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    std::cout << "In-order traversal after insertions: ";
    inOrder(root);
    std::cout << std::endl;

    std::cout << "Maximum depth: " << maxDepth(root) << std::endl;
    std::cout << "Minimum depth: " << minDepth(root) << std::endl;

    root = deleteNode(root, 20);
    root = deleteNode(root, 30);
    root = deleteNode(root, 50);

    std::cout << "In-order traversal after deletions: ";
    inOrder(root);
    std::cout << std::endl;

    std::cout << "Maximum depth after deletions: " << maxDepth(root) << std::endl;
    std::cout << "Minimum depth after deletions: " << minDepth(root) << std::endl;

    return 0;
}