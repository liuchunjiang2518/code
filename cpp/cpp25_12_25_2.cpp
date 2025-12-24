#include <cstdlib>
#include <iostream>
#include <string>
#define MAX 1000

typedef struct Link
{
    std::string name;
    char sex;
    int age;
    std::string tel;
    std::string address;
} Link;

void coutLink(Link* list, int idx)
{
    std::cout << "Name: " << list[idx].name 
              << ", Sex: " << list[idx].sex 
              << ", Age: " << list[idx].age 
              << ", Tel: " << list[idx].tel 
              << ", Address: " << list[idx].address 
              << std::endl;
}

void showList(Link* list, int size)
{
    if (size == 0)
    {
        std::cout << "通讯录为空。" << std::endl;
        return;
    }
    for (int i = 0; i < size; ++i)
    {
        coutLink(list, i);
    }
}

void menu()
{
    std::cout << "1.添加联系人" << std::endl
              << "2.显示联系人" << std::endl
              << "3.删除联系人" << std::endl
              << "4.查找联系人" << std::endl
              << "5.修改联系人" << std::endl
              << "6.清空联系人" << std::endl
              << "0.退出通讯录" << std::endl;
}

void insertLink(Link* list, int& size)
{
    if (size >= MAX)
    {
        std::cout << "通讯录已满！" << std::endl;
        return;
    }
    Link& person = list[size];
    std::cout << "Name: ";
    std::cin >> person.name;
    std::cout << "Sex: ";
    std::cin >> person.sex;
    std::cout << "Age: ";
    std::cin >> person.age;
    std::cout << "Tel: ";
    std::cin >> person.tel;
    std::cout << "Address: ";
    std::cin >> person.address;
    size++;
}

void selectLink(Link* list, std::string name, int size)
{
    bool found = false;
    for (int i = 0; i < size; ++i)
    {
        if (name == list[i].name)
        {
            coutLink(list, i);
            found = true;
        }
    }
    if (!found)
    {
        std::cout << "未找到联系人：" << name << std::endl;
    }
}

void deleteLink(Link* list, std::string name, int& size)
{
    for (int i = 0; i < size; ++i)
    {
        if (name == list[i].name)
        {
            for (int j = i; j < size - 1; ++j)
            {
                list[j] = list[j + 1];
            }
            size--;
            std::cout << "删除成功！" << std::endl;
            return;
        }
    }
    std::cout << "未找到联系人：" << name << std::endl;
}

void updateLink(Link* list, std::string name, int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (name == list[i].name)
        {
            std::cout << "请输入新信息：" << std::endl;
            std::cout << "Name: ";
            std::cin >> list[i].name;
            std::cout << "Sex: ";
            std::cin >> list[i].sex;
            std::cout << "Age: ";
            std::cin >> list[i].age;
            std::cout << "Tel: ";
            std::cin >> list[i].tel;
            std::cout << "Address: ";
            std::cin >> list[i].address;
            std::cout << "修改成功！" << std::endl;
            return;
        }
    }
    std::cout << "未找到联系人：" << name << std::endl;
}

void clearList(int& size)
{
    size = 0;
    std::cout << "通讯录已清空。" << std::endl;
}

void start(Link* list, int& size)
{
    int choose;
    std::string name;
    while (true)
    {
        menu();
        std::cin >> choose;
        switch (choose)
        {
            case 0:
                return;
            case 1:
                insertLink(list, size);
                break;
            case 2:
                showList(list, size);
                break;
            case 3:
                std::cout << "请输入要删除的姓名: ";
                std::cin >> name;
                deleteLink(list, name, size);
                break;
            case 4:
                std::cout << "请输入要查找的姓名: ";
                std::cin >> name;
                selectLink(list, name, size);
                break;
            case 5:
                std::cout << "请输入要修改的姓名: ";
                std::cin >> name;
                updateLink(list, name, size);
                break;
            case 6:
                clearList(size);
                break;
            default:
                std::cout << "无效选项，请重试。" << std::endl;
        }
    }
}

int main()
{
    system("chcp 65001 >nul");
    Link list[MAX];
    int size = 0;
    start(list, size);
    return 0;
}