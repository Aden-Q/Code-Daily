// 98.30% time and 84.59% space
// first time dfs, reference
// AC faster than BFS

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // grid[i][j] == '1' or '0'
        int count = 0;
        if(grid.empty())
            return count;

        for(int i=0; i<grid.size(); i++)
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }

            }

        return count;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == '0')
            return;
        else
            grid[i][j] = '0';           // sink the island
        dfs(grid, i+1, j);              // sink all the adjacent islands
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
};

int main(){
    Solution test;

    return 0;
}