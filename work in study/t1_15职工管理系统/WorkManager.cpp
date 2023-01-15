#include"WorkerManager.h"


WorkManager::WorkManager()
{
	this->size = 0;
	this->worklist = NULL;
}

WorkManager::~WorkManager()
{

}

void WorkManager::ShowMenu()
{
	cout << "*************************************" << endl;
	cout << "****    ��ӭʹ��ְ������ϵͳ     ****" << endl;
	cout << "****    0.�˳�ְ������ϵͳ       ****" << endl;
	cout << "****    1.����ְ����Ϣ           ****" << endl;
	cout << "****    2.��ʾְ����Ϣ           ****" << endl;
	cout << "****    3.ɾ��ְ����Ϣ           ****" << endl;
	cout << "****    4.�޸�ְ����Ϣ           ****" << endl;
	cout << "****    5.����ְ����Ϣ           ****" << endl;
	cout << "****    6.���ձ������           ****" << endl;
	cout << "****    7.�����ĵ�               ****" << endl;
	cout << "*************************************" << endl;
}



void WorkManager::AddWork(WorkManager& wm)
{
	cout << "������Ҫ��ӵ�Ա������" << endl;
	int addnum;//��¼���ӵ�����������forѭ����������
	cin >> addnum;

	AbstractWorker** newspace = new AbstractWorker * [wm.size + addnum];//�´���һ�������㹻���¿ռ�
	for (int i = 0; i < addnum; i++)//ѭ��ִ�����Ա���Ĳ���
	{

		for (int j = 0; j < wm.size; j++)//���������е��������п�����������
		{
			newspace[j] = wm.worklist[j];
		}

		int input;
		cout << "��ѡ����Ҫ��ӵ�ְ������" << endl;
		cout << "1.��ͨԱ��" << endl;
		cout << "2.����" << endl;
		cout << "3.�ϰ�" << endl;
		cin >> input;

		AbstractWorker* newp = NULL;//�����½�����Ա������Ϣ�ݴ�
		switch (input)//�ö�̬ʵ�ֲ�ͬ���ְ�����½�
		{
		case 1:
		    newp = new Employee;
			break;
		case 2:
			newp = new Manager;
			break;
		case 3:
			newp = new Boss;
			break;
		default:
			break;
		}

		cout << "������ְ����ţ�ps����ǰ��" << wm.size + i << "��ְ��" << endl;
		int id;
		cin >> id;
		newp->m_ID = id;

		cout << "������ְ������" << endl;
		string name;
		cin >> name;
		newp->m_name = name;

		newp->m_Dept = input;

		newspace[wm.size + i] = newp;
	}

	wm.size += addnum;
	delete wm.worklist;
	wm.worklist = newspace;


}

void WorkManager::DisplayWorker(WorkManager& wm)
{
	if (wm.size == 0)
	{
		cout << "\n��¼���ְ����Ϣ����...�Һ�����ô˵���������¿տ���Ҳ��һ��ְԱ��û���ء�" << endl;
		return;
	}
	for (int i = 0; i < wm.size; i++)
	{
		wm.worklist[i]->ShowInfo();
	}
}

void WorkManager::Destoryworker(WorkManager& wm)
{
	if (wm.size == 0)
	{
		cout << "ϵͳ����ְԱ��Ϣ��" << endl;
		return;
	}
	cout << "������������û�õĵ�ְԱ�ı��" << endl;
	int d;
	cin >> d;
	for (int i = 0; i < wm.size; i++)
	{
		if (d == wm.worklist[i]->m_ID)
		{
			delete wm.worklist[i];
			for (int j = i; j+1 < wm.size; j++)
			{
				wm.worklist[j] = wm.worklist[j + 1];
			}
			wm.size--;
			cout << "��ɱ�ɹ�" << endl;
			return;
		}
	}
	cout << "����û��������������������Ѱ�������ţ�" << endl;
}

