#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2){
        if(h1 == NULL || h2 == NULL){
            return h1 == NULL ? h2 : h1;
        }

        if(h1->val <= h2->val){
            h1->next = mergeTwoLists(h1->next,h2);
            return h1;
        }
        else{
            h2->next = mergeTwoLists(h1,h2->next);
            return h2;
        }
    }
};

int main(){
    ListNode* h1 = new ListNode(1);
    h1->next = new ListNode(2);
    h1->next->next = new ListNode(4);

    ListNode* h2 = new ListNode(1);
    h2->next = new ListNode(3);
    h2->next->next = new ListNode(4);

    Solution obj;
    ListNode* res = obj.mergeTwoLists(h1, h2);

    while(res != NULL){
        cout << res->val << " ";
        res = res->next;
    }
    cout << "\n";

    return 0;
}