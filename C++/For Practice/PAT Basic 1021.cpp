#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{

    string a;
    cin >> a;
    int n = a.size();
    sort(a.begin(), a.end());
    int count = 0;
    int index = 0;
    char tmp;
    while (index < n)
    {
        cout << a[index] << ":";
        tmp = a[index];
        count = 0;
        while (tmp == a[index])
        {
            count++;
            index++;
        }
        cout << count << endl;
    }
    return 0;
}
