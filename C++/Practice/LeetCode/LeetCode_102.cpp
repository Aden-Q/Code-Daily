// Binary Tree Leval Order Traverse

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
    vector<vector<int>> res;
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        traverse(root, 0);
        return res;
    }
    
    void traverse(TreeNode* cur, int depth){
        if(cur==NULL)
            return;
        if(depth >= res.size()){
            // allocate vec object
            vector<int> newvec;
            newvec.push_back(cur->val);
            res.push_back(newvec);
        }
        else
            res[depth].push_back(cur->val);
        traverse(cur->left, depth+1);
        traverse(cur->right, depth+1);
        return;
    }
};