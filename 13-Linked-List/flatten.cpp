#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head){
        if(head == NULL){
            return head;
        }
        Node* curr = head;
        while(curr != NULL){
            if(curr->child != NULL){
                Node* next = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;

                while(curr->next != NULL){
                    curr = curr->next;
                }
                curr->next = next;
                if(next != NULL){
                    next->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};

int main(){
    Node* head = new Node();
    head->val = 1;
    head->prev = NULL;
    head->next = NULL;

    Node* child = new Node();
    child->val = 2;
    child->prev = NULL;
    child->next = NULL;
    child->child = NULL;

    head->child = child;

    Solution obj;
    Node* res = obj.flatten(head);

    while(res != NULL){
        cout << res->val << " ";
        res = res->next;
    }
    cout << "\n";

    return 0;
}