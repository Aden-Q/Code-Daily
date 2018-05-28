#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int flag_judge(int cur_time, int time_flag[]);		//改变时间点的标志并返回debug次数

int main() {
	int H, N, T0;			//比赛时间，题目数量，读题时间
	int total_time;			//花费总时间，分钟制
	int cur_time;			//当前花费的时间，分钟制，即accept time
	char problems[9][21];	//读取问题名
	int t[9];				//估计的解题时间
	int d[9];				//调试时间
	int i;
	int time_flag[6];		//[0]-[5]表示是否已经过了那个时间点
	int d_time;				//当前解题需要的调试次数
	int order[9];			//访问题目的顺序
	int best_order[9];		//最佳访问顺序,用于打印输出
	int up;				//做到第几个题目
	int best_time;	//最佳解题时间
	int max_num;		//最多的解题数目

	while (1) {
		scanf("%d", &H);
		if (H == -1)			//-1为结束标志，之后加外循环
			break;
		//for (i = 0; i < 9; i++)			//初始化访问顺序
		//	order[i] = i;
		
		scanf("%d %d", &N, &T0);
		for (i = 0; i < N; i++)
			scanf("%s %d %d", problems[i], t + i, d + i);
		max_num = 0;
		best_time = 10000;

		do {
			cur_time = 0;		//初始化
			total_time = 0;
			time_flag[1] = time_flag[2] = time_flag[3] = time_flag[4] = time_flag[5] = 0;
			time_flag[0] = 1;
			up = 0;

			cur_time += T0;			//读题时间

			for (i = 0; i < N; i++) {			//遍历所有的题目
				cur_time += t[order[i]];			//得到当前题做完的第一次提交时间
				d_time = flag_judge(cur_time, time_flag);			//得到当前需要的调试次数
				cur_time += d_time * d[order[i]];			//这个题AC的完成时间
				if (cur_time <= H * 60) {			//如果这个题AC不会超时，计入总时间
					total_time += cur_time + 20 * d_time;
					up++;
				}
				else
					break;		//超时则直接跳出循环，当前题无效了
			}

			if (up > max_num) {		//做的题目更多了，则无条件赋值
				best_time = total_time;
				max_num = up;
				for (i = 0; i < up; i++)		//做up个题目
					best_order[i] = order[i];
			}
			else if (up == max_num) {		//如果解题数量相等
				if (total_time < best_time) {		//如果当前总时间更少，记下总时间以及做题顺序
					best_time = total_time;
					for (i = 0; i < up; i++)		//做up个题目
						best_order[i] = order[i];
				}
			}
			else
				;
		} while (next_permutation(order, order + N));		//改变做题顺序并进行下一次循环

		printf("Total Time = %d\n", best_time);
		for (i = 0; i < max_num; i++)
			printf("%s\n", problems[best_order[i]]);
	}

	return 0;
}

int flag_judge(int cur_time, int time_flag[]) {
	if (cur_time > 60)			//已经过了第一个小时
		time_flag[1] = 1;
	if (cur_time > 120)			//已经过了第二个小时
		time_flag[2] = 1;
	if (cur_time > 180)			//已经过了第三个小时
		time_flag[3] = 1;
	if (cur_time > 240)			//已经过了第四个小时
		time_flag[4] = 1;
	if (cur_time > 300)			//已经过了五小时
		time_flag[5] = 1;
	return time_flag[1] + time_flag[2] + time_flag[3] + time_flag[4] + time_flag[5];	//返回所需要的调试次数
}