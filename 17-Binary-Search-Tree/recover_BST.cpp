#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};

Node* prevNode = NULL;
Node* first = NULL;
Node* second = NULL;

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);

    if(prevNode != NULL && prevNode->data > root->data){
        if(first == NULL){
            first = prevNode;
        }
        second = root;
    }

    prevNode = root;
    inorder(root->right);
}

void recoverTree(Node* root){
    inorder(root);

    if(first != NULL && second != NULL){
        int temp = first->data;
        first->data = second->data;
        second->data = temp;
    }
}

void printInorder(Node* root){
    if(root == NULL){
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main(){
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(9);

    int temp = root->left->data;
    root->left->data = root->right->data;
    root->right->data = temp;

    printInorder(root);
    cout << "\n";

    recoverTree(root);

    printInorder(root);
    cout << "\n";

    return 0;
}