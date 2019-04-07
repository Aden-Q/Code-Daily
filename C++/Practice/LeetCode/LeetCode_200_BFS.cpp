// Number of Islands
// 走一个n*m遍历，每次遍历的时候如果是1，把所有邻接的1都给访问完(一次深搜)，每次遍历的时候只要管是不是'1'就行了
// 98.93%

#include <iostream>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        if(grid.size()==0)
            return 0;
        int i,j;
        int count = 0;
        for(i=0;i<grid.size();i++)
            for(j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    DFS(grid, i, j);        //做一次深搜，把相邻的1全部给访问掉，并用0去覆盖
                    count++;
                }
            }
        
        return count;
    }

    void DFS(vector<vector<char> >& grid, int row, int col){
        grid[row][col] = '0';       //先把它填成0，表示被访问过，也为了防止下次再被访问
        if(row-1>-1 && grid[row-1][col]=='1')
            DFS(grid, row-1, col);      //如果左边位置存在并且是未被访问的1，那么以它为根做一次深搜
        if(row+1<grid.size() && grid[row+1][col]=='1')
            DFS(grid, row+1, col);
        if(col-1>-1 && grid[row][col-1]=='1')
            DFS(grid, row, col-1);
        if(col+1<grid[0].size() && grid[row][col+1]=='1')
            DFS(grid, row, col+1);
    }
};

int main(){

}
