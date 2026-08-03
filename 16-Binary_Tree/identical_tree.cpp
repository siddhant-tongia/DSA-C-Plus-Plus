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

int main()
{
    vector<int> tree1 = {1,2,-1,-1,3,-1,-1};
    vector<int> tree2 = {1,2,-1,-1,3,-1,-1};
    int idx1 = -1, idx2 = -1;
    Node* root1 = buildtree(tree1,idx1);
    Node* root2 = buildtree(tree2,idx2);
    cout << isIdentical(root1,root2) << endl;

return 0;
}