// 01 Matrix
// 简单BFS
// 23.53% time 0.36% space
// AC


#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    	queue<pair<int,int>> q;
    	int maxrow = matrix.size();
    	int maxcol = matrix[0].size();
        for(int i=0; i<maxrow; i++) {
        	for(int j=0; j<maxcol; j++) {
        		if(matrix[i][j] == 0)
        			continue;
        		int depth = -1;
        		int flag = 0;
        		q.push({i,j});
        		
	        	while(!q.empty()) {
	        		int size = q.size();
	        		depth++;
	        		for(int k=0; k<size; k++) {
		        		pair<int,int> node = q.front();
		        		q.pop();
		        		int row = node.first;
		        		int col = node.second;
		        		if(matrix[row][col] == 0) {
		        			flag = 1;
		        			break;
		        		}
		        		if(row>0)
		        			q.push({row-1,col});
		        		if(row<maxrow-1)
		        			q.push({row+1,col});
		        		if(col>0)
		        			q.push({row,col-1});
		        		if(col<maxcol-1)
		        			q.push({row,col+1});
	        		}

	        		if(flag == 1) {
	        			while(!q.empty())
	        				q.pop();
	        			break;
	        		}
	        	}

	        	matrix[i][j] = depth;
        	}
        }

        return matrix;
    }
};

int main() {


	return 0;
}