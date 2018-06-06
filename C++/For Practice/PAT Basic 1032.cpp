#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int i;
    int index, cur_score;
    int max_score = 0;
    vector<int> score(100005);
    for (i = 0; i < N; i++)
    {
        cin >> index >> cur_score;
        score[index] += cur_score;
    }
    for (i = 1; i <= N; i++)
    {
        if (score[i] > max_score)
        {
            max_score = score[i];
            index = i;
        }
    }
    cout << index << " " << max_score << endl;
    return 0;
}