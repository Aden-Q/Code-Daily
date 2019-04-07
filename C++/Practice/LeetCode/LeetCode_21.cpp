// Merge two sorted linkedlists
// C++ 超89.16%
// 一样是个简单的题，实现就行了，当复习语法用

#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        int val1, val2;
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while(l1 || l2){
            if(l1!=NULL)
                val1 = l1->val;
            else
                val1 = 10000;
            if(l2!=NULL)
                val2 = l2->val;
            else
                val2 = 10000;
            if(val1 < val2){
                ListNode* newnode = new ListNode(val1);
                cur->next = newnode;
                l1 = l1->next;
            }
            else{
                ListNode* newnode = new ListNode(val2);
                cur->next = newnode;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        return head->next;
    }
};

int main(){
    Solution test;
    ListNode* res;
    ListNode l(1);
    ListNode* newl = new ListNode(2);
    l->next = newl;
    res = test.mergeTwoLists();

    return 0;
}
