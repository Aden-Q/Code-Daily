#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int N;
    string c;
    cin >> N;
    cin >> c;
    int i, k, j, t;
    k = floor(sqrt((N + 1) / 2));
    int count = N - (2 * k * k - 1);
    for (i = 0; i < k; i++)
    {
        for (t = 0; t < i; t++)
            cout << " ";
        for (j = 0; j < 2 * (k - i) - 1; j++)
            cout << c;
        cout << endl;
    }
    for (i = k - 2; i >= 0; i--)
    {
        for (t = 0; t < i; t++)
            cout << " ";
        for (j = 0; j < 2 * (k - i) - 1; j++)
            cout << c;
        cout << endl;
    }
    cout << count << endl;
}