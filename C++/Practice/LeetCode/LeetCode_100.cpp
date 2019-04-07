// 0 ms, 100.00% AC

#include <iostream>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
       if(p && q){     // both not empty
           if(p->val != q->val)
               return false;
           else if(isSameTree(p->left, q->left) == true && isSameTree(p->right, q->right) == true)
               return true;
           else
               return false;
       }
       else if(!p && !q)    // both empty
           return true;
       else     // one is empty but not both
           return false;
    }
};

int main(){

    return 0;
}
