#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Gcd(int x, int y)
{
	int ret = 0;
	for(int i = 0; i < (x>y?x:y); i++)
	{
		if(x%i ==0 &&y%i ==0)
			ret = i;
	}
	return ret;
}
int main()
{
    int len = 3;
    vector<int> arr{4,6,9};

    sort(arr.begin(),arr.end());
    
    int ret = 0;
    while(Gcd(arr[0], arr[len-1]) != 1)
    	ret++;
    ret += len-1;
    
    cout<< ret;
    
    return 0;
}
