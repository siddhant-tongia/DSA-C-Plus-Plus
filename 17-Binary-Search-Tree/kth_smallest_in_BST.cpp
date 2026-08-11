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

int preorder = 0;
int kthSmallest(Node* root, int k) {

    if(root == NULL){
        return -1;
    }

    if(root->left){
        int leftans = kthSmallest(root->left,k);
        if(leftans != -1){
            return leftans;
        }
    }

    if(preorder + 1 == k){
        return root->data;
    }
    preorder = preorder + 1;

    if(root->right){
        int rightans = kthSmallest(root->right,k);
        if(rightans != -1){
            return rightans;
        }
    }

return -1;
}
int main()
{
    vector<int> arr = {3,2,1,5,6,4};
    Node* root = buildBST(arr);
    cout << kthSmallest(root,4);
return 0;
}