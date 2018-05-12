#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Gas
{
    float P; //price per gas
    int D;   //distance
};

inline bool comparison(Gas a, Gas b)
{
    return a.D < b.D;
}
void Print_info(Gas gas[], int N);

int main()
{
    float C;    //capacity of the tank
    float D;    //total distance
    float Davg; //distance per gas
    int N;    //nummber of gas stations
    int i, j;
    float cur_dis = 0;           //current distance away from start point
    float cur_cost = 0;          //current cost from start point
    float cur_cap = 0;           //current size of gas
    bool flag_station = false; //indicate whether there is a station, default "No"
    bool flag_cheaper = false; //indicate whether there is a cheaper station, defalut "No"
    float P_max;
    int index_max;

    Gas gas[500];

    cin >> C >> D >> Davg >> N;
    for (i = 0; i < N; i++)
        cin >> gas[i].P >> gas[i].D; //read in price and distance for each station
    sort(gas, gas + N, comparison);
    //Print_info(gas, N);
    for (i = 0; i < N;) //handle each station
    {
        if(gas[0].D!=0)
            break;
        P_max = 100000;
        while (gas[i].D < cur_dis) //skip several stations
            i++;
        if (i >= N)
            break;
        for (j = i + 1; j < N; j++)
        {
            if (cur_dis + C * Davg >= gas[j].D)
            {
                flag_station = true;     //there is a station
                if (gas[j].P < gas[i].P) //j is cheaper and is the nearest
                {
                    if ((gas[j].D - gas[i].D) / Davg > cur_cap)
                    {
                        cur_cost += ((gas[j].D - gas[i].D) / Davg - cur_cap) * gas[i].P;
                        cur_cap = 0;
                    }
                    else
                    {
                        cur_cost += 0;
                        cur_cap -= (gas[j].D - gas[i].D) / Davg;
                    }
                    cur_dis = gas[j].D; //run to station j
                    flag_cheaper = true;
                    break;
                }
            }
        }
        if (flag_cheaper == true) //there is cheaper station
        {
            flag_cheaper = false; //reset
            flag_station = false;
            continue;
        }
        else if (flag_station == true) //there are several stations but all expensive
        {
            if (cur_dis + C * Davg >= D) //approach destination directily
            {
                if ((D - cur_dis) / Davg < cur_cap)
                    cur_cost += 0;
                else
                    cur_cost += (D - cur_dis) / Davg * gas[i].P;
                cur_dis = D;
                break; //end game
            }
            else
            {
                for (j = i + 1; j < N; j++)
                    if (gas[j].P < P_max && cur_dis + C * Davg >= gas[j].D)
                    {
                        P_max = gas[j].P;
                        index_max = j;
                    }
                cur_cost += (C - cur_cap) * gas[i].P; //add to full
                cur_cap = C - (gas[index_max].D - cur_dis) / Davg;
                cur_dis = gas[index_max].D;
            }
            flag_station = false;
        }
        else //there is no station
        {
            if (cur_dis + C * Davg >= D)
            {
                if ((D - cur_dis) / Davg < cur_cap)
                    cur_cost += 0;
                else
                    cur_cost += ((D - cur_dis) / Davg - cur_cap) * gas[i].P;
                cur_dis = D;
            }
            else
            {

                cur_cost += (C - cur_cap) * gas[i].P;
                cur_dis += C * Davg;
                break;
            }
        }
    }
    cout << setiosflags(ios::fixed) << setprecision(2);
    if (cur_dis < D)
        cout << "The maximum travel distance = " << cur_dis << endl;
    else
        cout << cur_cost << endl;

    return 0;
}

void Print_info(Gas gas[], int N)
{
    int i;
    cout << endl;
    for (i = 0; i < N; i++)
        cout << gas[i].P << " " << gas[i].D << endl;
}
