// Binary Tree Inorder Traversal with DFS (iterative way)
// 100.00% time and 53.68% space
// AC
// no reference

#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    map<TreeNode*, bool> visited;

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> node;
        TreeNode* cur;
        node.push(root);

        // due to inorder requirements, a little complex
        while(!node.empty()) {
            cur = node.top();
            // visit directly
            if(!cur)
                node.pop();
            // visit directly
            else if(!cur->left) {
                node.pop();
                if(cur->right)
                    node.push(cur->right);
                res.push_back(cur->val);
                visited[cur] = true;
            }
            else if(visited.find(cur->left) != visited.end()) {
                res.push_back(cur->val);
                visited[cur] = true;
                node.pop();
                if(cur->right)
                    node.push(cur->right);
            }
            else {
                node.push(cur->left);
            }
        }

        return res;
    }
};

int main(){
    Solution test;
    TreeNode root(1);
    root.right = new TreeNode(2);
    root.right->left = new TreeNode(3);
    vector<int> res;
    res = test.inorderTraversal(&root);
    // cout << res << endl;

    return 0;
}