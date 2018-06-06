#include <iostream>
#include <map>

using namespace std;

//time exceed version
/*
int main()
{
    map<int, int> score_count;
    int score;
    int N, K;
    int i;
    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin >> score;
        if (score_count.count(score) == 0)
        {
            score_count[score] = 1;
        }
        else
            score_count[score]++;
    }
    cin >> K;
    if (K > 0)
    {
        cin >> score;
        if (score_count.count(score) == 0)
            cout << "0";
        else
            cout << score_count[score];
        for (i = 1; i < K; i++) //next
        {
            cin >> score;
            if (score_count.count(score) == 0)
                cout << " 0";
            else
                cout << " " << score_count[score];
        }
        cout << endl;
    }
    return 0;
}
*/

int main()
{
    int a[101] = {0};
    int N, K;
    int i;
    int score;
    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin >> score;
        a[score]++;
    }
    cin >> K;
    if (K > 0)
    {
        cin >> score;
        cout << a[score];
        for (i = 1; i < K; i++)
        {
            cin >> score;
            cout << " " << a[score];
        }
        cout << endl;
    }
    return 0;
}