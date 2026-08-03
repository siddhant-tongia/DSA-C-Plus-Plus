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
            left = right = NULL;
        }
};

Node* buildtree(vector<int> &preorder, int &idx){
    idx++;
    if(preorder[idx] == -1){
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildtree(preorder,idx);
    root->right = buildtree(preorder,idx);
    return root;
}

bool isIdentical(Node* p, Node* q){
    if(p == NULL || q == NULL){
        return p == q;
    }

    bool IsleftSame = isIdentical(p->left,q->left);
    bool IsrightSame = isIdentical(p->right,q->right);

    return IsleftSame && IsrightSame && p->data == q->data;
}

bool isSubtree(Node* root, Node* subRoot) {
        if(root == NULL || subRoot == NULL){
            return root == subRoot;
        }
        if(root->data == subRoot->data && isIdentical(root,subRoot)){
            return true;
        }

        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }

int main()
{
    vector<int> tree1 = {3, 4, 1, -1, -1, 2, -1, -1, 5, -1, -1};
    vector<int> tree2 = {4, 1, -1, -1, 2, -1, -1};
    int idx1 = -1, idx2 = -1;
    Node* root1 = buildtree(tree1,idx1);
    Node* root2 = buildtree(tree2,idx2);
    cout << isSubtree(root1,root2) << endl;

return 0;
}