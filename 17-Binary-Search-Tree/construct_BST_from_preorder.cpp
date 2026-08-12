#include<iostream>
#include<vector>
#include<climits>
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


Node* buildBST(vector<int>& preorder, int& i, int bound){
    if(i >= preorder.size() || preorder[i] > bound){
            return NULL;
    }

    Node* root = new Node(preorder[i++]);

    root->left = buildBST(preorder,i,root->data);
    root->right = buildBST(preorder,i,bound);
return root;
}
Node* bstFromPreorder(vector<int>& preorder){
    int i = 0;
    return buildBST(preorder,i,INT_MAX);
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


int main(){
    vector<int> nums = {8,5,1,7,10,12};
    Node* root = bstFromPreorder(nums);
    inorder(root);
    return 0;
}