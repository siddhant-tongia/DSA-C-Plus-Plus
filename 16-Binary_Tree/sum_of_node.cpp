#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            left = right = NULL;
        }
};

static int idx = -1;
Node* buildtree(vector<int> &preorder){
    idx++;
    if(preorder[idx] == -1){
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildtree(preorder);
    root->right = buildtree(preorder);
    return root;
}
static int total_sum = 0;
int sum(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftsum = sum(root->left);
    int rightsum = sum(root->right);
    
return leftsum + rightsum + root->data;
}

int main()
{
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildtree(preorder);
    cout << sum(root) << endl;
return 0;
}