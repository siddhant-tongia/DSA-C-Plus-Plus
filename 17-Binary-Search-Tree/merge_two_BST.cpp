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
            right = left = NULL;
        }
};

vector<int> inorder(Node* root, vector<int> &arr){
    if(root == NULL){
        return arr;
    }
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
    return arr;
}

Node* insert(int val, Node* root){
    if(root == NULL){
        return new Node(val);
    }

    if(val < root->data){
        root->left = insert(val,root->left);
    }else{
        root->right = insert(val,root->right);
    }

    return root;
}

Node* buildBST(vector<int> &arr){
    Node* root = NULL;
    for(auto val : arr){
        root = insert(val,root);
    }

    return root;
}

Node* buildsortedBST(vector<int> &arr,int st, int end){

    if(st > end){
        return NULL;
    }

    int mid = st + (end-st)/2;


    Node* root = new Node(arr[mid]);

    root->left = buildsortedBST(arr,st,mid-1);
    root->right = buildsortedBST(arr,mid+1,end);

    return root;
}

Node* mergeTwoBSTs(Node* root1, Node* root2){
    vector<int> arr1,arr2;

    inorder(root1,arr1);
    inorder(root2,arr2);

    vector<int> mergearr;

    int i = 0, j = 0;

    while(i < arr1.size() && j < arr2.size()){
        arr1[i] < arr2[j] ? mergearr.push_back(arr1[i++]) : mergearr.push_back(arr2[j++]);
    }

    while(i < arr1.size()){
        mergearr.push_back(arr1[i++]);
    }
    while(j < arr2.size()){
        mergearr.push_back(arr2[j++]);
    }
return buildsortedBST(mergearr,0,mergearr.size()-1);
}

void inorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main(){
    vector<int> nums1 = {8,2,1,10};
    vector<int> nums2 = {5,3,0};

    Node* root1 = buildBST(nums1);
    Node* root2 = buildBST(nums2);

    Node* root = mergeTwoBSTs(root1,root2);

    inorderTraversal(root);    
return 0;
}