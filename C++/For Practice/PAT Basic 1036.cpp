#include <iostream>

using namespace std;

/*
    一个超级超级大坑，输入字符可能为空，用cin无法读取空字符，会卡一个测试点
*/

int main()
{
    int N;
    char c;
    int i, j;
    cin >> N;
    getchar();
    c = getchar();
    for (i = 0; i < N; i++)
        cout << c;
    for (i = 0; i < N * 1.0 / 2 - 2; i++)
    {
        cout << endl;
        cout << c;
        for (j = 0; j < N - 2; j++)
            cout << " ";
        cout << c;
    }
    cout << endl;
    for (i = 0; i < N; i++)
        cout << c;
    cout << endl;
    return 0;
}