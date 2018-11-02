// Maximum Depth Of Binary Tree
// 单边recursion
// 99.29%

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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int maxd = -1;
        maxd = max(maxDepth(root->left), maxDepth(root->right)) + 1;
        return maxd;
    }
    
    int max(int i, int j){
        if(i<j)
            return j;
        else
            return i;
    }
    
};