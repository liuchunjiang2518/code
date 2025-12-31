#include <iostream>
#include <string>

class Father {
public:
    int A;
    Father() {
        std::cout << "父类构造" << std::endl;
    }
    ~Father() {
        std::cout << "父类析构" << std::endl;
    }
private:
    int B;
protected:
    int C;
};

class Son: public Father {
public:
    int D;
    Son() {
        std::cout << "子类构造" << std::endl;
    }
    ~Son() {
        std::cout << "子类析构" << std::endl;
    }
};

void test1() {
    Son s;
    std::cout << sizeof(s) << std::endl;
}

// 继承中的构造和析构顺序
void test2() {
    Son s;
}

// 继承中同名成员处理
class Base {
public:
    static int MAX;
    int num;
    Base() {
        num = 200;
    }
    int func() {
        return 400;
    }
    int func(int a) {
        return a;
    }
};
int Base::MAX = 1000;

class Derived: public Base {
public:
    static int MAX;
    int num;
    Derived() {
        num = 100;
    }
    int func() {
        return 300;
    }
};
int Derived::MAX = 2000;

void test3() {
    Derived d;
    std::cout << d.num << std::endl;
    std::cout << d.Base::num << std::endl;
    std::cout << d.func() << std::endl;
    std::cout << d.Base::func() << std::endl;
    std::cout << d.Base::func(500) << std::endl;
    std::cout << d.MAX << std::endl;
    std::cout << Base::MAX << std::endl;
    std::cout << Derived::Base::MAX <<std::endl;
}

// 多继承
class Base1 {
public:
    int X;
    Base1() {
        X = 100;
    }
};

class Base2 {
public:
    int X;
    Base2() {
        X = 200;
    }
};

class Derived1: public Base1, public Base2 {
public:
    int Y;
    Derived1() {
        Y = 300;
    }
};

void test4() {
    Derived1 d;
    std::cout << d.Base1::X << std::endl;
    std::cout << d.Base2::X << std::endl;
}

// 菱形继承
class Animal {
public:
    int age;
};

// 羊
class Sheep: virtual public Animal {};

// 骆驼
class Camel: virtual public Animal {};

// 羊驼
class Alpaca: public Sheep, public Camel {};

void test5() {
    Alpaca a;
    a.age = 18;
    std::cout << sizeof(a) << std::endl;
}

class Test {
public:
    int age;
    char sex[9];
    std::string name;
};

void test() {
    Test t;
    std::cout << sizeof(t) << std::endl;
}

int main() {
    std::cout << "Hello World" << std::endl;
    // test1(); // 16
    // test2();
    // test3();
    // test4();
    // test5();
    test();
    return 0;
}