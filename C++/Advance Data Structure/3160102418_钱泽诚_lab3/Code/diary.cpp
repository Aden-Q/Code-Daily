//Author:QZC
//Date:2018.4.27
#include "diary.h"

void Diary::SetDate(string d)		//�����ռ�ʱ��
{
	date = d;
}

string Diary::GetDate()			//�����ռ�ʱ��
{
	return date;
}

void Diary::PdAdd()			//����ռ����ݣ����д洢
{
	string str;
	getline(cin, str);		//�ӱ�׼�����ȡһ�е����ݵ�str��
	while (str != ".")		//���Ƿ��ȡ���ı��Ľ�����־
	{
		text.push_back(str);	//���һ���ı�
		getline(cin, str);		//��ȡ��һ���ı�
	}
	text.push_back(".");			//���"."��Ϊ�ռ�֮��ķָ���
}

vector<string>  &Diary::GetText()
{
	return text;
}

void Diary::PdList()
{

}

void Diary::PdRemove()
{

}

void Diary::PdShow()
{

}