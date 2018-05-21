#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int i, N;
    vector<string> name;
    vector<string> birthday;
    string n, b;
    string name_old, name_young;
    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin >> n >> b;
        name.push_back(n);
        birthday.push_back(b);
    }
    int y, m, d;
    int min_y, min_m, min_d, max_y, max_m, max_d;
    min_y = 2014;
    min_m = 12;
    min_d = 32;
    max_y = 1814;
    max_m = 0;
    max_y = 5;
    int count = 0;
    for (i = 0; i < N; i++)
    {
        y = stoi(birthday[i].substr(0, 4));
        m = stoi(birthday[i].substr(5, 2));
        d = stoi(birthday[i].substr(8, 2));
        if (y > 2014 || (y == 2014 && m > 9) || (y == 2014 && m == 9 && d > 6)) //future
            continue;
        else if (y < 1814 || (y == 1814 && m < 9) || (y == 1814 && m == 9 && d < 6)) //over 200 years old
            continue;
        else
        {
            count++;
            if (y < min_y)
            {
                min_y = y;
                min_m = m;
                min_d = d;
                name_old = name[i];
            }
            else if (y == min_y)
            {
                if (m < min_m || (m == min_m && d < min_d))
                {
                    min_y = y;
                    min_m = m;
                    min_d = d;
                    name_old = name[i];
                }
            }
            if (y > max_y)
            {
                max_y = y;
                max_m = m;
                max_d = d;
                name_young = name[i];
            }
            else if (y == max_y)
            {
                if (m > max_m || (m == max_m && d > max_d))
                {
                    max_y = y;
                    max_m = m;
                    max_d = d;
                    name_young = name[i];
                }
            }
        }
    }
    cout << count << " " << name_old << " " << name_young << endl;
    return 0;
}
