/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int cflag = 0;
        int curval;
        ListNode* h = NULL;
        ListNode* curp;
        ListNode* n;
        while(l1 != NULL || l2 != NULL)
        {
            if(l1==NULL)
                curval = l2->val + cflag;
            else if(l2 == NULL)
                curval = l1->val + cflag;
            else
                curval = l1->val + l2->val + cflag;
            n = new ListNode(curval % 10);
            if(h == NULL)
            {
                h = n;
                curp = h;
            }
            else{
                curp->next = n;
                curp = curp->next;
            }
            if(curval>=10)
                cflag = 1;
            else
                cflag = 0;
            if(l1!=NULL)
                l1 = l1->next;
            if(l2!=NULL)
                l2 = l2->next;
        }
        if(cflag == 1)
        {
            n = new ListNode(cflag);
            curp->next = n;
        }
        return h;
    }
};
