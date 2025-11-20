#include<iostream>

struct Node {
    int data;       
    Node* left;     
    Node* right;   
};

// Function to create a new node with given data
Node* createNode(int value) {
    Node* newNode = new Node();  
    newNode->data = value;       
    newNode->left = nullptr;     
    newNode->right = nullptr;    
    return newNode;              
}

// Function for Pre-order traversal: Root -> Left -> Right
void preOrderTraversal(Node* root) {
    if (root == nullptr) {       
        return;
    }
    std::cout << root->data << " ";  
    preOrderTraversal(root->left);  
    preOrderTraversal(root->right);  
}

// Function for In-order traversal: Left -> Root -> Right
void inOrderTraversal(Node* root) {
    if (root == nullptr) {       
        return;
    }
    inOrderTraversal(root->left);   
    std::cout << root->data << " ";  
    inOrderTraversal(root->right);   
}

// Function for Post-order traversal: Left -> Right -> Root
void postOrderTraversal(Node* root) {
    if (root == nullptr) {   
        return;
    }
    postOrderTraversal(root->left);  
    postOrderTraversal(root->right); 
    std::cout << root->data << " "; 
}

int main(){
    Node* root = createNode(1);      
    root->left = createNode(2);      
    root->right = createNode(3);    
    root->left->left = createNode(4);  
    root->left->right = createNode(5); 
    
    
    std::cout << "Pre-order Traversal: ";
    preOrderTraversal(root);
    std::cout << std::endl;
    
    std::cout << "In-order Traversal: ";
    inOrderTraversal(root);
    std::cout << std::endl;
    
    std::cout << "Post-order Traversal: ";
    postOrderTraversal(root);
    std::cout << std::endl;

    return 0;
}