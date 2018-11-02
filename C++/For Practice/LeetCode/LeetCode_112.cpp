// Path Sum
// 就是最后return answer的条件分支写的有点糟糕
// 100%

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
    int flag = 0;
    // top-down吧，结束到left,right都null
    bool hasPathSum(TreeNode* root, int sum) {
        flag++;     //递归计数标志
        if(root == NULL && sum == 0 && flag>1)
            return true;
        else if(root == NULL)
            return false;
        bool l, r;
        l = hasPathSum(root->left, sum-root->val);
        r = hasPathSum(root->right, sum-root->val);
        if(root->left!=NULL && root->right==NULL && r == true)
            return false;
        else if(root->left==NULL && root->right!=NULL && l == true)
            return false;
        else if(l==true || r==true)
            return true;
        else
            return false;
    }
};