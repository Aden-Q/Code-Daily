#include <iostream>


using namespace std;


int main()
{
	string a, b, c;
	cin >> a >>b;
	int i;
	for(i = 0; i< a.size(); i++)
	{
		if(b.find(a[i]) == -1)
		{
			if(a[i]>='a' &&a[i]<='z')
				a[i] = a[i] - 'a' + 'A';
			if(c.find(a[i]) == -1)
				c += a[i];
		}
	}
	cout << c << endl;
	return 0;
}