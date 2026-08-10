#include<iostream>
#include<vector>
#include<unordered_set>
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

bool isValidBST(Node* root, Node* min, Node* max){
    if(root == NULL){
        return true;
    }

    if(min != NULL && root->data <= min->data){
        return false;
    }
    if(max != NULL && root->data >= max->data){
        return false;
    }

    return isValidBST(root->left,min,root) && isValidBST(root->right,root,max);
}

int main()
{
    vector<int> arr = {3,2,1,5,6,4};
    Node* root = buildBST(arr);
    cout << isValidBST(root,NULL,NULL) << endl;
return 0;
}