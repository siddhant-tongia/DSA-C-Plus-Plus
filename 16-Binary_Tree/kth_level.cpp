#include<iostream>
#include<vector>
#include<queue>
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

void kthlevel(Node* root, int k){

    if(root == NULL){
        return;
    }
    queue<pair<Node*,int>> q;
    q.push({root,1});

    while(q.size() > 0){
        Node* curr = q.front().first;
        int level = q.front().second;

        q.pop();

        if(level == k){
            cout << curr->data << " ";
        }
        if(level < k){
            if(curr->left != NULL){
                q.push({curr->left,level+1});
            }
            if(curr->right != NULL){
                q.push({curr->right,level+1});
            }
        }
    }
}

int main()
{
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildtree(preorder);
    kthlevel(root,3);
return 0;
}