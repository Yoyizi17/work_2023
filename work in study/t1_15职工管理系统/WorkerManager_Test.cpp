#include"WorkerManager.h"
#include"Worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
int main()
{
	//AbstractWorker* w = new Boss(1, "������", 6);
	//w->ShowInfo();

	WorkManager wm;
	wm.ShowMenu();//��ӡ�˵�;

	int input;
	cout << "��ѡ��" << endl;
	do
	{
		cin >> input;
		switch (input)
		{
		case 0://�˳�ϵͳ
			break;
		case 1://����ְ��
			wm.AddWork(wm);
			cout << "������" << endl;
			cout << "\n" << endl;
			wm.ShowMenu();
			break;
		case 2://��ʾְ��
			cout << "\n��¼���ְ����Ϣ����" << endl;
			wm.DisplayWorker(wm);
			break;
		case 3://ɾ
			wm.Destoryworker(wm);
			wm.ShowMenu();
			break;
		case 4://��
			wm.Changeworker(wm);
			//wm.ShowMenu();
			break;
		case 5://��
			wm.Findwork(wm);
			break;
		case 6://����
			wm.Sortwork(wm);
			break;
		case 7://�������
			wm.Killallwork(wm);
			break;
		default:
			cout << "��⵽�����������������룺" << endl;
		}
	} while (input);

	cout << "��ӭ�´�ʹ����```" << endl;
	return 0;
}