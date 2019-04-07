// Construct Binary Tree from Preorder and Inorder Traversal

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

    TreeNode* helper(vector<int>& preorder, int pleft, int pright, vector<int>& inorder, int ileft, int iright){
        if(pleft>pright || ileft>iright)
            return NULL;
        TreeNode* cur = new TreeNode(preorder[pleft]);  //前序的左端为root
        int i;
        for(i=ileft; i<iright; i++)     //找到前序的当前根在中序中的位置
            if(inorder[i]==cur->val)
                break;
        cur->left = helper(preorder, pleft+1, pleft+i-ileft, inorder, ileft, i-1);
        cur->right = helper(preorder, pleft+i-ileft+1, pright, inorder, i+1, iright);

        return cur;
    }
};

void preorder(TreeNode* root){
    if(root == NULL)
        return;
    cout << root->val << endl;
    preorder(root->left);
    preorder(root->right);
    return;
}

int main(){
    Solution test;
    TreeNode* res;
    int nums1[] = {3,9,20,15,7};
    int nums2[] = {9,3,15,20,7};
    vector<int> vec1(nums1, nums1+5);
    vector<int> vec2(nums2, nums2+5);
    res = test.buildTree(vec1, vec2);
    preorder(res);

    return 0;
}
