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

Node* LCA(Node* root, Node* p, Node* q){

    if(root == NULL){
        return NULL;
    }

    int rval = root->data;
    int pval = p->data;
    int qval = q->data;

    if(rval > pval && rval > qval){
        return LCA(root->left,p,q);
    }else if(rval < pval && rval < qval){
        return LCA(root->right,p,q);
    }else{
        return root;
    }
}

int main()
{
    vector<int> arr = {3,2,1,5,6,4};
    Node* root = buildBST(arr);
    Node* p = root->right->left;
    Node* q = root->right->right;
    
    Node* ans = LCA(root, p, q);
    if(ans != NULL){
        cout << ans->data << endl;
    }
    
    return 0;
}