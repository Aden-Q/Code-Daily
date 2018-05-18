#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string t;
    string a, b;
    cin >> t;
    int index = t.find("E");
    int i;
    for (i = 0; i < index; i++)
        a += t[i];
    for (i = index + 1; i < t.size(); i++)
        b += t[i];
    if (a[0] == '-')
        cout << a[0];
    int k;
    int count = 0;
    k = stoi(b);
    if (k < 0)
    {
        k = -k;
        cout << "0.";
        for (i = 0; i < k - 1; i++)
            cout << "0";
        for (i = 1; i < a.size(); i++)
            if (a[i] != '.')
                cout << a[i];
    }
    else if (k > 0)
    {
        if (k > a.size() - 4)
        {
            for (i = 1; i < a.size(); i++)
                if (a[i] != '.')
                {
                    cout << a[i];
                    count++;
                }
            for (i = 0; i < k - count + 1; i++)
                cout << '0';
        }
        else
        {
            for (i = 1; i <= k + 2; i++)
                if (a[i] != '.')
                {
                    cout << a[i];
                    count++;
                }
            cout << '.';
            for (i = k+3; i < a.size(); i++)
                cout << a[i];
        }
    }
    else
    {
        for (i = 1; i < a.size(); i++)
            cout << a[i];
    }
    cout << endl;

    return 0;
}
