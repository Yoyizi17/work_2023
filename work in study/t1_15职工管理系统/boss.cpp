#include"boss.h"


Boss::Boss()
{

}

Boss::Boss(int ID, string name, int Dept)
{
    m_ID = ID;
    m_name = name;
    m_Dept = Dept;
}

void Boss::ShowInfo()//��ʾְ����Ϣ
{
    cout << "ְ����ţ�" << m_ID
        << "\tְ��������" << m_name
        << "\t��λ��" << GetDept()
        << "\t��λְ������"
        << endl;
}

string Boss::GetDept()//��ȡ��λ����
{
    return string("�ϰ�");
}