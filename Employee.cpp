/*
 * @Author: Akko
 * @Date: 2020-09-06 14:44:01
 * @LastEditTime: 2020-09-06 15:58:06
 * @LastEditors: Akko
 * @Description: 雇员类
 * @FilePath: /EIS/Employee.c++
 * @ Copyright ©️ 2020 Akko All rights reserved.
 */
#include <iostream>
#include <string>
#include <fstream>

#ifndef EMPLOYEE
#define EMPLOYEE

using namespace std;

class Employee
{
protected:
    string Employee_NO;
    string Name;
    string Sex;
    string Department;
    string Rank;

public:
    static int Employee_Number;
    void Get(void);                                   //display
    void Get(string, string, string, string, string); //修改数据
    string UGet();                                    //用于向派生类提供信息
    string SearchGet(int);                            //为Search()提供相关信息
    friend void Search();
    virtual void Display();
    virtual int Modify();
    virtual int Update();
    Employee();
    Employee(const Employee &s)
    {

        Employee_NO = s.Employee_NO;
        Name = s.Name;
        Sex = s.Sex;
        Department = s.Department;
        Rank = s.Rank;
    }
    ~Employee()
    {
        Employee_Number--;
    };
};

Employee::Employee()
{
    cout << "----------基础信息---------\n";
    cout << "1.编号: ";
    cin >> Employee_NO;
    cout << "2.姓名: ";
    cin >> Name;
    cout << "3.性别: ";
    cin >> Sex;
    cout << "4.所在部门: ";
    cin >> Department;
    cout << "5.级别: ";
    cin >> Rank;
    Employee_Number++;
}
string Employee::SearchGet(int i) //返回姓名编号
{
    if (i == 0)
        return Name;
    else
        return Employee_NO;
}
void Employee::Get()
{
    cout << "1.编号: " << Employee_NO << endl;
    cout << "2.姓名: " << Name << endl;
    cout << "3.性别: " << Sex << endl;
    cout << "4.所在部门: " << Department << endl;
    cout << "5.级别: " << Rank << endl;
}
void Employee::Get(string s1, string s2, string s3, string s4, string s5)
{
    cout << "编号(已修改): " << (Employee_NO = s1) << endl;
    cout << "姓名(已修改): " << (Name = s2) << endl;
    cout << "性别(已修改): " << (Sex = s3) << endl;
    cout << "所在部门(已修改): " << (Department = s4) << endl;
    cout << "级别(已修改): " << (Rank = s5) << endl;
}
string Employee::UGet()
{
    string s1 = "1.编号: " + Employee_NO;
    string s2 = "\n2.姓名: " + Name;
    string s3 = "\n3.性别:" + Sex;
    string s4 = "\n4.所在部门: " + Department;
    string s5 = "\n5.级别: " + Rank;

    s1 += s2;
    s1 += s3;
    s1 += s4;
    s1 += s5;

    return s1;
}
void Employee::Display() //显示功能
{
    cout << "\n1.编号"
         << "\t"
         << "2.姓名"
         << "\t"
         << "3.性别"
         << "\t"
         << "4.所在部门"
         << "\t"
         << "5.级别" << endl;
    cout << Employee_NO << "\t" << Name << "\t" << Sex << "\t" << Department << "\t" << Rank << endl;
}
int Employee::Modify() //修改功能
{
    int temp;
    Employee::Display();
    cout << "请输入编号以继续: ";
    cin >> temp;
    switch (temp)
    {
    case 1:
        cout << "新的编号: ";
        cin >> Employee_NO;
        break;
    case 2:
        cout << "新的姓名: ";
        cin >> Name;
        break;
    case 3:
        cout << "新的性别: ";
        cin >> Sex;
        break;
    case 4:
        cout << "新的所在部门: ";
        cin >> Department;
        break;
    case 5:
        cout << "新的级别: ";
        cin >> Rank;
        break;

    default:
        cout << "编号不存在，已退出。\n";
        break;
    }
    return 0;
}
int Employee::Update()
{
    ofstream out(".\\Employee.txt");
    if (!out)
    {
        cout << "操作失败!\n";
    }
    else
    {
        out << "1.编号: " << Employee_NO << endl;
        out << "2.姓名: " << Name << endl;
        out << "3.性别: " << Sex << endl;
        out << "4.所在部门: " << Department << endl;
        out << "5.级别: " << Rank << endl;
    }
    out.close();
    return 0;
}
#endif//EMPLOYEE