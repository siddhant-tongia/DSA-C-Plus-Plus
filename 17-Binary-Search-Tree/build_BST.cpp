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

bool search(Node* root,int key){
    if(root == NULL){
        return false;
    }

    if(root->data == key){
        return true ;
    }

    if(key < root->data){
        return search(root->left,key);
    }else{
        return search(root->right,key);
    }

    return false;
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
    cout << search(root,8) << endl;
return 0;
}