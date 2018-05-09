#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int N, M;
    int data[10];
    int i, j;
    int temp;
    cin >> N;
    cin >> M;
    for (i = 0; i < N; i++)
        cin >> data[i];
    for (i = 0; i < M; i++)
    {
        temp = data[N - 1];
        for (j = N - 1; j > 0; j--)
            data[j] = data[j - 1];
        data[0] = temp;
    }
    cout << data[0];
    for (i = 1; i < N; i++)
        cout << " " << data[i];
    cout << endl;
    return 0;
}