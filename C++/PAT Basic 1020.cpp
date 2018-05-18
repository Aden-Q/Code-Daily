#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    int N;
    double D;
    map<double, int> t; //map store to value
    map<double, int>::reverse_iterator riter;
    cin >> N >> D; //kinds and needs
    int i;
    double j;
    vector<double> m, n;
    double total_store = 0;
    double total_val = 0;
    for (i = 0; i < N; i++) //push into sorts
    {
        cin >> j;
        m.push_back(j);
    }
    for (i = 0; i < N; i++) //push into value
    {
        cin >> j;
        n.push_back(j);
    }
    for (i = 0; i < N; i++)
    {
        t.insert(pair<double, double>(double(n[i]) / double(m[i]), m[i]));
    }
    // for (riter = t.rbegin(); riter != t.rend(); riter++)
    //   cout << riter->first << "  " << riter->second << endl;
    riter = t.rbegin(); //reverse iterator
    while (total_store < D && riter != t.rend())
    {
        if (total_store + riter->second < D)
        {
            total_store += riter->second;
            total_val += riter->first * riter->second;
        }
        else
        {
            total_val += riter->first * (D - total_store);
            break;
        }
        riter++;
    }
    cout << setprecision(2);
    cout.setf(ios::fixed, ios::floatfield);
    cout << total_val << endl;
    return 0;
}