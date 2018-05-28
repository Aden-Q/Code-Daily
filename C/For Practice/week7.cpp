#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int flag_judge(int cur_time, int time_flag[]);		//�ı�ʱ���ı�־������debug����

int main() {
	int H, N, T0;			//����ʱ�䣬��Ŀ����������ʱ��
	int total_time;			//������ʱ�䣬������
	int cur_time;			//��ǰ���ѵ�ʱ�䣬�����ƣ���accept time
	char problems[9][21];	//��ȡ������
	int t[9];				//���ƵĽ���ʱ��
	int d[9];				//����ʱ��
	int i;
	int time_flag[6];		//[0]-[5]��ʾ�Ƿ��Ѿ������Ǹ�ʱ���
	int d_time;				//��ǰ������Ҫ�ĵ��Դ���
	int order[9];			//������Ŀ��˳��
	int best_order[9];		//��ѷ���˳��,���ڴ�ӡ���
	int up;				//�����ڼ�����Ŀ
	int best_time;	//��ѽ���ʱ��
	int max_num;		//���Ľ�����Ŀ

	while (1) {
		scanf("%d", &H);
		if (H == -1)			//-1Ϊ������־��֮�����ѭ��
			break;
		//for (i = 0; i < 9; i++)			//��ʼ������˳��
		//	order[i] = i;
		
		scanf("%d %d", &N, &T0);
		for (i = 0; i < N; i++)
			scanf("%s %d %d", problems[i], t + i, d + i);
		max_num = 0;
		best_time = 10000;

		do {
			cur_time = 0;		//��ʼ��
			total_time = 0;
			time_flag[1] = time_flag[2] = time_flag[3] = time_flag[4] = time_flag[5] = 0;
			time_flag[0] = 1;
			up = 0;

			cur_time += T0;			//����ʱ��

			for (i = 0; i < N; i++) {			//�������е���Ŀ
				cur_time += t[order[i]];			//�õ���ǰ������ĵ�һ���ύʱ��
				d_time = flag_judge(cur_time, time_flag);			//�õ���ǰ��Ҫ�ĵ��Դ���
				cur_time += d_time * d[order[i]];			//�����AC�����ʱ��
				if (cur_time <= H * 60) {			//��������AC���ᳬʱ��������ʱ��
					total_time += cur_time + 20 * d_time;
					up++;
				}
				else
					break;		//��ʱ��ֱ������ѭ������ǰ����Ч��
			}

			if (up > max_num) {		//������Ŀ�����ˣ�����������ֵ
				best_time = total_time;
				max_num = up;
				for (i = 0; i < up; i++)		//��up����Ŀ
					best_order[i] = order[i];
			}
			else if (up == max_num) {		//��������������
				if (total_time < best_time) {		//�����ǰ��ʱ����٣�������ʱ���Լ�����˳��
					best_time = total_time;
					for (i = 0; i < up; i++)		//��up����Ŀ
						best_order[i] = order[i];
				}
			}
			else
				;
		} while (next_permutation(order, order + N));		//�ı�����˳�򲢽�����һ��ѭ��

		printf("Total Time = %d\n", best_time);
		for (i = 0; i < max_num; i++)
			printf("%s\n", problems[best_order[i]]);
	}

	return 0;
}

int flag_judge(int cur_time, int time_flag[]) {
	if (cur_time > 60)			//�Ѿ����˵�һ��Сʱ
		time_flag[1] = 1;
	if (cur_time > 120)			//�Ѿ����˵ڶ���Сʱ
		time_flag[2] = 1;
	if (cur_time > 180)			//�Ѿ����˵�����Сʱ
		time_flag[3] = 1;
	if (cur_time > 240)			//�Ѿ����˵��ĸ�Сʱ
		time_flag[4] = 1;
	if (cur_time > 300)			//�Ѿ�������Сʱ
		time_flag[5] = 1;
	return time_flag[1] + time_flag[2] + time_flag[3] + time_flag[4] + time_flag[5];	//��������Ҫ�ĵ��Դ���
}