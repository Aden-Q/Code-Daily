#pragma once
#include <iostream>

using namespace std;

class IndexOutofBounds {};

template <class T>
class Vector {
public:
	Vector();		// create an empty vector
	Vector(int size);	// create a vector of size elements
	Vector(const Vector& r);	// copy ctor
	virtual ~Vector();
	T& operator[](int index);
	// return the specified element, throws exception when index <0 or >=m_nSize
	int size();		// return the size of the vector
	int inflate(int addSize);	// expand the storage to m_nSize+addSize, return the new size
private:
	T * m_pElements;
	int m_nSize;
};

template <class T>
Vector<T>::Vector() //implicit constructer
{
	m_nSize = 0;
	m_pElements = nullptr;
	cout << "Default constructor called." << endl;
}

template <class T>
Vector<T>::Vector(int size) //explicit constructer
{
	m_nSize = size;
	m_pElements = new T[size];
	for (int i = 0; i < size; i++)
		(m_pElements)[i] = 0;		//initialization with 0 value
	cout << "Constructor with size parameter called." << endl;
}

template <class T>
Vector<T>::Vector(const Vector &r) //copy constuctor
{
	int i;
	delete[] this->m_pElements;
	m_pElements = new T[r.m_nSize];
	m_nSize = r.m_nSize;
	for (i = 0; i < m_nSize; i++)
		m_pElements[i] = (r.m_pElements)[i];		//copy by element
	cout << "Copy constructor called." << endl;
}

template <class T>
Vector<T>::~Vector() //default destructor
{
	if (m_pElements == nullptr)
		delete m_pElements;
	else
		delete[] m_pElements;
	cout << "Destructor called." << endl;		//indicator
}

template <class T>
T& Vector<T>::operator[](int index)			//throw exception if index out of range
{
	IndexOutofBounds indicator;
	if (index < 0 || index >= m_nSize)
		throw indicator;
	cout << "Normal index!";
	return *(this->m_pElements + index);
}

template <class T>
int Vector<T>::size() //called implicitly, return a member variable
{
	cout << "Size funciton called." << endl;
	return m_nSize;
}

template <class T>
int Vector<T>::inflate(int addsize) //called explicitly, inflaing Vector instance(resize)
{
	int i;
	T * newptr;
	if (m_nSize + addsize < 0)
		return -1;			//error return value
	newptr = new T[m_nSize + addsize];
	if (addsize >= 0)
	{
		for (i = 0; i < m_nSize; i++)		//zero initialization
			newptr[i] = m_pElements[i];
		for (i = m_nSize; i < m_nSize + addsize; i++)		//zero initialization
			newptr[i] = 0;
	}
	else
	{
		for (i = 0; i < m_nSize + addsize; i++)		//zero initialization
			newptr[i] = m_pElements[i];
	}

	delete[] m_pElements;
	m_pElements = newptr;
	m_nSize = m_nSize + addsize;
	cout << "Inflate function called." << endl;
	return this->m_nSize;
}