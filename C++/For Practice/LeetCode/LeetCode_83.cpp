// Remove Duplicates from Sorted List

#include <iostream>

using namespace std;


 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pre, *post;
        pre = head;
        post = head;
        // 好吧我算是一点都不管内存释放了
        while(post!=NULL){
            while(post && post->val == pre->val)
                post= post->next;
            pre->next = post;
            pre = post;
        }

        return head;
    }
};

int main(){
    Solution test;
    ListNode* t1 = new ListNode(1);
    ListNode* t2 = new ListNode(2);
    ListNode* t3 = new ListNode(3);
    t1->next = t2;
    t2->next = t3;
    ListNode* res = test.deleteDuplicates(t1);

    return 0;
}
