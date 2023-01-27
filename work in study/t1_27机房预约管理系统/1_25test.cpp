/*
学生类的成员变量：string （学）号，string 姓名， string 密码。<>
老师类的成员变量：string （职工）号，string 姓名，string 密码。<>
管理员类：string 用户名，密码。<>

预约信息管理类：
         变量：
         学号，姓名，预约的机房，预约的日子，预约的时间（上午/下午），预约状态（审核中，取消预约，审核通过）；
         string  string    int         int          int                                    int
         成员函数：
                 查看我的预约信息（显示取消预约）：
                 查看所有人预约信息接口（重载，不显示“取消预约”状态的预约信息。）：
                 增加预约信息接口：
                 取消预约信息接口：

                 审核预约信息接口：
                 查看所有人预约信息接口（重载，显示“取消预约”状态的预约信息。）：

账号管理类（纯虚类）：<>
                      成员函数：
                      判断账号密码是否正确（）==0；
                      新增账号（）==0；
学生账号管理类：<>
         成员函数（纯虚函数的多态实现）：
     判断学生账号密码是否正确函数接口： {
                                             string1; 
                                             if(string1==xx号||string1==姓名)   1.输入正确的学号+密码/姓名+密码;否则提示输入错误并结束，
                                                  string2;                         返回登录选择界面。
                                                  if(string2==password)          ps:xx号和密码均取自于各多态内部调用的——机房预约管理系统类——
                                                       return true;                 储存对应信息的数组。
                                              else
                                              else
                                                   return false;
                                         }
                          新增学生账号：{
                                             string  stu_num（判断是否重复）
                                             string  name
                                             string  password;
                                             学生类（stu_num，name，password）；
                                             储存学生信息的数组.push_back(学生类);

                                             向student.txt文件中新增数据；
                                         }
老师账号管理类：同上。
管理员账号管理类：同上。

机房预约管理系统类实现功能：
              变量：储存学生信息（数组）；
                    储存老师信息（数组）；
                    储存管理员信息（数组）；
                    储存所有预约信息（数组）；
              成员函数：构造函数：空实现
                        初始化：从student.txt文件中获取学生信息。从teahcer.txt文件中获取老师信息。从manager.txt文件中获取管理员信息。
                                从book文件中获取预约信息。
                        登录接口：{
                                       int;
                                       swicth(int)
                                       登陆管理类* Login；
                                       case 1:学生接口：
                                       case 2:老师接口：
                                       case 3:管理员接口：
                                       case 0:退出。
                                  }
     学生接口（登陆管理类*& Login）：{
                                       Login=new 学生账号管理类（用纯虚类指针实现多态）；
                                       if(Login—>判断账号密码是否正确函数接口（）==flase);
                                           return;
                                       system（"cls")；清屏。

                                       menu;菜单。
                                       int;
                                       swicth(int)
                                       case 1：查看我的预约信息接口。
                                       case 2：查看所有人预约信息接口。（重载，不显示“取消预约”状态的预约信息。）
                                       case 3：增加预约信息接口。
                                       case 4：取消预约信息接口。
                                       case 0：退出登录接口。
                                    }
      老师接口（登陆管理类*& Login）：{
                                       Login=new 老师账号管理类（用纯虚类指针实现多态）；
                                       if(Login—>判断账号密码是否正确函数接口（）==flase);
                                           return;

                                        system("cls")；清屏。

                                       menu;菜单。
                                       int;
                                       swicth(int)
                                       case 1：审核预约信息接口。
                                       case 2：查看所有人预约信息接口。（重载，显示“取消预约”状态的预约信息。）
                                       case 0：退出登录接口。
                                    }
    管理员接口（登陆管理类*& Login）：{
                                       Login=new 管理员账号管理类（用纯虚类指针实现多态）；
                                       if(Login—>判断账号密码是否正确函数接口（）==flase);
                                           return;

                                       delete Login；
                                       Login=NULL；

                                       menu;菜单。
                                       int;
                                       swicth(int)
                                       case 1：新增学生账号（Login=new 学生账号管理类；Login.新增学生账号（））。
                                       case 2：新增老师账号（同上）。
                                       case 3；新增管理员账号（同上）。
                                       case 4；清空所有预约信息。
                                       case 0：退出登录接口。

                                       system
                                     }
                     清空所有预约信息：
                                     {
                                          清空文件。
                                          清空储存预约信息的列表。
                                     }
                                     
      

                    
*/

#include"mroom_book_manager.h"

int main()
{
    MroomBook_Manager mm;
    mm.Login(mm);
	return 0;
}