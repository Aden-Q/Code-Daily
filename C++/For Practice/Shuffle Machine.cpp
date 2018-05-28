#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string card;
    string shuffle_set[60];
    string initial_set[60]; //index from 1 to 54
    int data[60];
    int i, j, K, t;
    for (i = 1; i <= 54; i++)
    {
        if (i <= 13 * 1)
            initial_set[i] = "S" + to_string(i);
        else if (i > 13 && i <= 26)
            initial_set[i] = "H" + to_string(i - 13);
        else if (i > 26 && i <= 39)
            initial_set[i] = "C" + to_string(i - 26);
        else if (i > 39 && i <= 52)
            initial_set[i] = "D" + to_string(i - 39);
        else if (i > 52 && i <= 54)
            initial_set[i] = "J" + to_string(i - 52);
    }
    //for (i = 1; i <= 54; i++)
    //    cout << " " << initial_set[i];
    //cout << endl;
    cin >> K;
    for (i = 1; i <= 54; i++)
    {
        cin >> data[i];
        shuffle_set[data[i]] = initial_set[i];
    }
    for (i = 1; i < K; i++)
    {
        for (j = 1; j <= 54; j++)
            initial_set[j] = shuffle_set[j];
        for (t = 1; t <= 54; t++)
            shuffle_set[data[t]] = initial_set[t];
    }
    cout << shuffle_set[1];
    for (j = 2; j <= 54; j++)
        cout << " " << shuffle_set[j];
    cout << endl;

    return 0;
}
