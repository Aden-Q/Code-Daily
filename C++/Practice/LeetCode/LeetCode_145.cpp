// Binary Tree Postorder Traverse

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(res, root);
        return res;
    }
    
    void postorder(vector<int>& res, TreeNode* cur){
        if(cur==NULL)
            return;
        postorder(res, cur->left);
        postorder(res, cur->right);
        res.push_back(cur->val);
        return;
    }
};