// Populating Next Right Pointers in Each Node
// 做next right链接，思路是用postorder和二维数组去做好层次遍历，然后再
// 根据得到的数组去处理point指针，数组存的应该是TreeNode*
// 实现起来比较简单，做一次level order traverse就行了
// 没想到了跑了99.47%，感觉是很naive的做法啊

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
