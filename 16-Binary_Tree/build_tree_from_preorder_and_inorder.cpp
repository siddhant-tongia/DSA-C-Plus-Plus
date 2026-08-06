#include<iostream>
#include<vector>

using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int val){
            data = val;
            left = right = NULL;
        }
};
int search(vector<int>& inorder, int left, int right, int val){
    for(int i=left ; i<=right ; i++){
        if(inorder[i] == val){
            return i;
        }
    }
return -1;
}

TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& preidx, int left, int right){
    if(left > right){
        return NULL;
    }

    TreeNode* root = new TreeNode(preorder[preidx]);

    int inidx = search(inorder, left, right, preorder[preidx]);
    preidx++;

    root->left = helper(preorder, inorder, preidx, left, inidx-1);
    root->right = helper(preorder, inorder, preidx, inidx+1, right);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preidx = 0;
    return helper(preorder, inorder, preidx, 0, preorder.size()-1);
}

void printInorder(TreeNode* root){
    if (root == NULL){
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main(){

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* root = buildTree(preorder, inorder);

    printInorder(root);
    cout << endl;
return 0;
}