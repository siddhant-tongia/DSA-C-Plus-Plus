#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* right;
    Node* left;

    Node(int val){
        data = val;
        right = left = NULL;
    }
};

Node* leftmostfromrighttree(Node* root){
    Node* ans = NULL;
    while(root != NULL){
        ans = root;
        root = root->left;
    }
    return ans;
}

Node* rightmostfromlefttree(Node* root){
    Node* ans = NULL;
    while(root != NULL){
        ans = root;
        root = root->right;
    }
    return ans;
}

vector<int> inorderPredandSucc(Node* root, int key){
    Node* curr = root;
    Node* pred = NULL;
    Node* succ = NULL;

    while(curr != NULL){
        if(curr->data < key){
            pred = curr;
            curr = curr->right;
        }else if(curr->data > key){
            succ = curr;
            curr = curr->left;
        }else{
            if(curr->left != NULL){
                pred = rightmostfromlefttree(curr->left);
            }
            if(curr->right != NULL){
                succ = leftmostfromrighttree(curr->right);
            }
            break;
        }
    }

    int p = (pred != NULL) ? pred->data : -1;
    int s = (succ != NULL) ? succ->data : -1;

    return {p,s};
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    vector<int> ans = inorderPredandSucc(root, 10);
    cout << ans[0] << "\n" << ans[1] << "\n";

    ans = inorderPredandSucc(root, 8);
    cout << ans[0] << "\n" << ans[1] << "\n";

    return 0;
}