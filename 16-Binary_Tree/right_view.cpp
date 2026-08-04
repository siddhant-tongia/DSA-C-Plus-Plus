#include<iostream>
#include<vector>
#include<queue>
#include<map>
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
void rightview(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        int levelSize = q.size(); 
        
        for(int i = 0; i < levelSize; i++){
            Node* curr = q.front();
            q.pop();
            
            if(i == levelSize - 1){
                cout << curr->data << " ";
            }
            
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
    }
}
int main()
{
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildtree(preorder);
    rightview(root);
return 0;
}