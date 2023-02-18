#include<iostream>
#include<Queue>
using namespace std;

struct Taxi
{
	int reach_time;//加入队列时的时间
	//int leave_time;//离开队列时的时间
	int boarding = 90;//乘客上车时间，且总是90s

	Taxi(int reach)//初始化入队时间
	{
		reach_time = reach;
	}
};

struct Queuing
{
	int reach_num = 0;    //加入队列的车数
	int leave_num = 0;    //成功载客的车数
	int qsize = 0;        //队列的实时长度
	int qtop = 200;       //队列的最大长度
	int all_wait_time = 0;//总的出租车等待时长
	int can_t_reach = 0;  //因为最大长度而无法加入队列的出租车
	queue<Taxi> airplane; //使用一个队列结构对象，处理数据

	void Distory()        //销毁乘车区数据
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
	//想要测试的次数
	int test_num;
	//想要测试的时长
	double test_time;
	//平均每小时达到机场的车数
	int aver_h_taxi;

	//n次等待时间，n次选择排队的车数
	double n_wait_time = 0, n_reach_num = 0;

	Queuing Qu;//创建一个乘车区的对象

	cout << "请输入你要测试的次数，想要测试的时长(单位：小时），平均每小时到达机场的车数" << endl;
	cin >> test_num >> test_time >> aver_h_taxi;
	cout << "测试开始！" << endl;

	//根据输入初始化数据
	int aver_s_taxi = test_time * 3600;//将小时转换为秒，方便运算
	double p_reach = static_cast<double>(aver_h_taxi) / 3600;//每秒司机选择加入队列的概率
	srand((unsigned int)time(NULL));

	int tn = test_num;//将使用t作为test_num的分身
	while (tn--)
	{
		int tt = aver_s_taxi;//将使用tt作为test_time的分身
		while (tt--)
		{
			//随机出一个0~1之间的小数并与"入队"概率p_reach比较，得数比p_reach代表司机想要入队
			if (static_cast<double>(rand() % 101) / 100 <= p_reach)
			{
				if (Qu.qsize >= 200)//如果乘车区已满-》
				{
					Qu.can_t_reach++;
				}
				else
				{
					Qu.airplane.push(Taxi(tt));//向队尾插入一个匿名出租车对象
					Qu.qsize++;//乘车区实时长度+1
					Qu.reach_num++;//加入乘车区的车数+1
				}
			}

			//检查头车乘客是否已经上车，若没有，乘客上车时间-1；否则记录等待时间，加入总的等待时间，并出队, 并成功载客的车数+1
			if (Qu.airplane.empty())//如果队列为空则跳过本次循环
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
	cout << test_num << "次模拟中平均进行排队的出租车数量： " << n_reach_num / test_num << "辆" << endl;
	cout << test_num << "次模拟中出租车平均等待时间： " << (n_wait_time / n_reach_num) / 60 << "分钟" << endl;

	return 0;
}

//int main()
//{
//	//想要测试的次数
//	int test_num;
//	//想要测试的时长
//	double test_time;
//	//平均每小时达到机场的车数
//	int aver_h_taxi;
//
//	//平均等待时间，<test_time>时长内平均选择排队的车数
//	double aver_wait_time, aver_reach_num;
//
//	Queuing Qu;//创建一个乘车区的对象
//
//	cout << "请输入你要测试的次数，想要测试的时长(单位：小时），平均每小时到达机场的车数" << endl;
//	cin >> test_num >> test_time >> aver_h_taxi;
//	cout << "请输入乘车区最大容量" << endl;
//	cin >> Qu.qtop;
//	cout << "测试开始！" << endl;
//
//	//根据输入初始化数据
//	int aver_s_taxi = test_time * 3600;//将小时转换为秒，方便运算
//	double p_reach = static_cast<double>(aver_h_taxi) / 3600;//每秒司机选择加入队列的概率
//	srand((unsigned int)time(NULL));
//
//	while (test_num--)
//	{
//		int tt = aver_s_taxi;//将使用tt作为test_time的分身
//		while (tt--)
//		{
//			//随机出一个0~1之间的小数并与"入队"概率p_reach比较，得数比p_reach代表司机想要入队
//			if (static_cast<double>(rand() % 101) / 100 <= p_reach)
//			{
//				if (Qu.qsize >= 200)//如果乘车区已满-》
//				{
//					Qu.can_t_reach++;
//				}
//				else
//				{
//					Qu.airplane.push(Taxi(tt));//向队尾插入一个匿名出租车对象
//					Qu.qsize++;//乘车区实时长度+1
//					Qu.reach_num++;//加入乘车区的车数+1
//				}
//			}
//			
//			//检查头车乘客是否已经上车，若没有，乘客上车时间-1；否则记录等待时间，加入总的等待时间，并出队, 并成功载客的车数+1
//			if (Qu.airplane.empty())//如果队列为空则跳过本次循环
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
//		cout << "进行排队的出租车数量： " << Qu.reach_num << endl;
//		cout << "成功载客的出租车数量： " << Qu.leave_num << endl;
//		cout << "由于场地限制不能排队的出租车的数量：" << Qu.can_t_reach << endl;
//		cout << "出租车平均等待时间： " << static_cast<double>(Qu.all_wait_time) / Qu.reach_num << endl;
//		Qu.Distory();
//	}
//
//	return 0;
//}