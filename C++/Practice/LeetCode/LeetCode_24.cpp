// Swap Nodes in Pairs
// 100.00% time, 24.81% space
// Head recursion, step length 2, somewhat not intuitive
// AC

#include <iostream>
#include <vector>

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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
        	return head;
        // tail recursion
        else {
        	ListNode* prev = head;
        	ListNode* cur = head->next;
        	ListNode* next = head->next->next;
        	cur->next = prev;
        	prev->next = swapPairs(next);
        	return cur;
        }
    }
};

int main() {
	cout << "Hello, World!" << endl; 
	return 0;
}