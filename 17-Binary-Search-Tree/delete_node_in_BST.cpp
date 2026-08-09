#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            right = left = NULL;
        }
};

Node* insert(int val, Node* root){
    if(root == NULL){
        return new Node(val);
    }

    if(val < root->data){
        root->left = insert(val,root->left);
    }else{
        root->right = insert(val,root->right);
    }

    return root;
}

Node* buildBST(vector<int> &arr){
    Node* root = NULL;
    for(auto val : arr){
        root = insert(val,root);
    }

    return root;
}

Node* GetInorderSuccessor(Node* root){
    while(root != NULL && root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int key){
    if(root == NULL){
        return root;
    }

    if(key < root->data){
        root->left  = deleteNode(root->left,key);
    }else if(key > root->data){
        root->right = deleteNode(root->right,key);
    }else{
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }else{
            Node* inorderSuccessor = GetInorderSuccessor(root->right);
            root->data = inorderSuccessor->data;
            root->right = deleteNode(root->right,inorderSuccessor->data);
        }
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    vector<int> arr = {3,2,1,5,6,4};
    Node* root = buildBST(arr);
    deleteNode(root,4);
    inorder(root);
return 0;
}