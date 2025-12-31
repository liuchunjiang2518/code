#include <iostream>
#include <string>
#include <cmath>
#include "Graphic.h"
using std::cout;
using std::endl;
using std::string;
#define PI 3.14

// 类
class Student
{
    public:
        string id;
        string name;
        void showStudent()
        {
            cout << name << id << endl;
        }
};

class Person
{
    // 类内可以，类外可以
    public:
        string name;
        void func()
        {
            name = "刘玉平";
            car = "拖拉机";
            password = 123;
        }

        // car可读可写
        void setCar(string s_car)
        {
            car = s_car;
        }
        string getCar()
        {
            return car;
        }

        // age只读
        int getAge()
        {
            return age;
        }

        // password只写
        void setPassword(string s_Idol)
        {
            Idol = s_Idol;
        }

    // 类内可以，类外不可以 儿子可以访问
    protected:
        string car;

    // 类内可以，类外不可以 儿子不可以访问
    private:
        int password;
        int age = 45;
        string Idol;
};

int testClass()
{
    Circle cl;
    cl.R = 2;
    cout << "圆的周长为" << cl.calculateZC() << endl;
    Student wan;
    wan.id = "S1001";
    wan.name = "万春宏";
    wan.showStudent();
    Person liu;
    liu.func();
    cout << liu.name << liu.getCar() << endl;
    cout << "立方体" << endl;
    Cube c1;
    c1.setH(10);
    c1.setL(10);
    c1.setW(10);
    cout << c1.calculateS() << ' ' << c1.calculateV() << endl;
    return 0;
}

int main()
{
    cout << "Hello World" << endl;
    testClass();
    return 0;
}