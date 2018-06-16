#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    long int a, b, c;
    int D;
    cin >> a >> b >> D;
    c = a + b;
    vector<int> t;
    vector<int>::reverse_iterator riter;
    long int m;
    if (c == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    else
    {
        while (c != 0)
        {
            m = c % D;
            c /= D;
            t.push_back(m);
        }
    }
    for (riter = t.rbegin(); riter != t.rend(); riter++)
        cout << *riter;
    cout << endl;

    return 0;
}
