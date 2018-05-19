#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    long int C1, C2;
    int CLK = 100;
    cin >> C1 >> C2;
    int total_s = round(double(C2 - C1) / CLK + 1e-4);
    int s, m, h;
    s = total_s % 60;
    total_s /= 60;
    m = total_s % 60;
    total_s /= 60;
    h = total_s % 60;
    total_s /= 60;
    cout << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << m << ":" << setw(2) << setfill('0') << s << endl;

    return 0;
}
