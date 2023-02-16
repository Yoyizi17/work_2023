#include<iostream>
#include<Queue>
using namespace std;

struct Taxi
{
	int reach_time;//�������ʱ��ʱ��
	//int leave_time;//�뿪����ʱ��ʱ��
	int boarding = 90;//�˿��ϳ�ʱ�䣬������90s

	Taxi(int reach)//��ʼ�����ʱ��
	{
		reach_time = reach;
	}
};

struct Queuing
{
	int reach_num = 0;    //������еĳ���
	int leave_num = 0;    //�ɹ��ؿ͵ĳ���
	int qsize = 0;        //���е�ʵʱ����
	int qtop = 200;       //���е���󳤶�
	int all_wait_time = 0;//�ܵĳ��⳵�ȴ�ʱ��
	int can_t_reach = 0;  //��Ϊ��󳤶ȶ��޷�������еĳ��⳵
	queue<Taxi> airplane; //ʹ��һ�����нṹ���󣬴�������

	void Distory()        //���ٳ˳�������
	{
		reach_num = 0;   
		leave_num = 0;   
		qsize = 0;        
		qtop = 200;      
		all_wait_time = 0;
		can_t_reach = 0;
		while (!airplane.empty())airplane.pop();
	}
};

int main()
{
	//��Ҫ���ԵĴ���
	int test_num;
	//��Ҫ���Ե�ʱ��
	double test_time;
	//ƽ��ÿСʱ�ﵽ�����ĳ���
	int aver_h_taxi;

	//n�εȴ�ʱ�䣬n��ѡ���Ŷӵĳ���
	double n_wait_time = 0, n_reach_num = 0;

	Queuing Qu;//����һ���˳����Ķ���

	cout << "��������Ҫ���ԵĴ�������Ҫ���Ե�ʱ��(��λ��Сʱ����ƽ��ÿСʱ��������ĳ���" << endl;
	cin >> test_num >> test_time >> aver_h_taxi;
	cout << "���Կ�ʼ��" << endl;

	//���������ʼ������
	int aver_s_taxi = test_time * 3600;//��Сʱת��Ϊ�룬��������
	double p_reach = static_cast<double>(aver_h_taxi) / 3600;//ÿ��˾��ѡ�������еĸ���
	srand((unsigned int)time(NULL));

	int tn = test_num;//��ʹ��t��Ϊtest_num�ķ���
	while (tn--)
	{
		int tt = aver_s_taxi;//��ʹ��tt��Ϊtest_time�ķ���
		while (tt--)
		{
			//�����һ��0~1֮���С������"���"����p_reach�Ƚϣ�������p_reach����˾����Ҫ���
			if (static_cast<double>(rand() % 101) / 100 <= p_reach)
			{
				if (Qu.qsize >= 200)//����˳�������-��
				{
					Qu.can_t_reach++;
				}
				else
				{
					Qu.airplane.push(Taxi(tt));//���β����һ���������⳵����
					Qu.qsize++;//�˳���ʵʱ����+1
					Qu.reach_num++;//����˳����ĳ���+1
				}
			}

			//���ͷ���˿��Ƿ��Ѿ��ϳ�����û�У��˿��ϳ�ʱ��-1�������¼�ȴ�ʱ�䣬�����ܵĵȴ�ʱ�䣬������, ���ɹ��ؿ͵ĳ���+1
			if (Qu.airplane.empty())//�������Ϊ������������ѭ��
				continue;
			if (Qu.airplane.front().boarding > 0)
				Qu.airplane.front().boarding--;
			else
			{
				Qu.all_wait_time += Qu.airplane.front().reach_time - tt;
				Qu.airplane.pop();
				Qu.leave_num++;
				Qu.qsize--;
			}
		}

		n_reach_num += Qu.reach_num;
		n_wait_time += Qu.all_wait_time;
		Qu.Distory();
	}
	cout << test_num << "��ģ����ƽ�������Ŷӵĳ��⳵������ " << n_reach_num / test_num << "��" << endl;
	cout << test_num << "��ģ���г��⳵ƽ���ȴ�ʱ�䣺 " << (n_wait_time / n_reach_num) / 60 << "����" << endl;

	return 0;
}

//int main()
//{
//	//��Ҫ���ԵĴ���
//	int test_num;
//	//��Ҫ���Ե�ʱ��
//	double test_time;
//	//ƽ��ÿСʱ�ﵽ�����ĳ���
//	int aver_h_taxi;
//
//	//ƽ���ȴ�ʱ�䣬<test_time>ʱ����ƽ��ѡ���Ŷӵĳ���
//	double aver_wait_time, aver_reach_num;
//
//	Queuing Qu;//����һ���˳����Ķ���
//
//	cout << "��������Ҫ���ԵĴ�������Ҫ���Ե�ʱ��(��λ��Сʱ����ƽ��ÿСʱ��������ĳ���" << endl;
//	cin >> test_num >> test_time >> aver_h_taxi;
//	cout << "������˳����������" << endl;
//	cin >> Qu.qtop;
//	cout << "���Կ�ʼ��" << endl;
//
//	//���������ʼ������
//	int aver_s_taxi = test_time * 3600;//��Сʱת��Ϊ�룬��������
//	double p_reach = static_cast<double>(aver_h_taxi) / 3600;//ÿ��˾��ѡ�������еĸ���
//	srand((unsigned int)time(NULL));
//
//	while (test_num--)
//	{
//		int tt = aver_s_taxi;//��ʹ��tt��Ϊtest_time�ķ���
//		while (tt--)
//		{
//			//�����һ��0~1֮���С������"���"����p_reach�Ƚϣ�������p_reach����˾����Ҫ���
//			if (static_cast<double>(rand() % 101) / 100 <= p_reach)
//			{
//				if (Qu.qsize >= 200)//����˳�������-��
//				{
//					Qu.can_t_reach++;
//				}
//				else
//				{
//					Qu.airplane.push(Taxi(tt));//���β����һ���������⳵����
//					Qu.qsize++;//�˳���ʵʱ����+1
//					Qu.reach_num++;//����˳����ĳ���+1
//				}
//			}
//			
//			//���ͷ���˿��Ƿ��Ѿ��ϳ�����û�У��˿��ϳ�ʱ��-1�������¼�ȴ�ʱ�䣬�����ܵĵȴ�ʱ�䣬������, ���ɹ��ؿ͵ĳ���+1
//			if (Qu.airplane.empty())//�������Ϊ������������ѭ��
//				continue;
//			if(Qu.airplane.front().boarding > 0)
//				Qu.airplane.front().boarding--;
//			else
//			{
//				Qu.all_wait_time += Qu.airplane.front().reach_time - tt;
//				Qu.airplane.pop();
//				Qu.leave_num++;
//				Qu.qsize--;
//			}
//		}
//		cout << "�����Ŷӵĳ��⳵������ " << Qu.reach_num << endl;
//		cout << "�ɹ��ؿ͵ĳ��⳵������ " << Qu.leave_num << endl;
//		cout << "���ڳ������Ʋ����Ŷӵĳ��⳵��������" << Qu.can_t_reach << endl;
//		cout << "���⳵ƽ���ȴ�ʱ�䣺 " << static_cast<double>(Qu.all_wait_time) / Qu.reach_num << endl;
//		Qu.Distory();
//	}
//
//	return 0;
//}