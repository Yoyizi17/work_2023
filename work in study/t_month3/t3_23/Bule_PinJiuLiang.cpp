#include<iostream>

using namespace std;

int main()
{
	for(int i = 20; i >= 0; i--)
	{
		int all_p = i;
		
		float n1, n2, n3, n4;//n������ÿ�ֺȵľ���
		int out1, out2, out3;//out����ÿ��֮��ʣ�������
		
		for(out1 = 19; out1 > 0; out1--)
		{
			for(out2 = out1-1; out2 > 0; out2--)
			{
				for(out3 = out2-1; out3 > 0; out3--)
				{
					n1 = 1/static_cast<float>(all_p);
					n2 = 1/static_cast<float>(out1);
					n3 = 1/static_cast<float>(out2);
					n4 = 1/static_cast<float>(out3);
					if(n1 + n2 + n3 + n4 == 1.0 && n1 < n2 && n2 < n3 && n3 < n4)
						cout<< all_p << "," << out1 << "," << out2 << "," << out3 << endl;
				}
			}
		}
	}
	return 0;
}
