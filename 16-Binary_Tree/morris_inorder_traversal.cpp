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

vector<int> inorderTraversal(Node* root) {
    vector<int> ans;
    Node* curr = root;

    while(curr != NULL){
        if(curr->left == NULL){
            ans.push_back(curr->data);
            curr = curr->right;
        }else{
            Node* IP = curr->left;
            while(IP->right != NULL && IP->right != curr){
            IP = IP->right;
            }
            if(IP->right == NULL){
                IP->right = curr;
                curr = curr->left;
            }else{
                IP->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
}
int main(){
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildtree(preorder);
    
    vector<int> result = inorderTraversal(root);
    
    for (int i=0; i<result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
return 0;
}