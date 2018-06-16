#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int N, i, j;
    int sum;
    cin >> N;
    string c;
    int w[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    int flag;
    int ill_count = 0;
    char X;
    vector<string> illegal;
    for (i = 0; i < N; i++)
    {
        sum = 0;
        flag = 0;
        cin >> c;
        for (j = 0; j < 17; j++)
        {
            if (c[j] - '0' >= 0 && c[j] - '0' <= 9)
                sum += (c[j] - '0') * w[j];
            else
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            illegal.push_back(c);
            ill_count++;
        }
        else
        {
            switch (sum % 11)
            {
            case (0):
                X = '1';
                break;
            case (1):
                X = '0';
                break;
            case (2):
                X = 'X';
                break;
            case (3):
                X = '9';
                break;
            case (4):
                X = '8';
                break;
            case (5):
                X = '7';
                break;
            case (6):
                X = '6';
                break;
            case (7):
                X = '5';
                break;
            case (8):
                X = '4';
                break;
            case (9):
                X = '3';
                break;
            case (10):
                X = '2';
                break;
            }
            if (X != c[17])
            {
                illegal.push_back(c);
                ill_count++;
            }
        }
    }
    if (ill_count == 0)
        cout << "All passed" << endl;
    else
    {
        for (i = 0; i < illegal.size(); i++)
            cout << illegal[i] << endl;
    }
    return 0;
}
