#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow){
                return true;
            }
        }  
    return false;      
    }
};

int main() {
    ListNode* head = new ListNode(3);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(0);
    ListNode* node3 = new ListNode(-4);
    
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1; 

    Solution obj;
    bool res = obj.hasCycle(head);

    cout << (res ? "true" : "false") << "\n";

    return 0;
}