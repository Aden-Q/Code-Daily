// Binary Tree Preorder Traverse

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> s;
        pre(s, root);
        return s;
    }
    void pre(vector<int>& s, TreeNode* cur){
        if(cur)
            s.push_back(cur->val);
        else
            return;
        if(cur->left)
            pre(s, cur->left);
        if(cur->right)
            pre(s, cur->right);
        return;
    }
};