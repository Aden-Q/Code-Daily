// Valid Sudoku
// 用Vector实现二维数组
// 48.86%
// 这个题让我立志以后绝对不写垃圾代码了
// 期待二刷时的改变

#include <iosream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> count(10);
        int i, j, k;
        int row, col;
        
        //行遍历
        for(i=0;i<9;i++){
            //O(1)计数初始化
            for(k=0;k<9;k++)
                count[k+1]=1;
            for(j=0;j<9;j++){
                if(board[i][j] >= '0' && board[i][j] <= '9')
                    count[board[i][j]-'0']--;
            }
            //检查
            for(k=0;k<9;k++)
                if(count[k+1]<0)
                    return false;
        }
        
        //列遍历 
        for(i=0;i<9;i++){
            //O(1)计数初始化
            for(k=0;k<9;k++)
                count[k+1]=1;
            for(j=0;j<9;j++){
                if(board[j][i] >= '0' && board[j][i] <= '9')
                    count[board[j][i]-'0']--;
            }
            //检查
            for(k=0;k<9;k++)
                if(count[k+1]<0)
                    return false;
        }

        //方格遍历
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                //O(1)初始化
                for(k=0;k<9;k++)
                    count[k+1]=1;
                for(row = i*3;row<i*3+3;row++)
                    for(col = j*3;col<j*3+3;col++)
                        if(board[row][col]>='0' && board[row][col] <= '9')
                            count[board[row][col]-'0']--;
                for(k=0;k<9;k++)
                    if(count[k+1]<0)
                        return false;
            }
        }
        return true;
    }
};

int main(){
    Solution test;
    bool res;
    vector<vector<char>> vec(9);
    for(int i=0;i<9;i++)
        vec[i].resize(9);   //总感觉resize可能效率低下
    // 算了，不做测试了，输入麻烦

    res = test.isValidSudoku();

    return 0;
}
