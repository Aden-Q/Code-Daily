//Author:QZC
//Date:2018.4.27
#include "diary.h"

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
	int flag = 0;			//return value flag
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

	cout << "Please Specify The Date Of Diary You Want To Remove(e.g:20180404): " << endl;
	cin >> date;
	getchar();
	for (iter_diary = My_Diary.begin(); iter_diary != My_Diary.end();)		//�����ռǱ��е�ÿһƪ�ռ�
	{
		if (date == (*iter_diary).GetDate()) {		//���ռǱ����Ѿ�����������ڵ��ռ��ˣ�������ɾ��
			iter_diary = My_Diary.erase(iter_diary);		//��������ɾ�����ռ�
			flag = 1;
		}
		else
			iter_diary++;
	}

	//�ѱ�׼����ض����ļ�"diary.txt"
	fout.open("diary.txt", ios::out);			//��дģʽ���ļ�
	backup = cout.rdbuf();
	cout.rdbuf(fout.rdbuf());
	for (iter_diary = My_Diary.begin(); iter_diary != My_Diary.end(); iter_diary++)		//�����ռǱ��е�ÿһƪ�ռ�
	{
		wdiary = *iter_diary;
		cout << (*iter_diary).GetDate() << endl;
		for (iter_text = wdiary.GetText().begin(); iter_text != wdiary.GetText().end(); iter_text++)
		{
			cout << *iter_text << endl;
		}
	}
	cout.rdbuf(backup);			//cout�ض���ص���׼���
	fout.close();

	if (flag == 1) {
		cout << "Remove Successfully!!!" << endl;
		return 0;		//remove sucessfully
	}
	else {
		cout << "Remvoe Failed!!!" << endl;
		return -1;		//fail
	}
}