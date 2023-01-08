#include<iostream>
using namespace std;

//class Cube
//{
//private:
//
//	int m_L;
//	int m_W;
//	int m_H;
//
//public:
//
//	void Setcube(int x,int y,int z)
//	{
//		m_L = x;
//		m_W = y;
//		m_H = z;
//	}
//	int* Getcube()
//	{
//		int* cube = new int[3];
//		cube[0] = m_L;
//		cube[1] = m_W;
//		cube[2] = m_H;
//
//		return cube;
//	}
//};
//
//bool IsSameCube(int* a, int* b)
//{
//	for (int i = 0; i < 3; i++)
//	{
//		if (a[i] != b[i])
//			return false;
//	}
//	return true;
//}

class Person
{
public:
	Person()
	{
		cout << "Person 调用构造函数" << endl;
	}

	~Person()
	{
		cout << "Person 调用析构函数" << endl;
	}
};

int main()
{
	//Cube a;
	//a.Setcube(2, 3, 4);
	//Cube b;
	//b.Setcube(2, 3, 5);
	//cout << IsSameCube(a.Getcube(), b.Getcube()) << endl;
	Person p;
	return 0;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    if (numRows == 0)
        return;

    //开辟一个二维数组
    int** arr = (int**)malloc(numRows * sizeof(int*));
    for (int i = 1; i <= numRows; i++)
    {
        arr[i - 1] = (int*)malloc(i * sizeof(int));
    }

    //赋值杨辉三角
    for (int i = 0; i < numRows; i++)
    {
        arr[i][0] = 1;
        if (arr[i][i] != 0)
            arr[i][i] = 1;
    }

    for (int i = 2; i < numRows; i++)
    {
        for (int j = 1; j < i; j++)
        {
            arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j]);
        }
    }


    *returnSize = numRows;
    *returnColumnSizes = malloc(sizeof(int) * numRows);
    for (int i = 0; i < numRows; ++i)
    {
        (*returnColumnSizes)[i] = i + 1;
    }


    return arr;
}