#pragma once
#include<iostream>
#include<string>
using namespace std;

class AbstractWorker
{
public:
    int m_ID;//ְ�����
    string m_name;//ְ������
    int m_Dept;//��λ����


    virtual void ShowInfo() = 0;//��ʾְ����Ϣ
    virtual string GetDept() = 0;//��ȡ��λ����
};