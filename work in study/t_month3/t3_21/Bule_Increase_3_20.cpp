#include<iostream>
using namespace std;

int main()
{
	int x = 10;
	int y = 89;
	
	for(int min = 1; min <= 120; min++)
	{
		if(min%4 == 0)
			y *= 2;
		if(min%6 == 0)
		{
			x *= 2;
		}
		
		if(min%2 == 1)
			y -= x;
	}
	cout<< "x:" << x << "\ny:" << y << endl;
	return 0;
}
