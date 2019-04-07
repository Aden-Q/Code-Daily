// Flood Fill
// 应该就是一个简单队列的BFS
// 20.52% time and 0.81% space
// AC

#include <iostream>
#include <queus>

using namespace std;

class Solution {
private:
	queue<pair<int,int>> pixels;
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.empty())
        	return image;
        if(sr > image.size() || sc > image[0].size())
        	return image;

        int maxrow = image.size();
        int maxcol = image[0].size();
        int color = image[sr][sc];
        int row = sr;
        int col = sc;

        if(color == newColor)
        	return image;

        pixels.push({sr,sc});
        while(!pixels.empty()) {
        	pair<int,int> node = pixels.front();
        	row = node.first;
        	col = node.second;
        	pixels.pop();
        	image[row][col] = newColor;
        	if(row-1>=0 && image[row-1][col]==color)
        		pixels.push({row-1,col});
        	if(row+1<maxrow && image[row+1][col]==color)
        		pixels.push({row+1,col});
        	if(col-1>=0 && image[row][col-1]==color)
        		pixels.push({row,col-1});
        	if(col+1<maxcol && image[row][col+1]==color)
        		pixels.push({row,col+1});
        }

        return image;
    }
};

int main() {


	return 0;
}