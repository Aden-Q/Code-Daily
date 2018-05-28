//Author:QZC
//Date:2018.4.27
#include "diary.h"
#include <algorithm>

int main()
{
	vector <Diary> My_Diary;		//日记本，程序开始时需要从文件中读入
	Diary rdiary, wdiary;				//创建日记对象，用来记录一篇日记
	string date;
	string str;
	ifstream fin;
	streambuf *backup;
	ofstream fout;
	vector<string>::iterator iter_text;
	vector<Diary>::iterator iter_diary;
	int a[1000] = {0};			//日期数组，排序用
	int i, j, k;				//迭代下标
	int size;
	int flag_start, flag_end;
	int start_date, end_date;
	fin.open("diary.txt", ios::in);		//以读模式打开文件
	while (!fin.eof())
	{
		rdiary.GetText().clear();		//清空上一次的文本
		getline(fin, date);
		if (date == "")			//读到末尾的换行符是退出
			break;
		rdiary.SetDate(date);
		getline(fin, str);
		while (str != ".")
		{
			rdiary.GetText().push_back(str);
			getline(fin, str);
		}
		rdiary.GetText().push_back(".");			//读完一篇日记后推入容器
		My_Diary.push_back(rdiary);
	}
	fin.close();			//读取结束后关闭文件

	i = 0;
	for (iter_diary = My_Diary.begin(); iter_diary != My_Diary.end(); iter_diary++)		//遍历每一篇日记
	{
		a[i] = stoi((*iter_diary).GetDate());
		i++;
	}
	size = i;		//数组容量
	sort(a, a + size);		//对数组进行排序

	cout << "Specify Start Date Or Not?  1 for Yes and 0 for No" << endl;
	cin >> flag_start;
	cout << "Specify End Date Or Not?  1 for Yes and 0 for No" << endl;
	cin >> flag_end;
	if (flag_start == 0 && flag_end == 0) {		//i j分别表示索引的上下限
		i = 0;
		j = size - 1;
	}
	else if (flag_start == 0 && flag_end == 1) {		//i j分别表示索引的上下限
		i = 0;
		cout << "Please Specify The End Date:" << endl;
		cin >> end_date;
		for (k = 0; k < size; k++)
			if (a[k] == end_date) {
				j = k;
				break;
			}
		if (k > size)			//如果输入了错误的结束日期，则默认访问到最后一个
			end_date = size - 1;
	}
	else if (flag_start == 1 && flag_end == 0) {		//i j分别表示索引的上下限
		cout << "Please Specify The Start Date:" << endl;
		cin >> start_date;
		for (k = 0; k < size; k++)
			if (a[k] == start_date) {
				i = k;
				break;
			}
		if (k > size)			//如果输入了错误的结束日期，则默认访问到最后一个
			start_date = 0;
		j = size - 1;
	}
	else if (flag_start == 1 && flag_end == 1) {		//i j分别表示索引的上下限
		cout << "Please Specify The Start Date:" << endl;
		cin >> end_date;
		for (k = 0; k < size; k++)
			if (a[k] == start_date) {
				i = k;
				break;
			}
		if (k > size)			//如果输入了错误的结束日期，则默认访问到最后一个
			end_date = 0;
		cout << "Please Specify The End Date:" << endl;
		cin >> end_date;
		for (k = 0; k < size; k++)
			if (a[k] == end_date) {
				j = k;
				break;
			}
		if (k > size)			//如果输入了错误的结束日期，则默认访问到最后一个
			end_date = size - 1;
	}
	if (i > j) {
		cout << "Error Input!!!" << endl;			//输入了错误的日期导致开始日期大于结束日期
		return 0;
	}
	//访问i到j之间的所有日记并输出
	cout << "All Diaries Meeting Demands Are Listed Following By Order:" << endl;
	for (k = i; k <= j; k++) {
		for (iter_diary = My_Diary.begin(); iter_diary != My_Diary.end(); iter_diary++)		//访问日记本中的每一篇日记
		{
			if (stoi((*iter_diary).GetDate()) == a[k]) {			//找到该日记
				wdiary = *iter_diary;
				cout << wdiary.GetDate() << endl;
				for (iter_text = wdiary.GetText().begin(); iter_text != wdiary.GetText().end(); iter_text++)
				{
					cout << *iter_text << endl;
				}
				break;			//找到并输出后进入下一轮循环
			}
		}
	}

	return 0;
}