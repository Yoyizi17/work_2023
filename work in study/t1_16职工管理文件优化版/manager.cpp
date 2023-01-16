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

void Manager::ShowInfo()//显示职工信息
{
    cout << "职工编号：" << m_ID
        << "\t职工姓名：" << m_name
        << "\t岗位：" << GetDept()
        << "\t岗位职责：完成老板交给的任务"
        << endl;
}

string Manager::GetDept()//获取岗位名称
{
    return string("经理");
}