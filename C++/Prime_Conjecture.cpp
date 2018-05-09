#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool Prime(int data);

int main()
{
    int N;
    int i;
    int count = 0;
    cin >> N;
    for(i=3;i+2<=N;i+=2)
    {
        if(Prime(i) == true && Prime(i+2) == true)
            count++;
    }
    cout << count << endl;
    return 0;
}

bool Prime(int data)
{
    if (data == 2)
        return true;
    else if (data == 1)
        return false;
    int i;
    int top = floor(sqrt(data));
    for (i = 2; i <= top; i++)
        if (data % i == 0)
            break;
    if (i <= top)
        return false;
    else
        return true;
}