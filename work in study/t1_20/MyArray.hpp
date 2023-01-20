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
	MyArray(int top)//�вι��캯��
	{
		this->m_phead = new T[top];
		this->m_size = 0;
		this->m_top = top;
	}

	MyArray(MyArray& A)//�������캯��
	{
		this->m_size = A.m_size;
		this->m_top = A.m_top;

		this->m_phead = new T[A.m_top];
		for (int i = 0; i < A.m_size; i++)
		{
			this->m_phead[i] = A.m_phead[i];
		}

	}

	MyArray& operator=(const MyArray& A)//��ֵ���������
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
			cout << "�������Խ��" << endl;
			exit(-1);
		}
		return this->m_phead[i];
	}

	//��
	void PushBack(const T& newp)
	{
		if (this->m_size == this->m_top) //�������˵����
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
	//ɾ
	void PokeBack()
	{
		if(this->m_size>0)
		    this->m_size--;
	}
	//��
	//��

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
