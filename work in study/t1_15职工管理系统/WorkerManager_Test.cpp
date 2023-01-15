#include"WorkerManager.h"
#include"Worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
int main()
{
	//AbstractWorker* w = new Boss(1, "张三风", 6);
	//w->ShowInfo();

	WorkManager wm;
	wm.ShowMenu();//打印菜单;

	int input;
	cout << "请选择：" << endl;
	do
	{
		cin >> input;
		switch (input)
		{
		case 0://退出系统
			break;
		case 1://增加职工
			wm.AddWork(wm);
			cout << "添加完毕" << endl;
			cout << "\n" << endl;
			wm.ShowMenu();
			break;
		case 2://显示职工
			cout << "\n已录入的职工信息如下" << endl;
			wm.DisplayWorker(wm);
			break;
		case 3://删
			wm.Destoryworker(wm);
			wm.ShowMenu();
			break;
		case 4://改
			wm.Changeworker(wm);
			//wm.ShowMenu();
			break;
		case 5://查
			wm.Findwork(wm);
			break;
		case 6://排序
			wm.Sortwork(wm);
			break;
		case 7://清空数据
			wm.Killallwork(wm);
			break;
		default:
			cout << "检测到输入有误，请重新输入：" << endl;
		}
	} while (input);

	cout << "欢迎下次使用喵```" << endl;
	return 0;
}