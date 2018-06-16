/*
	Author:QZC
 */

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main()
{
	long int N, p;
	long int i;
	int num;
	long int mulp, maxnum = 0;
	vector<long int> percum;
	vector<long int>::iterator iter, iter_end;
	cin >> N >> p;
	for(i=0;i<N;i++)
	{
		cin >> num;
		percum.push_back(num);
	}
	sort(percum.begin(), percum.end());
	for(iter=percum.begin();iter!=percum.end();iter++)
	{
		mulp = *iter * p;
		for(iter_end = iter;iter_end!=percum.end();iter_end++)
		{
			if(*iter_end>mulp)
				break;
		}
		if(iter_end-iter > maxnum)
			maxnum = iter_end - iter;
	}
	cout << maxnum << endl;
	return 0;
}