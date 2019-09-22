// Number of Equivalent Domino Pairs
// 74.58% time, 100.00% space
// Accepted

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
private:
    map<pair<int, int> , int> hashmap;
public:
    int numEquivDominoPairs(vector< vector<int> >& dominoes) {
        int count = 0;
        vector<int> temp;
        for (int i=0; i<dominoes.size(); i++) {
            // form a orderde pair first as a key of hashing
            int first = dominoes[i][0];
            int second = dominoes[i][1];
            pair<int, int> p(min(first, second), max(first, second));
            if (hashmap.count(p) != 0) {
                hashmap[p]++;
                count += hashmap[p];
            }
            else
                hashmap[p] = 0;
        }

        return count;
    }
};


int main(){
    vector< vector<int> > dominoes = {{1,2}, {2,1}, {3,4}, {5,6}}; 
    Solution test;
    int res = test.numEquivDominoPairs(dominoes);
    cout << res << endl;

    return 0;
}
