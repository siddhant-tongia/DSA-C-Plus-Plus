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
Node* LastVisited = NULL;
void flatten(Node* root){
    if(root == NULL){
        return;
    }

    flatten(root->right);
    flatten(root->left);

    root->left = NULL;
    root->right = LastVisited;
    LastVisited = root;
}

int main(){
    vector<int> preorder = {1, 2, 3, -1, -1, 4, -1, -1, 5, -1, 6, -1, -1};
    Node* root = buildtree(preorder);
    
    flatten(root);
    
    Node* curr = root;
    while (curr != NULL){
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
return 0;
}