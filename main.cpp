#include <iostream>
#include <string>
#include <limits>
#include "warehouse.h"
#include "Person.h"
#include "student.h"
#include "teacher.h"
#include "LibraryResource.h"
#include "librarybook.h"
#include "EBook.h"
#include "Magazine.h"

using namespace std;

void showMenu()
{
    cout << "\n====================图书馆管理系统菜单====================" << endl;
    cout << "1. 添加纸质图书" << endl;
    cout << "2. 添加电子书" << endl;
    cout << "3. 添加杂志期刊" << endl;
    cout << "4. 添加学生用户" << endl;
    cout << "5. 添加教师用户" << endl;
    cout << "6. 浏览全部馆藏资源" << endl;
    cout << "7. 浏览全部用户" << endl;
    cout << "8. 借阅资源（纸质借出 / 电子书馆内阅览）" << endl;
    cout << "9. 归还纸质资源" << endl;
    cout << "10. 查询资源信息（按编号）" << endl;
    cout << "11. 查询用户信息（按用户id）" << endl;
    cout << "12. 上报纸质图书丢失" << endl;
    cout << "13. 查询用户完整记录（纸质借阅+电子书阅览，自动算罚款）" << endl;
    cout << "14. 退出系统" << endl;
    cout << "15. 手动保存全部数据" << endl;
    cout << "==========================================================" << endl;
    cout << "请输入功能序号：";
}

int main()
{
    warehouse ware;
    ware.loadAllData(); //程序启动，读取txt恢复所有数据！
    int op;
    while (true)
    {
        showMenu();
        cin >> op;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (op == 14)
        {
            ware.saveAllData(); //退出前自动保存！
            cout << "退出系统。" << endl;
            break;
        }
        if (op == 15)
        {
            ware.saveAllData();
            continue;
        }
        string id;
        string rid;
        Person* userPtr = nullptr;
        LibraryResource* resPtr = nullptr;

        switch (op)
        {
        case 1:
        {
            librarybook* bk = new librarybook();
            bk->inputInfo();
            ware.addResource(bk);
            cout << "纸质图书添加成功！" << endl;
            break;
        }
        case 2:
        {
            EBook* eb = new EBook();
            eb->inputInfo();
            ware.addResource(eb);
            cout << "电子书添加成功！" << endl;
            break;
        }
        case 3:
        {
            Magazine* mg = new Magazine();
            mg->inputInfo();
            ware.addResource(mg);
            cout << "杂志添加成功！" << endl;
            break;
        }
        case 4:
        {
            student* stu = new student();
            stu->inputInfo();
            ware.addUser(stu);
            cout << "学生用户添加成功！" << endl;
            break;
        }
        case 5:
        {
            teacher* tea = new teacher();
            tea->inputInfo();
            ware.addUser(tea);
            cout << "教师用户添加成功！" << endl;
            break;
        }
        case 6:
        {
            ware.showAllResource();
            break;
        }
        case 7:
        {
            ware.showAllUser();
            break;
        }
        case 8:
        {
            cout << "请输入用户ID：";
            getline(cin, id);
            userPtr = ware.findUserById(id);
            if (userPtr == nullptr)
            {
                cout << "找不到该用户！" << endl;
                break;
            }
            cout << "请输入资源编号：";
            getline(cin, rid);
            resPtr = ware.findResById(rid);
            if (resPtr == nullptr)
            {
                cout << "找不到该馆藏资源！" << endl;
                break;
            }
            userPtr->borrowBook(*resPtr);
            break;
        }
        case 9:
        {
            cout << "请输入用户ID：";
            getline(cin, id);
            userPtr = ware.findUserById(id);
            if (userPtr == nullptr)
            {
                cout << "找不到该用户！" << endl;
                break;
            }
            cout << "请输入资源编号：";
            getline(cin, rid);
            resPtr = ware.findResById(rid);
            if (resPtr == nullptr)
            {
                cout << "找不到该馆藏资源！" << endl;
                break;
            }
            userPtr->returnBook(*resPtr);
            break;
        }
        case 10:
        {
            cout << "输入资源编号查询：";
            getline(cin, rid);
            resPtr = ware.findResById(rid);
            if (resPtr)
                resPtr->printInfo();
            else
                cout << "未找到该资源！" << endl;
            break;
        }
        case 11:
        {
            cout << "输入用户ID查询：";
            getline(cin, id);
            userPtr = ware.findUserById(id);
            if (userPtr)
                userPtr->showInfo();
            else
                cout << "未找到该用户！" << endl;
            break;
        }
        case 12:
        {
            cout << "请输入用户ID：";
            getline(cin, id);
            userPtr = ware.findUserById(id);
            if (userPtr == nullptr)
            {
                cout << "找不到该用户！" << endl;
                break;
            }
            cout << "请输入丢失的纸质资源编号：";
            getline(cin, rid);
            userPtr->reportLost(rid, ware);
            break;
        }
        case 13:
        {
            cout << "请输入用户ID：";
            getline(cin, id);
            userPtr = ware.findUserById(id);
            if (userPtr == nullptr)
            {
                cout << "找不到该用户！" << endl;
                break;
            }
            userPtr->calcAllFine(ware);
            userPtr->showFullBorrowInfo(ware);
            break;
        }
        default:
            cout << "输入序号无效，请重新选择！" << endl;
            break;
        }
    }
    return 0;
}