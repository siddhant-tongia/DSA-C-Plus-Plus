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
    
Node* helper(vector<int>& nums, int st, int end){
    int mid = st+(end-st)/2;

    if(st > end){
        return NULL;
    }

    Node* root = new Node(nums[mid]);

    root->left = helper(nums, st, mid-1);
    root->right = helper(nums, mid+1, end);

return root;
}

Node* sortedArrayToBST(vector<int>& nums){
    Node* root = helper(nums,0,nums.size()-1);
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

int main(){
    vector<int> nums = {-10,3,0,5,9};
    inorder(sortedArrayToBST(nums));
return 0;
}