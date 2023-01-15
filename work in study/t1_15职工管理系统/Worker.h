#pragma once
#include<iostream>
#include<string>
using namespace std;

class AbstractWorker
{
public:
    int m_ID;//职工编号
    string m_name;//职工姓名
    int m_Dept;//岗位名称


    virtual void ShowInfo() = 0;//显示职工信息
    virtual string GetDept() = 0;//获取岗位名称
};