#include <iostream>

// 静态成员
// 所有对象共享一个数据
// 类内声明类外初始化
// 静态成员函数只能访问静态成员变量
class Person {
public:
    static std::string introduction;
    std::string name;
    Person (std::string s_name = "NULL"): name(s_name) {}
    static void func() {
        introduction = "何人类";
        std::cout << Person::introduction << std::endl;
    }
};
std::string Person::introduction = "人类";

void test1() {
    Person p1;
    std::cout << p1.introduction << std::endl;
    Person p2;
    p2.introduction = "非人类";
    std::cout << p1.introduction << std::endl;
    Person::introduction = "似人类";
    std::cout << p1.introduction << std::endl;
    p1.func();
    Person::func();
}

// 对象模型和this指针
// 成员变量和成员函数函数是分开存储的
class Student {
public:
    int age;
    static int size;
    mutable std::string name;
    Student(int s_age = 0, std::string s_name = "万春宏") {
        this->age = s_age;
        this->name = s_name;
    }
    void copyAge(Student& s) {
        this->age = s.age;
    }
    Student& addAge(Student& s) {
        this->age += s.age;
        return *this;
    }
    void showStudent() const {
        if (this == nullptr) {
            return;
        }
        this->name = "NULL";
        std::cout << age << name << std::endl;
    }
    void func() {
        std::cout << "Hello World" << std::endl;
    }
};
int Student::size = 100;

void test2() {
    Student s1;
    std::cout << sizeof(s1) << std::endl; // 空对象占一个字节，区分空对象占内存的位置
    // 空对象加入一个int属性后总计占4个字节
    // 加入静态成员变量后不变
    // 加入成员函数不变
}

// this指针
// 指向被调用的成员函数所属的对象
void test3() {
    Student s1(10);
    Student s2;
    s2.copyAge(s1);
    std::cout << s1.age << std::endl << s2.age << std::endl;
    std::cout << s2.addAge(s1).age << std::endl; 
}

// 空指针访问成员函数
void test4() {
    Student* s1 = nullptr;
    s1->func();
    s1->showStudent();
}

// const修饰成员函数
// 变为常函数
// 不可以修改属性
void test5() {
    Student s1;
    s1.age = 19;
    s1.showStudent();
    const Student s2; // 常对象只能调用常函数
}

int main() {
    std::cout << "Hello World" << std::endl;
    // test1();
    // test2();
    // test3();
    // test4();
    test5();
    return 0;
}