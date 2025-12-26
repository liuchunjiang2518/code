#include <iostream>
#include <string>
#include "Queue.h"
#define MAX 100
using namespace std;

// 对象的初始化和清理
// 构造函数和析构函数，如果不写，编译器默认构造空的
class Person
{
    public:
        string name;
        Person() // 构造函数可以传参数，可以重载
        {
            cout << "Person默认构造函数调用" << endl;
        }
        Person(string a) // 有参构造函数
        {
            name = a;
            cout << "Person有参构造函数调用" << endl;
        }
        Person(const Person& p) // 拷贝构造函数
        {
            name = p.name;
            cout << "Person拷贝构造函数调用" << endl;
        }
        ~Person() // 析构函数不能传参数
        {
            cout << "Person析构函数调用" << endl;
        }
};

void test1()
{
    Person wan;
    Person liu("刘玉平");
    Person yu(liu);
    wan.name = "万春宏";
    cout << wan.name << liu.name << yu.name << endl;
}

void test2()
{
    Queue<int> Q(MAX);
    Q.enQueue(10);
    Q.enQueue(20);
    Q.enQueue(30);
    Q.enQueue(40);
    Q.enQueue(50);
    int del;
    Q.deQueue(del);
    Q.traverse();
}

int main()
{
    cout << "Hello World" << endl;
    // test1();
    test2();
    return 0;
}