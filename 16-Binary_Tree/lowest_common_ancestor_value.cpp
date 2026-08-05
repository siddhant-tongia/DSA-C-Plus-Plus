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

Node* lowestCommonAncestor(Node* root, Node* p, Node* q){
    if(root == NULL){
        return NULL;
    }

    if(root == p || root == q){
        return root;
    }

    Node* lefthalf = lowestCommonAncestor(root->left,p,q);
    Node* righthalf = lowestCommonAncestor(root->right,p,q);
        
    if(righthalf && lefthalf){
        return root;
    }else{
        if(lefthalf != NULL){
            return lefthalf;
        }else{
            return righthalf;
        }
    }
}
 
int main()
{
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildtree(preorder);
    
    Node* p = root->right->left;
    Node* q = root->right->right;
    
    Node* ancestor = lowestCommonAncestor(root, p, q);
    
    if(ancestor != NULL){
        cout << ancestor->data << endl;
    }
return 0;
}