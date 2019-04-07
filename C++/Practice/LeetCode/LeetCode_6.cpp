// ZigZag Conversion
// Medium 注意两个点就行了，一个是只有一行的情况，一个是数组size的问题，还是不太会动态申请内存。vector其实不太好

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector< vector<char> >vec(numRows,vector<char>(1000,0));
        int row = 0;
        int col = 0;
        int fillflag = 0;
        int i, j;
        string res="";
        for(i=0;i<s.length();i++){
            vec[row][col] = s[i];
            if(fillflag == 0 && row == numRows-1)
                fillflag = 1;
            else if(fillflag == 1 && row == 0 && numRows != 1)
                fillflag = 0;
                
            if(fillflag == 0)
                row++;
            else{
                if(row>0)
                    row--;
                col++;
            }
        }
        
        for(i=0;i<numRows;i++)
            for(j=0;j<=col;j++)
                if(vec[i][j]!=0)
                    res += vec[i][j];

        return res;
    }
};

int main(){
    Solution test;
    string r;
    r = test.convert("ABC", 1);
    cout << r << endl;

    return 0;
}
