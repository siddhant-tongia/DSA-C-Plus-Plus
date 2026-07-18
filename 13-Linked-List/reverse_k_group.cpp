#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        while(count < k){
            if(temp == NULL){
                return head;
            }
            temp = temp->next;
            count++;
        }

        ListNode* prevNode = reverseKGroup(temp,k);

        temp = head;
        count = 0;
        while(count < k){
            ListNode* next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = next;
            count++;
        }
    return prevNode;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;
    ListNode* res = obj.reverseKGroup(head, 2);

    while(res != NULL){
        cout << res->val << " ";
        res = res->next;
    }
    cout << "\n";

    return 0;
}