#include"WorkerManager.h"


WorkManager::WorkManager()
{
	//文件不存在
	ifstream ifs(FLIENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->size = 0;
		this->worklist = NULL;
		this->is_fempty = true;
		ifs.close();
		return;
	}

	//文件为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->size = 0;
		this->worklist = NULL;
		this->is_fempty = true;
		ifs.close();
		return;
	}
	ifs.close();

	//文件有数据
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
	cout << "****    欢迎使用职工管理系统     ****" << endl;
	cout << "****    0.退出职工管理系统       ****" << endl;
	cout << "****    1.增加职工信息           ****" << endl;
	cout << "****    2.显示职工信息           ****" << endl;
	cout << "****    3.删除职工信息           ****" << endl;
	cout << "****    4.修改职工信息           ****" << endl;
	cout << "****    5.查找职工信息           ****" << endl;
	cout << "****    6.按照编号排序           ****" << endl;
	cout << "****    7.所有文档               ****" << endl;
	cout << "*************************************" << endl;
}



void WorkManager::AddWork(WorkManager& wm)
{
	cout << "请输入要添加的员工人数" << endl;
	int addnum;//记录增加的人数，用于for循环结束条件
	cin >> addnum;

	AbstractWorker** newspace = new AbstractWorker * [wm.size + addnum];//新创建一个长度足够的新空间
	for (int i = 0; i < addnum; i++)//循环执行添加员工的操作
	{

		for (int j = 0; j < wm.size; j++)//将旧数组中的内容先行拷贝进新数组
		{
			newspace[j] = wm.worklist[j];
		}

		int input;
		cout << "请选择你要添加的职工类型" << endl;
		cout << "1.普通员工" << endl;
		cout << "2.经理" << endl;
		cout << "3.老板" << endl;
		cin >> input;

		AbstractWorker* newp = NULL;//用来新建单个员工的信息暂存
		switch (input)//用多态实现不同身份职工的新建
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

		cout << "请输入职工编号（ps：当前有" << wm.size + i << "名职工" << endl;
		int id;
		cin >> id;
		newp->m_ID = id;

		cout << "请输入职工姓名" << endl;
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
		cout << "\n已录入的职工信息如下...我很想这么说。但是眼下空空如也的一个职员都没有呢。" << endl;
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
		cout << "系统内无职员信息！" << endl;
		return;
	}
	cout << "请输入您觉得没用的的职员的编号" << endl;
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
			cout << "暗杀成功" << endl;
			wm.Save_file(wm);
			return;
		}
	}
	cout << "根本没这号人物，请问您是在拿我寻开心吗？嗯？" << endl;
}

void WorkManager::Changeworker(WorkManager& wm)
{
	if (wm.size == 0)
	{
		cout << "系统内无职员信息！" << endl;
		return;
	}
	Sleep(2000);
	cout << "......" << endl;
	Sleep(2000);
	cout << "..." << endl;
	Sleep(2000);
	cout << "终于无耻到可以对职员进行惨无人道的洗脑了吗？你这肮脏的肥猪\n" << endl;
	Sleep(2000);
	cout << "好吧，无论怎样，请输入您要进行洗脑的职员的编号" << endl;
	int f;
	cin >> f;
	for (int i = 0; i < wm.size; i++)
	{
		if (f == wm.worklist[i]->m_ID)
		{
			AbstractWorker* newp = NULL;
			int input;

			cout << "那么，请先决定ta新的职位吧" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> input;

			switch (input)//用多态实现不同身份职工的新建
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

			cout << "请输入ta新的编号" << endl;
			cin >> newp->m_ID;
			cout << "请输入ta新的名字" << endl;
			cin >> newp->m_name;


			delete wm.worklist[i];
			wm.worklist[i] = newp;
			cout << "调教完毕,想必您做的那些泯灭人性的畜生行径ta已经忘干净了吧" << endl;

			wm.Save_file(wm);
			return;
		}
	}
	cout << "没有这个人呢，您在拿我开玩笑吗？（握刀）" << endl;
}

void WorkManager::Findwork(WorkManager& wm)
{
	if (wm.size == 0)
	{
		cout << "系统内无职员信息！" << endl;
		return;
	}
	cout << "请输入你要查询的职员的编号" << endl;
	int f;
	cin >> f;
	for (int i = 0; i < wm.size; i++)
	{
		if (f == wm.worklist[i]->m_ID)
		{
			cout << "你要查询的职员的信息如下" << endl;
			wm.worklist[i]->ShowInfo();
			return;
		}
	}
	cout << "你要查询的职员不存在！" << endl;

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
	cout << "排序完成，想必ta们今后也会拿出十二分精神产能吧~~~~" << endl;
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
	cout << "排序完成，想必ta们今后也会拿出十二分精神产能吧~~~~" << endl;
}


void WorkManager::Sortwork(WorkManager& wm)
{
	if (wm.size == 0)
	{
		cout << "我们连一个职工都没有呢，您是昏头了吗？" << endl;
		return;
	}
	if (wm.size == 1)
	{
		cout << "虽然我也想活动一下，但是只有一个职工要我排序也让我起不了兴致呢~~？" << endl;
		return;
	}
	cout << "您是打算升序排列还是降序排列呢？" << endl;
	cout << "1.升序\n2.降序" << endl;
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
	cout << "嗯？您确定要 销 毁 所有职员吗？" << endl;
	int input;
	cout << "1.是\n2.我搞错了抱歉" << endl;
	cin >> input;
	if (input == 2)
	{
		cout << "这样吗，那下次把猪食从脑子里掏干净再和我说话吧" << endl;
		return;
	}
	
	cout << "哦？遵命，大屠杀要开始了呵呵呵呵呵~~~" << endl;
	Sleep(5000);
	for (int i = 0; i < wm.size; i++)
	{
		delete wm.worklist[i];
	}
	wm.size = 0;
	wm.worklist = NULL;
	cout << "真是安静呢~~\n这样就只剩下我和您了呢，呵呵（小声）" << endl;
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
