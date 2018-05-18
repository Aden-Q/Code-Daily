#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int i, j;
    int val;
    vector<int> t;
    vector<int>::iterator iter;
    for (i = 0; i < 10; i++)
    {
        cin >> val;
        t.push_back(val);
    }
    for (i = 1; i < t.size(); i++)
    {
        if (t[i] != 0)
        {
            cout << i;
            t[i]--;
            break;
        }
    }
    for (i = 0; i < t.size(); i++)
    {
        for (j = 0; j < t[i]; j++)
            cout << i;
    }
    cout << endl;
    return 0;
}
