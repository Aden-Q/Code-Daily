#include "head.h"
#include <iostream>

using namespace std;

int main()
{
	//The following statement test both constructors and "size" member fucntion
	Vector<int> test1;		//test default constructor
	Vector<int> test2(5);		//test construcot with size specified
	Vector<int> test3(test2);	//test copy constructor

	try
	{
		cout << test3[3] << endl;		//in range, so output 0(initialization value)
		cout << test3[5] << endl;		//index out of range, exception catched
	}
	catch (IndexOutofBounds)
	{
		cerr << "Index Out Of Bounds!!!" << endl;
		//to avoid trouble when testing, this line is noted
		//exit(1);
	}
	
	int size = test3.size();	//test "size" function
	cout << "Old size: " << size << endl;
	int inflate_size = test3.inflate(5);
	cout << "New size: " << inflate_size << endl;
	return 0;
}