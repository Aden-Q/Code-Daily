// Perfect Squares
// BFS implementation with Queuei
// 33.13% time and 3.31% space beats...
// sadness...

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        queue<int> remain;
        remain.push(n);
        vector<int> psquare; 
        int step = 0;
        int temp;
        int size;
        bool rflag = false;

        
        for(int i=1; i*i<=n; i++)
            psquare.push_back(i*i);
        
        while(!rflag){
            step++;
            size = remain.size();
            for(int i=0; i<size; i++){
                temp = remain.front();
                remain.pop();
                
                for(int j=0; j<psquare.size(); j++){
                    if(psquare[j]>temp)
                        break;
                    else if(psquare[j]==temp)
                        rflag = true;
                    else{
                        remain.push(temp-psquare[j]);
                    }
                }

                if(rflag)
                    break;
            }
        }
        
        return step;
    }
};


int main(){
    Solution test;
    cout << "n = 12: " << test.numSquares(12) << endl;
    cout << "n = 13: " << test.numSquares(13) << endl;
    cout << "n = 1: " << test.numSquares(1) << endl;
    return 0;
}
