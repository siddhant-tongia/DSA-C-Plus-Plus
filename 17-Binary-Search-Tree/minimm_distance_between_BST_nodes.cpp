#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
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

Node* prevNode = NULL;
int minDiffInBST(Node* root){
    if(root == NULL){
        return INT_MAX;
    }

    int ans = INT_MAX;

    if(root->left != NULL){
        int leftmin = minDiffInBST(root->left);
        ans = min(ans,leftmin);
    }

    if(prevNode != NULL){
        ans = min(ans,root->data - prevNode->data);
    }

    prevNode = root;

    if(root->right != NULL){
        int rightmin = minDiffInBST(root->right);
        ans = min(ans,rightmin);
    }

    return ans;
}

int main()
{
    vector<int> arr = {3,2,1,5,6,4};
    Node* root = buildBST(arr);
    cout << minDiffInBST(root);
return 0;
}