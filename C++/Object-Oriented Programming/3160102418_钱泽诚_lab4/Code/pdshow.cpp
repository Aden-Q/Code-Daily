//Author:QZC
//Date:2018.4.27
#include "diary.h"

int main()
{
	vector <Diary> My_Diary;		//日记本，程序开始时需要从文件中读入
	Diary rdiary, wdiary;				//创建日记对象，用来记录一篇日记
	string date;
	string str;
	ifstream fin;
	vector<string>::iterator iter_text;
	vector<Diary>::iterator iter_diary;
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

	cout << "Please Specify The Date Of Diary You Want To Search(e.g:20180404): " << endl;
	cin >> date;
	getchar();
	for (iter_diary = My_Diary.begin(); iter_diary != My_Diary.end();)		//访问日记本中的每一篇日记
	{
		if (date == (*iter_diary).GetDate())		//若日记本中已经存在这个日期的日记了，把他先删除
			break;
		else
			iter_diary++;
	}
	if (iter_diary == My_Diary.end())
		cout << "No Diary Satisfies Your Need!" << endl;
	else {			//输出该日记
		for (iter_text = (*iter_diary).GetText().begin(); iter_text != (*iter_diary).GetText().end(); iter_text++)
			cout << *iter_text << endl;
	}

	return 0;
}