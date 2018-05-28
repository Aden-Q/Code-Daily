//Author:QZC
//Date:2018.4.27
#ifndef DIARY_H
#define DIARY_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Diary					//一篇日记
{
private:
    string date;            //日记的日期，格式如"20180512"
    vector<string> text;    //日记的内容，按行存储
public:
    void SetDate(string date);  //添加日记时间
	string GetDate();			//返回日记的时间
	void PdAdd();           //添加日记内容
	vector<string>  &GetText();		//返回日记的内容，传递引用，防止大量的内存复制
	void PdList();
	void PdRemove();
	void PdShow();
};

#endif
