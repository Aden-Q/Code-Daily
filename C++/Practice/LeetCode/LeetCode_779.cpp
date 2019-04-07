// 100.00% time, 100.00% space
// AC
// tail recursion


#include <iostream>

using namespace std;

class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N == 1 && K ==1)
        	return 0;

        if(K%2 == 1)
        	return kthGrammar(N-1, (K+1)/2);
        else
        	return !kthGrammar(N-1, K/2);

        return 1;
    }
};


int main(void) {
	Solution test;
	cout << test.kthGrammar(4, 5) << endl;
	
	return 0;
}