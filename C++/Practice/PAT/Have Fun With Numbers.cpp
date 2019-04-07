#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string data;
    int carry;
    int i;
    int d;
    int t;
    vector<char> data_vector;
    vector<char> data_double;
    cin >> data;
    for (i = data.size() - 1; i >= 0; i--)
        data_vector.push_back(data[i]);
    vector<char>::iterator iter;
    vector<char>::iterator flag;
    carry = 0;
    for (iter = data_vector.begin(); iter != data_vector.end(); iter++)
    {
        if (*iter < '5')
        {
            data_double.push_back('0' + (*iter - '0') * 2 + carry);
            carry = 0;
        }
        else
        { //*iter >= '5'
            d = (*iter - '0') * 2 - 10;
            data_double.push_back('0' + d + carry);
            carry = 1;
        }
    }
    if (carry == 1)
        data_double.push_back('1');
    t = 1; //Yes
    for (iter = data_double.begin(); iter != data_double.end(); iter++)
    {
        flag = find(data_vector.begin(), data_vector.end(), *iter);
        if (flag == data_vector.end()) //fail to find
        {
            cout << "No" << endl;
            t = 0;
            break;
        }
        if (t == 0)
            break;
    }
    if (t == 1)
    {
        for (iter = data_vector.begin(); iter != data_vector.end(); iter++)
        {
            flag = find(data_double.begin(), data_double.end(), *iter);
            if (flag == data_double.end()) //fail to find
            {
                cout << "No" << endl;
                t = 0;
                break;
            }
            if (t == 0)
                break;
        }
    }
    if (t == 1)
        cout << "Yes" << endl;
    for (iter = data_double.end() - 1; iter != data_double.begin() - 1; iter--)
        cout << *iter;
    cout << endl;
    return 0;
}