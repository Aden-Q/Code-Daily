// Open the lock
// 广搜3.8%，不想说什么

#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string init = "0000";
        set<string> used;   // BFS的排除空间
        queue<string> q;    // 搜索队列
        int qsize;
        used.insert(init);
        q.push(init);
        int step = 0;
        int i,j,k;
        string cur, next, tmp;         // 每次从队列中取出要处理的那个元素
        if(count(deadends.begin(),deadends.end(),init)>0)
            return -1;

        while(!q.empty()){
            step++;
            qsize = q.size();
            for(i=0;i<qsize;i++){
                cur = q.front();
                q.pop();
                for(j=0;j<4;j++){       // 否则把相邻字符串入队
                    for(k=-1;k<=1;k++){
                        tmp = cur;
                        char& c = tmp[j];
                        c = (c+k+10-'0') % 10 + '0';
                        if(tmp == target)
                            return step;
                        else if(used.count(tmp) == 0 && count(deadends.begin(), deadends.end(), tmp) == 0){
                            q.push(tmp);
                            used.insert(tmp);
                        }
                    }
                }
            }
        }

        return -1;
    }
};

int main(){
    //string ss[] = {"0000"};
    string ss[] = {"0201","0101","0102","1212","2002"};
    //string ss[] = {"8887","8889","8878","8898","8788","8988","7888","9888"};
    //string ss[] = {"8888"};
    vector<string> vec(ss,ss+5);
    int k;
    //k = count(vec.begin(), vec.end(),"0201");
    //cout << k << endl;
    //string s = "8888";
    //string s = "0009";
    
    string s = "0202";
    int res;
    Solution test;
    res = test.openLock(vec, s);
    cout << res << endl;

    return 0;
}
