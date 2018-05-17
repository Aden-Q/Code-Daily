#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(int a, int b);

int main() //using reverse_iterator
{
    string str, nstr;
    string f_str, b_str;
    int f_int, b_int, n_int;
    cin >> str;
    deque<char> d, ne;
    deque<char>::iterator iter;
    deque<char>::reverse_iterator riter;
    int i;
    for (i = 0; i < 4 - str.size(); i++)
        d.push_back('0');
    for (i = 0; i < str.size(); i++)
        d.push_back(str[i]);

    while (1)
    {
        sort(d.begin(),d.end(),compare);
        f_str = b_str = "";
        ne.clear();
        for (iter = d.begin(); iter != d.end(); iter++)
            f_str += *iter;
        for (riter = d.rbegin(); riter != d.rend(); riter++)
            b_str += *riter;
        f_int = stoi(f_str);
        b_int = stoi(b_str);
        n_int = f_int - b_int;
        nstr = to_string(n_int);
        for (i = 0; i < 4 - nstr.size(); i++)
            ne.push_back('0');
        for (i = 0; i < nstr.size(); i++)
            ne.push_back(nstr[i]);
        d = ne;
        cout << f_str << " - " << b_str << " = ";
        for (iter = d.begin(); iter != d.end(); iter++)
            cout << *iter;
        cout << endl;
        if (nstr == "0" || nstr == "6174")
            break;
    }

    return 0;
}

bool compare(int a, int b)
{
    return a > b;
}