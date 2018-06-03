#include <iostream>

/*
    注意，这个题的负数输出形式中，负号是整体标志，而不是第一个数，这个容易理解错误
*/

using namespace std;

int main()
{
    string P, A, out;
    int g_p, s_p, k_p;
    int g_a, s_a, k_a;
    int g, s, k;
    cin >> P >> A;
    int index_1 = P.find('.');
    int index_2 = P.find('.', P.find('.') + 1);
    g_p = stoi(P.substr(0, index_1));
    s_p = stoi(P.substr(index_1 + 1, index_2));
    k_p = stoi(P.substr(index_2 + 1, P.size()));
    index_1 = A.find('.');
    index_2 = A.find('.', A.find('.') + 1);
    g_a = stoi(A.substr(0, index_1));
    s_a = stoi(A.substr(index_1 + 1, index_2));
    k_a = stoi(A.substr(index_2 + 1, A.size()));
    int sign = 1; //default positive
    if (g_p * 17 * 29 + s_p * 29 + k_p <= g_a * 17 * 29 + s_a * 29 + k_a)
    {
        g = g_a - g_p;
        s = s_a - s_p;
        k = k_a - k_p;
    }
    else
    {
        sign = -1;
        g = g_p - g_a;
        s = s_p - s_a;
        k = k_p - k_a;
    }
    if (k < 0)
    {
        k += 29;
        s -= 1;
    }
    if (s < 0)
    {
        s += 17;
        g -= 1;
    }
    if(sign == -1)
        cout<<'-';
    cout << g << '.' << s << '.' << k << endl;
    return 0;
}