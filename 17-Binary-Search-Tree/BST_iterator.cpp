#include<iostream>
#include<stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        data = val;
        right = left = NULL;
    }
};

class BSTIterator {
public:
    stack<Node*> s;

    void storeleftNode(Node* root){
        while(root != NULL){
            s.push(root);
            root = root->left;
        }
    }

    BSTIterator(Node* root){
        storeleftNode(root);
    }
    
    int next(){
        Node* ans = s.top();
        s.pop();
        if(ans->right){
            storeleftNode(ans->right);
        }
        return ans->data;
    }
    
    bool hasNext(){
        return s.size() > 0;
    }
};

int main(){
    Node* root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(15);
    root->right->left = new Node(9);
    root->right->right = new Node(20);

    BSTIterator* iterator = new BSTIterator(root);
    while(iterator->hasNext()) {
        cout << iterator->next() << " ";
    }
    cout << endl;
return 0;
}