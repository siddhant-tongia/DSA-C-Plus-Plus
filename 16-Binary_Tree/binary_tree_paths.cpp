#include<iostream>
#include<vector>
#include<string>
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
void paths(Node* root, string path, vector<string>& ans){
    if(root->left == NULL && root->right == NULL){
        ans.push_back(path);
        return;
    }

    if(root->left){
        paths(root->left,path + "->" + to_string(root->left->data),ans);
    }
    if(root->right){
        paths(root->right,path + "->" + to_string(root->right->data),ans);
    }
}
vector<string> binaryTreePaths(Node* root) {

    vector<string> ans;
    string path = to_string(root->data);
    if(root == NULL){
        return ans;
    }
    paths(root,path,ans);
return ans;
}

int main()
{
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildtree(preorder);
    vector<string> result = binaryTreePaths(root);

    for(auto path : result){
        cout << path << ",";
    }
return 0;
}