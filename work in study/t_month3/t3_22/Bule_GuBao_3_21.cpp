#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int arr[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	do
	{
		for(int k = 1; k < 10; k++)
		{
			int num1 = arr[0]*10000 + arr[1]*1000 + arr[2]*100 + arr[3]*10 + arr[4];
			int num2 = arr[4]*10000 + arr[3]*1000 + arr[2]*100 + arr[1]*10 + arr[0];
			
			if(num1 * k == num2)
			{
				cout<< arr[0] << arr[1] << arr[2] << arr[3] << arr[4] << "?£º" << k;
				return 0;
			}
		}
	}while(next_permutation(arr,arr+10));
	return 0;
}
