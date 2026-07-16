#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution{
public:
    Node* copyRandomList(Node* head){
        if(head == NULL){
            return NULL; 
        }
        unordered_map<Node*,Node*> m;

        Node* newHead = new Node(head->val);
        Node* oldtemp = head->next;
        Node* newtemp = newHead;
        m[head] = newHead;

        while(oldtemp != NULL){
            Node* copyNode = new Node(oldtemp->val);
            m[oldtemp] = copyNode;
            newtemp->next = copyNode;
            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }
        oldtemp = head;
        newtemp = newHead;

        while(oldtemp != NULL){
            newtemp->random = m[oldtemp->random];
            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }
    return newHead;
    }
};

int main() {
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);

    head->random = NULL;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;

    Solution obj;
    Node* res = obj.copyRandomList(head);

    Node* temp = res;
    while(temp != NULL){
        cout << "[" << temp->val << ", ";
        if(temp->random != NULL) {
            cout << temp->random->val << "] ";
        } else {
            cout << "null] ";
        }
        temp = temp->next;
    }
    cout << "\n";

    return 0;
}