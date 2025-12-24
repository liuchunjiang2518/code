#include <iostream>
#include <string>
#include <cstdlib>

typedef struct Card
{
    std::string name;
    int balance;
}Card;

Card user = {"万春宏",5000000};

void show()
{
    std::cout << "当前余额为" << user.balance << std::endl;
}

void pop()
{
    int money;
    std::cout << "输入取款数" << std::endl;
    std::cin >> money;
    user.balance -= money;
    std::cout << "取款" << money << std::endl;
}

void push()
{
    int money;
    std::cout << "输入存款数" << std::endl;
    std::cin >> money;
    user.balance += money;
    std::cout << "存款" << money << std::endl;
}

void menu()
{
    int choose;
    while (true)
    {
        std::cout << "0退出 1显示余额 2存款 3取款" << std::endl;
        std::cin >> choose;
        switch (choose)
        {
            case 0:
                std::cout << "已退出系统" << std::endl;
                return;
            case 1:
                show();
                break;
            case 2:
                push();
                show();
                break;
            case 3:
                pop();
                show();
                break;
            default:
                std::cout << "当前操作有误" << std::endl;
        }
    }
}

int main()
{
    system("chcp 65001 >nul");
    std::string name;
    std::cout << "输入姓名" << std::endl;
    std::cin >> name;
    if (name == user.name)
    {
        menu();
    }
    else
    {
        std::cout << "当前姓名有误" << std::endl;
    }
    return 0;
}