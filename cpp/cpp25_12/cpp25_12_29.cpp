#include <iostream>
#include <string>

// 运算符重载
class Person {
    friend Person operator-(const Person& p1, const Person& p2);
    friend std::ostream& operator<<(std::ostream& cout, const Person& p);
public:
    Person addPerson(const Person& p);
    Person operator+(const Person& p);
    Person& operator++();
    Person operator++(int);
    void setXY(int X, int Y);
private:
    int x;
    int y;
};

void Person::setXY(int X, int Y) {
    x = X;
    y = Y;
}

Person Person::operator+(const Person& p) {
    Person curr;
    curr.x = this->x + p.x;
    curr.y = this->y + p.y;
    return curr;
}

Person Person::addPerson(const Person& p) {
    Person curr;
    curr.x = this->x + p.x;
    curr.y = this->y + p.y;
    return curr;
}

// 全局函数重载
Person operator-(const Person& p1, const Person& p2) {
    Person curr;
    curr.x = p1.x - p2.x;
    curr.y = p1.y - p2.y;
    return curr;
}

// 左移运算符重载
std::ostream& operator<<(std::ostream& cout, const Person& p) {
    cout << p.x << p.y;
    return cout;
}

// 递增运算符重载
// 前置
Person& Person::operator++() {
    x++;
    y++;
    return *this;
}
// 后置 int代表占位参数
Person Person::operator++(int) {
    Person temp = *this;
    x++;
    y++;
    return temp;
}

void test1() {
    Person p1;
    Person p2;
    p1.setXY(20,10);
    p2.setXY(15,5);
    Person p3 = p1 + p2;
    Person p4 = p1 - p2;
    std::cout << p3 << std::endl;
    std::cout << p4 << std::endl;
    std::cout << ++p4 << std::endl;
    std::cout << p4++ << std::endl;
}

int main() {
    std::cout << "Hello World" << std::endl;
    test1();
    return 0;
}