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

int widthOfBinaryTree(Node* root) {
        if (!root) return 0;
    queue<pair<Node*,unsigned long long>> q;
    q.push({root,0});
    int maxwidth = 0;
    
    while(q.size() > 0){
        int currlevSize = q.size();
        unsigned long long stwidth = q.front().second;
        unsigned long long endwidth = q.back().second;

        maxwidth = max(maxwidth, (int)(endwidth - stwidth + 1));

        for(int i=0 ; i<currlevSize ; i++){
            auto curr = q.front();
            unsigned long long idx = q.front().second;
            q.pop();
            if(curr.first->left){
                q.push({curr.first->left,idx*2 + 1});
            }
            if(curr.first->right){
                q.push({curr.first->right,idx*2 + 2});
            }
        }
    }
    return maxwidth;
}

int main()
{
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildtree(preorder);
    cout << widthOfBinaryTree(root) << endl;
return 0;
}