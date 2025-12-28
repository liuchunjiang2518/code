#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string name;
    int* height;
    Person()
    {
        cout << "默认" << endl;
    }
    Person(string s_name,int s_height)
    {
        name = s_name;
        height = new int(s_height);
        cout << "有参" << endl;
    }
    Person(const Person& p)
    {
        name = p.name;
        height = new int(*p.height);
        cout << "拷贝" << endl;
    }
    ~Person()
    {
        if (height != nullptr)
        {
            delete height;
            height = nullptr;
        } 
    }
};

// 拷贝函数构造时机
// 1.使用一个已经创建完毕的对象初始化新对象
void test1()
{
    Person p1;
    p1.name = "万春宏";
    Person p2(p1);
    cout << p2.name << endl;
}

// 2.值传递的方式给函数参数传参
void doWork(Person p)
{

}
void test2()
{
    Person p;
    doWork(p);
}

// c++17之后没有了
// 3.值返回局部对象
Person func()
{
    Person p("万春宏",175);
    return p;
}
void test3()
{
    Person p = func();
    Person p1 = p;
    cout << p1.name << endl;
}

// 深拷贝浅拷贝
void test4()
{
    // 浅拷贝
    // 堆区的内存重复释放
    Person p1("万春宏",175);
    Person p2(p1);
    cout << *p1.height << *p2.height << endl;
}

// 类对象作为类成员
class Heath
{
public:
    float height;
    float weight;
    Heath(float s_height = 0.0f,float s_weight = 0.0f) : height(s_height),weight(s_weight) {}
};

// 初始化列表
class Student
{
public:
    string name;
    int age;
    string sex;
    Heath heath_info;
    Student(string s_name = "NULL",int s_age = -1,string s_sex = "空",Heath s_heath = Heath()) :
        name(s_name),
        age(s_age),
        sex(s_sex),
        heath_info(s_heath) {}
};

int main()
{
    cout << "Hello World" << endl;
    // test1();
    // test2();
    test3();
    return 0;
}