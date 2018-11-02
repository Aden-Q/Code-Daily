// Symmtric Tree
// 双边recursion
// 98.91%

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
    stack<int> s;
    // 自顶向下两个node一起recurse
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        if(root->left == NULL && root->right == NULL)
            return true;
        else
            return recur(root->left, root->right);
    }
    
    bool recur(TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL)
            return true;
        else if(left == NULL || right == NULL)
            return false;
        bool l, r;
        l = recur(left->left, right->right);
        r = recur(left->right, right->left);
        if(l == true && r == true && left->val == right->val)
            return true;
        else
            return false;
    }
};