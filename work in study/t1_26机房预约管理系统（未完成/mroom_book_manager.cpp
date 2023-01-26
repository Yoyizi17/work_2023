#include"mroom_book_manager.h"
#include"student_.acc_manager.h"

void mune()
{
	cout << "******************************" << endl;
	cout << "*    ��ӭʹ�û���ԤԼϵͳ    *" << endl;
	cout << "*        1.ѧ����½          *" << endl;
	cout << "*        2.��ʦ��½          *" << endl;
	cout << "*        3.����Ա��½        *" << endl;
	cout << "*        0.�˳�ϵͳ          *" << endl;
	cout << "******************************" << endl;
}

MroomBook_Manager::MroomBook_Manager()
{
	vstu.insert(Student("1", "����", "123"));
}

void MroomBook_Manager::Login(MroomBook_Manager& mm)
{
	
	int input;

	do
	{
		mune();
		cout << "��ѡ��";
		cin >> input;
		switch (input)
		{
		case STUDENT:
			mm.StudentLogin(mm);
			system("cls");
			break;
		case TEATHER:
			break;
		case ADMIN:
			break;
		case EXIT:
			cout << "��ӭ�´�ʹ�ã�" << endl;
			break;
		default:
			cout << "����������������룺";
			break;
		}
	} while (input);
}

void MroomBook_Manager::StudentLogin(MroomBook_Manager& mm)
{
	string num;//������¼���ѧ����ѧ�Ż���������
	AccountManager* Login = new  StudentAccManager;
	if (!Login->Is_accPassTrue(mm,num))
		return;
	int input;
	do
	{
		StudentMenu();//��ӡ�˵�
		cout << "��ѡ��" << endl;
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "��ִ�� 1" << endl;
			break;
		case 2:
			cout << "��ִ�� 2" << endl;
			break;
		case 3:
			cout << "��ִ�� 3" << endl;
			break;
		case 4:
			cout << "��ִ�� 4" << endl;
			break;
		case 0:
			break;
		default:
			cout << "�����������������" << endl;
		}
	} while (input);
}

void MroomBook_Manager::StudentMenu()
{
	cout << "************************************" << endl;
	cout << "*        1.�鿴�ҵ�ԤԼ��Ϣ        *" << endl;
	cout << "*        2.�鿴����ԤԼ��Ϣ        *" << endl;
	cout << "*        3.�����ҵ�ԤԼ            *" << endl;
	cout << "*        4.ȡ���ҵ�ԤԼ            *" << endl;
	cout << "*        0.�˳�ϵͳ                *" << endl;
	cout << "************************************" << endl;
}
