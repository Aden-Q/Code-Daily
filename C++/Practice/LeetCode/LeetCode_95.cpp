// 75.89% time, 16.66% space
// AC
// recursion


#include <iostream>
#include <vector>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        TreeNode* root;
        vector<TreeNode*> trees;
        if(n < 1)
        	return trees;

        trees = treeGenerate(1, n);
        
        return trees;
    }

    vector<TreeNode*> treeGenerate(int start, int end) {
    	TreeNode* root;
    	vector<TreeNode*> trees;

    	if(start > end) {
    		trees.push_back(NULL);
    		return trees;
    	}

    	for(int i=start; i <= end; i++) {
    		vector<TreeNode*> leftTrees = treeGenerate(start, i-1);
    		vector<TreeNode*> rightTrees = treeGenerate(i+1, end);

			for(auto ltree : leftTrees) {
				for(auto rtree : rightTrees) {
					root = new TreeNode(i);
					root->left = ltree;
					root->right = rtree;
					trees.push_back(root);
				}
			}    		
    	}

    	return trees;
    }
};


int main(void) {
	Solution test;
	vector<TreeNode*> trees = test.generateTrees(3);

	for(auto tree : trees)
		cout << tree->val << endl;
	
	return 0;
}