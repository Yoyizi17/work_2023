#include"WorkerManager.h"


WorkManager::WorkManager()
{
	//�ļ�������
	ifstream ifs(FLIENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		this->size = 0;
		this->worklist = NULL;
		this->is_fempty = true;
		ifs.close();
		return;
	}

	//�ļ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->size = 0;
		this->worklist = NULL;
		this->is_fempty = true;
		ifs.close();
		return;
	}
	ifs.close();

	//�ļ�������
	/*this->GetWorklist();*/
	int size = this->GetWorkNum();
	this->GetWorklist(size);
}

//void WorkManager::GetWorklist()
//{
//	ifstream ifs(FLIENAME, ios::in);
//	this->size = 0;
//	this->worklist = NULL;
//
//	while (!ifs.eof())
//	{
//		int id;
//		ifs >> id;
//		if (!ifs.eof())
//		{
//			string name;
//			int deptid;
//			ifs >> name;
//			ifs >> deptid;
//
//			AbstractWorker** newlist = new AbstractWorker * [this->size + 1];
//			for (int i = 0; i < size; i++)
//			{
//				newlist[i] = worklist[i];
//			}
//
//			AbstractWorker* newp = NULL;
//
//			if (deptid == 1)
//				newp = new Employee;
//			else if (deptid == 2)
//				newp = new Manager;
//			else
//				newp = new Boss;
//
//			newp->m_ID = id;
//			newp->m_name = name;
//			newp->m_Dept = deptid;
//			newlist[size] = newp;
//
//			size++;
//			worklist = newlist;
//		}
//	}
//	
//	this->is_fempty = false;
//	ifs.close();
//}


WorkManager::~WorkManager()
{
	if (this->worklist != NULL)
	{
		delete[] this->worklist;
		this->worklist = NULL;
	}
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
	delete[] wm.worklist;
	wm.worklist = newspace;
	wm.is_fempty = false;

	wm.Save_file(wm);


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
			wm.Save_file(wm);
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
			newp->m_Dept = input;

			cout << "������ta�µı��" << endl;
			cin >> newp->m_ID;
			cout << "������ta�µ�����" << endl;
			cin >> newp->m_name;


			delete wm.worklist[i];
			wm.worklist[i] = newp;
			cout << "�������,�����������Щ�������Ե������о�ta�Ѿ����ɾ��˰�" << endl;

			wm.Save_file(wm);
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
	/*int idt = w1->m_ID;
	string namet = w1->m_name;
	w1->m_ID = w2->m_ID;
	w1->m_name = w2->m_name;
	w2->m_ID = idt;
	w2->m_name = namet;*/
	AbstractWorker* tmp(w1);
	w1 = w2;
	w2 = tmp;
	
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

	wm.Save_file(wm);
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
	wm.worklist = NULL;
	cout << "���ǰ�����~~\n������ֻʣ���Һ������أ��Ǻǣ�С����" << endl;
	wm.Save_file(wm);
}

void WorkManager::Save_file(WorkManager& wm)
{
	ofstream ofs(FLIENAME, ios::out);
	for (int i = 0; i < wm.size; i++)
	{
		ofs << wm.worklist[i]->m_ID << "  "
			<< wm.worklist[i]->m_name << "  "
			<< wm.worklist[i]->m_Dept << endl;
	}
	ofs.close();
}

int WorkManager::GetWorkNum()
{
	int id;
	string name;
	int dept;
	int num = 0;
	ifstream ifs(FLIENAME, ios::in);
	while (ifs >> id && ifs >> name && ifs >> dept)
	{
		num++;
	}

	ifs.close();

	return num;
}

void WorkManager::GetWorklist(int Size)
{
	AbstractWorker** newlist = new AbstractWorker * [Size];
	ifstream ifs(FLIENAME, ios::in);
	for (int i = 0; i < Size; i++)
	{
		int id;
		string name;
		int deptid;

		AbstractWorker* newp = NULL;

		ifs >> id;
		ifs >> name;
		ifs >> deptid;

		if (deptid == 1)
			newp = new Employee;
		else if (deptid == 2)
			newp = new Manager;
		else
			newp = new Boss;
		newp->m_ID = id;
		newp->m_name = name;
		newp->m_Dept = deptid;

		newlist[i] = newp;
	}
	this->worklist = newlist;
	this->size = Size;
	this->is_fempty = false;

	ifs.close();
}
