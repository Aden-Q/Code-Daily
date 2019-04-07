// 8.86% time, 5.04% space
// AC
// recursion


#include <iostream>
#include <unordered_map>

using namespace std;

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
        	return l2;
        else if(l2 == NULL)
        	return l1;

        ListNode* l;
        if(l1->val <= l2->val) {
        	l = new ListNode(l1->val);
        	l->next = mergeTwoLists(l1->next, l2);
        }
        else {
        	l = new ListNode(l2->val);
        	l->next = mergeTwoLists(l1, l2->next);
        }

        return l;
    }
};


int main(void) {
	Solution test;

	
	return 0;
}