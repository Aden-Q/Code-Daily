//Author:QZC
//Date:2018.4.27
#include "diary.h"
#include <algorithm>

int main()
{
	vector <Diary> My_Diary;		//�ռǱ�������ʼʱ��Ҫ���ļ��ж���
	Diary rdiary, wdiary;				//�����ռǶ���������¼һƪ�ռ�
	string date;
	string str;
	ifstream fin;
	streambuf *backup;
	ofstream fout;
	vector<string>::iterator iter_text;
	vector<Diary>::iterator iter_diary;
	int a[1000] = {0};			//�������飬������
	int i, j, k;				//�����±�
	int size;
	int flag_start, flag_end;
	int start_date, end_date;
	fin.open("diary.txt", ios::in);		//�Զ�ģʽ���ļ�
	while (!fin.eof())
	{
		rdiary.GetText().clear();		//�����һ�ε��ı�
		getline(fin, date);
		if (date == "")			//����ĩβ�Ļ��з����˳�
			break;
		rdiary.SetDate(date);
		getline(fin, str);
		while (str != ".")
		{
			rdiary.GetText().push_back(str);
			getline(fin, str);
		}
		rdiary.GetText().push_back(".");			//����һƪ�ռǺ���������
		My_Diary.push_back(rdiary);
	}
	fin.close();			//��ȡ������ر��ļ�

	i = 0;
	for (iter_diary = My_Diary.begin(); iter_diary != My_Diary.end(); iter_diary++)		//����ÿһƪ�ռ�
	{
		a[i] = stoi((*iter_diary).GetDate());
		i++;
	}
	size = i;		//��������
	sort(a, a + size);		//�������������

	cout << "Specify Start Date Or Not?  1 for Yes and 0 for No" << endl;
	cin >> flag_start;
	cout << "Specify End Date Or Not?  1 for Yes and 0 for No" << endl;
	cin >> flag_end;
	if (flag_start == 0 && flag_end == 0) {		//i j�ֱ��ʾ������������
		i = 0;
		j = size - 1;
	}
	else if (flag_start == 0 && flag_end == 1) {		//i j�ֱ��ʾ������������
		i = 0;
		cout << "Please Specify The End Date:" << endl;
		cin >> end_date;
		for (k = 0; k < size; k++)
			if (a[k] == end_date) {
				j = k;
				break;
			}
		if (k > size)			//��������˴���Ľ������ڣ���Ĭ�Ϸ��ʵ����һ��
			end_date = size - 1;
	}
	else if (flag_start == 1 && flag_end == 0) {		//i j�ֱ��ʾ������������
		cout << "Please Specify The Start Date:" << endl;
		cin >> start_date;
		for (k = 0; k < size; k++)
			if (a[k] == start_date) {
				i = k;
				break;
			}
		if (k > size)			//��������˴���Ľ������ڣ���Ĭ�Ϸ��ʵ����һ��
			start_date = 0;
		j = size - 1;
	}
	else if (flag_start == 1 && flag_end == 1) {		//i j�ֱ��ʾ������������
		cout << "Please Specify The Start Date:" << endl;
		cin >> end_date;
		for (k = 0; k < size; k++)
			if (a[k] == start_date) {
				i = k;
				break;
			}
		if (k > size)			//��������˴���Ľ������ڣ���Ĭ�Ϸ��ʵ����һ��
			end_date = 0;
		cout << "Please Specify The End Date:" << endl;
		cin >> end_date;
		for (k = 0; k < size; k++)
			if (a[k] == end_date) {
				j = k;
				break;
			}
		if (k > size)			//��������˴���Ľ������ڣ���Ĭ�Ϸ��ʵ����һ��
			end_date = size - 1;
	}
	if (i > j) {
		cout << "Error Input!!!" << endl;			//�����˴�������ڵ��¿�ʼ���ڴ��ڽ�������
		return 0;
	}
	//����i��j֮��������ռǲ����
	cout << "All Diaries Meeting Demands Are Listed Following By Order:" << endl;
	for (k = i; k <= j; k++) {
		for (iter_diary = My_Diary.begin(); iter_diary != My_Diary.end(); iter_diary++)		//�����ռǱ��е�ÿһƪ�ռ�
		{
			if (stoi((*iter_diary).GetDate()) == a[k]) {			//�ҵ����ռ�
				wdiary = *iter_diary;
				cout << wdiary.GetDate() << endl;
				for (iter_text = wdiary.GetText().begin(); iter_text != wdiary.GetText().end(); iter_text++)
				{
					cout << *iter_text << endl;
				}
				break;			//�ҵ�������������һ��ѭ��
			}
		}
	}

	return 0;
}