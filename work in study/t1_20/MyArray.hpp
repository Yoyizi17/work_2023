#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

template<typename T>
class MyArray
{
private:
	T* m_phead;
	int m_size;
	int m_top;

public:
	MyArray(int top)//有参构造函数
	{
		this->m_phead = new T[top];
		this->m_size = 0;
		this->m_top = top;
	}

	MyArray(MyArray& A)//拷贝构造函数
	{
		this->m_size = A.m_size;
		this->m_top = A.m_top;

		this->m_phead = new T[A.m_top];
		for (int i = 0; i < A.m_size; i++)
		{
			this->m_phead[i] = A.m_phead[i];
		}

	}

	MyArray& operator=(const MyArray& A)//赋值运算符重载
	{
		if (this->m_phead != NULL)
			delete[]this->m_phead;

		this->m_size = A.m_size;
		this->m_top = A.m_top;

		T* newarr = new T[A.m_top];
		assert(newarr);
		for (int i = 0; i < A.m_size; i++)
		{
			newarr[i] = A.m_phead[i];
		}
		this->m_phead = newarr;

		return *this;
	}
	T& operator[](int i)
	{
		if (i > this->m_size)
		{
			cout << "数组访问越界" << endl;
			exit(-1);
		}
		return this->m_phead[i];
	}

	//增
	void PushBack(const T& newp)
	{
		if (this->m_size == this->m_top) //容量满了的情况
		{
			T* newarr = new T[this->m_top * 2];
			assert(newarr);

			for (int i = 0; i < this->m_size; i++)
			{
				newarr[i] = this->m_phead[i];
			}
			delete[]this->m_phead;
			this->m_phead = newarr;
		}

		this->m_phead[this->m_size] = newp;
		this->m_size++;
	}
	//删
	void PokeBack()
	{
		if(this->m_size>0)
		    this->m_size--;
	}
	//查
	//改

	int GetArrSize()
	{
		return this->m_size;
	}
	int GetArrTop()
	{
		return this->m_top;
	}

	~MyArray()
	{
		if (this->m_phead != NULL)
			delete[]m_phead;
	}
};

//template<typename T>
//void MyArray<typename T>::AddArray<typename T>(T newp)
