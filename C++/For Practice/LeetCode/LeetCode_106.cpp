// Construct Binary Tree from Inorder and Postorder Traversal

#include <iostream>
#include <vector>

using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }

    TreeNode* helper(vector<int>& inorder, int ileft, int iright, vector<int>& postorder, int pleft, int pright){
        if(ileft>iright || pleft>pright)    //确保不空
            return NULL;
        TreeNode* cur = new TreeNode(postorder[pright]);    //用后序的右端作为根
        int i;
        for(i=ileft;i<=iright;i++)
            if(inorder[i]==cur->val)
                break;      //在中序中找到根的索引
        cur->left = helper(inorder, ileft, i-1, postorder, pleft, pleft+i-ileft-1); //中序左子树的后序遍历和中序遍历
        cur->right = helper(inorder, i+1, iright, postorder, pleft+i-ileft, pright-1); //中序右子树的后序遍历和中序遍历
        return cur;        
    }
};

void preorder(TreeNode *root){
    if(root==NULL)
        return;
    else{
        cout << root->val << endl;
        preorder(root->left);
        preorder(root->right);
    }
    return;
}

int main(){
    Solution test;
    int nums1[] = {9,3,15,20,7};
    int nums2[] = {9,15,7,20,3};
    vector<int> vec1(nums1, nums1+5);
    vector<int> vec2(nums2, nums2+5);

    TreeNode* root = test.buildTree(vec1, vec2);
    preorder(root);

    return 0;
}