void WorkManager::Changeworker(WorkManager& wm)
{
	if (wm.size == 0)
	{
		cout << "ϵͳ����ְԱ��Ϣ��" << endl;
		return;
	}
	Sleep(2000);
	cout << "......" << endl;
	Sleep(2000);
	cout << "..." << endl;
	Sleep(2000);
	cout << "�����޳ܵ����Զ�ְԱ���в����˵���ϴ���������ⰹ��ķ���\n" << endl;
	Sleep(2000);
	cout << "�ðɣ�������������������Ҫ����ϴ�Ե�ְԱ�ı��" << endl;
	int f;
	cin >> f;
	for (int i = 0; i < wm.size; i++)
	{
		if (f == wm.worklist[i]->m_ID)
		{
			AbstractWorker* newp = NULL;
			int input;

			cout << "��ô�����Ⱦ���ta�µ�ְλ��" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> input;

			switch (input)//�ö�̬ʵ�ֲ�ͬ���ְ�����½�
			{
			case 1:
				newp = new Employee;
				break;
			case 2:
				newp = new Manager;
				break;
			case 3:
				newp = new Boss;
				break;
			default:
				break;
			}

			cout << "������ta�µı��" << endl;
			cin >> newp->m_ID;
			cout << "������ta�µ�����" << endl;
			cin >> newp->m_name;
			delete wm.worklist[i];
			wm.worklist[i] = newp;
			cout << "�������,�����������Щ�������Ե������о�ta�Ѿ����ɾ��˰�" << endl;

			return;
		}
	}
	cout << "û��������أ��������ҿ���Ц�𣿣��յ���" << endl;
}

void WorkManager::Findwork(WorkManager& wm)
{
	if (wm.size == 0)
	{
		cout << "ϵͳ����ְԱ��Ϣ��" << endl;
		return;
	}
	cout << "��������Ҫ��ѯ��ְԱ�ı��" << endl;
	int f;
	cin >> f;
	for (int i = 0; i < wm.size; i++)
	{
		if (f == wm.worklist[i]->m_ID)
		{
			cout << "��Ҫ��ѯ��ְԱ����Ϣ����" << endl;
			wm.worklist[i]->ShowInfo();
			return;
		}
	}
	cout << "��Ҫ��ѯ��ְԱ�����ڣ�" << endl;

}

void Swapwork(AbstractWorker*& w1, AbstractWorker*& w2)
{
	int idt = w1->m_ID;
	string namet = w1->m_name;
	w1->m_ID = w2->m_ID;
	w1->m_name = w2->m_name;
	w2->m_ID = idt;
	w2->m_name = namet;
}

void M_Sort1(WorkManager& wm)
{
	for (int i = wm.size; i>1 ; i--)
	{
		for (int j = 0; j+1 < i; j++)
		{
			if (wm.worklist[j]->m_ID > wm.worklist[j + 1]->m_ID)
				Swapwork(wm.worklist[j], wm.worklist[j + 1]);
		}
	}
	cout << "������ɣ����ta�ǽ��Ҳ���ó�ʮ���־�����ܰ�~~~~" << endl;
}

void M_Sort2(WorkManager& wm)
{
	for (int i = wm.size; i > 1; i--)
	{
		for (int j = 0; j + 1 < i; j++)
		{
			if (wm.worklist[j]->m_ID < wm.worklist[j + 1]->m_ID)
				Swapwork(wm.worklist[j], wm.worklist[j + 1]);
		}
	}
	cout << "������ɣ����ta�ǽ��Ҳ���ó�ʮ���־�����ܰ�~~~~" << endl;
}


void WorkManager::Sortwork(WorkManager& wm)
{
	if (wm.size == 0)
	{
		cout << "������һ��ְ����û���أ����ǻ�ͷ����" << endl;
		return;
	}
	if (wm.size == 1)
	{
		cout << "��Ȼ��Ҳ��һ�£�����ֻ��һ��ְ��Ҫ������Ҳ��������������~~��" << endl;
		return;
	}
	cout << "���Ǵ����������л��ǽ��������أ�" << endl;
	cout << "1.����\n2.����" << endl;
	int input;
	cin >> input;
	if (input == 1)
		M_Sort1(wm);
	else
		M_Sort2(wm);
}

void WorkManager::Killallwork(WorkManager& wm)
{
	cout << "�ţ���ȷ��Ҫ �� �� ����ְԱ��" << endl;
	int input;
	cout << "1.��\n2.�Ҹ���˱�Ǹ" << endl;
	cin >> input;
	if (input == 2)
	{
		cout << "���������´ΰ���ʳ���������͸ɾ��ٺ���˵����" << endl;
		return;
	}
	
	cout << "Ŷ������������ɱҪ��ʼ�˺ǺǺǺǺ�~~~" << endl;
	Sleep(5000);
	for (int i = 0; i < wm.size; i++)
	{
		delete wm.worklist[i];
	}
	wm.size = 0;
	cout << "���ǰ�����~~\n������ֻʣ���Һ������أ��Ǻǣ�С����" << endl;
}
