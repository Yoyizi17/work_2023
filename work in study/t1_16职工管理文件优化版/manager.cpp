#include"manager.h"


Manager::Manager()
{

}

Manager::Manager(int ID, string name, int Dept)
{
    m_ID = ID;
    m_name = name;
    m_Dept = Dept;
}

void Manager::ShowInfo()//��ʾְ����Ϣ
{
    cout << "ְ����ţ�" << m_ID
        << "\tְ��������" << m_name
        << "\t��λ��" << GetDept()
        << "\t��λְ������ϰ彻��������"
        << endl;
}

string Manager::GetDept()//��ȡ��λ����
{
    return string("����");
}