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
	vector<string>::iterator iter_text;
	vector<Diary>::iterator iter_diary;
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

	cout << "Please Specify The Date Of Diary You Want To Search(e.g:20180404): " << endl;
	cin >> date;
	getchar();
	for (iter_diary = My_Diary.begin(); iter_diary != My_Diary.end();)		//�����ռǱ��е�ÿһƪ�ռ�
	{
		if (date == (*iter_diary).GetDate())		//���ռǱ����Ѿ�����������ڵ��ռ��ˣ�������ɾ��
			break;
		else
			iter_diary++;
	}
	if (iter_diary == My_Diary.end())
		cout << "No Diary Satisfies Your Need!" << endl;
	else {			//������ռ�
		for (iter_text = (*iter_diary).GetText().begin(); iter_text != (*iter_diary).GetText().end(); iter_text++)
			cout << *iter_text << endl;
	}

	return 0;
}