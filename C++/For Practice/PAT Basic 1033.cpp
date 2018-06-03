#include <iostream>

using namespace std;

/*
    一个大坑：用cin无法读取空行，用getline才可以，因此用cin会卡一个测试点！！！
*/

int main()
{
    string bad_key;
    string str_in;
    string str_out;
    getline(cin, bad_key);
    getline(cin, str_in);
    int i;
    bool up = true;
    if (bad_key.find('+') != -1)
        up = false;
    for (i = 0; i < bad_key.size(); i++)
    {
        if (bad_key[i] >= 'A' && bad_key[i] <= 'Z')
            bad_key += bad_key[i] - 'A' + 'a';
    }
    for (i = 0; i < str_in.size(); i++)
    {
        if (up == true)
        {
            if (bad_key.find(str_in[i]) == -1)
                str_out += str_in[i];
        }
        else
        {
            if (bad_key.find(str_in[i]) == -1 && !(str_in[i]>='A' && str_in[i] <='Z'))
                str_out += str_in[i];
        }
    }
    cout << str_out << endl;
    return 0;
}
