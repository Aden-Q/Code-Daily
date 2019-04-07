// Binary Tree Inorder Traverse

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(res, root);
        return res;
    }
    
    void inorder(vector<int>& res, TreeNode* cur){
        if(cur==NULL)
            return;
        inorder(res, cur->left);
        res.push_back(cur->val);
        inorder(res, cur->right);
        return;
    }
};