#include"employee.h"


Employee::Employee()
{

}

Employee::Employee(int ID,string name,int Dept)
{
    m_ID = ID;
    m_name = name;
    m_Dept = Dept;
}

void Employee:: ShowInfo()//��ʾְ����Ϣ
{
    cout << "ְ����ţ�" << m_ID 
        << "\tְ��������" << m_name 
        << "\t��λ��" << GetDept() 
        << "\t��λְ����ɾ�����������" 
        << endl;
}

string Employee::GetDept()//��ȡ��λ����
{
    return string("Ա��");
}