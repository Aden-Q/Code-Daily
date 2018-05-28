//Author:QZC
//Date:2018.4.27
#include "diary.h"

void Diary::SetDate(string d)		//设置日记时间
{
	date = d;
}

string Diary::GetDate()			//返回日记时间
{
	return date;
}

void Diary::PdAdd()			//添加日记内容，按行存储
{
	string str;
	getline(cin, str);		//从标准输入读取一行的内容到str中
	while (str != ".")		//看是否读取到文本的结束标志
	{
		text.push_back(str);	//添加一行文本
		getline(cin, str);		//读取下一行文本
	}
	text.push_back(".");			//输出"."作为日记之间的分隔符
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