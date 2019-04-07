// Populating Next Right Pointers in Each Node II
// 这个是非满二叉树，另外一个是满二叉树
// 和1是一样的做法，完全不用直接AC改哈哈哈哈

#include <iostream>
#include <vector>

using namespace std;


// Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    vector<vector<TreeLinkNode*> > res;
    void connect(TreeLinkNode *root) {
        traverse(root, 0);
        for(int i=0;i<res.size();i++)
            for(int j=0;j<res[i].size();j++){
                if(j+1<res[i].size())       //不写else是因为next被初始化为NULL了
                    (res[i][j])->next = res[i][j+1];
            }
        return;
    }

    void traverse(TreeLinkNode* cur, int depth){
        if(cur == NULL)
            return;
        if(depth >= res.size()){
            vector<TreeLinkNode*> newvec;
            newvec.push_back(cur); //推入指针，因为后面要根据此节点建表
            res.push_back(newvec);
        }
        else
            res[depth].push_back(cur);  //不用新建一个维度
        traverse(cur->left, depth+1);
        traverse(cur->right, depth+1);
        return;
    }
};

int main(){
    Solution test;
    TreeLinkNode* root = new TreeLinkNode(1);
    TreeLinkNode* cur1 = new TreeLinkNode(2);
    TreeLinkNode* cur2 = new TreeLinkNode(3);
    root->left = cur1;
    root->right = cur2;
    test.connect(root);

    if(root->next==NULL)
        cout << 1 << endl;
    if(root->left->next == NULL)
        cout << 1 << endl;
    cout << root->left->next->val << endl;

    return 0;
}
