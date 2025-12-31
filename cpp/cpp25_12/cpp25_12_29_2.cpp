#include <iostream>
#include <string>

class Num {
    friend std::ostream& operator<<(std::ostream& cout, const Num& n);
public:
    Num(int X);
    ~Num();
    Num& operator=(const Num& n);
    bool operator==(const Num& n);
private:
    int* x;
};

class Func {
public:
    void operator()(std::string test);
    int operator()(int x, int y);
};

int Func::operator()(int x, int y) {
    return x + y;
}

void Func::operator()(std::string test) {
    std::cout << test << std::endl;
}

Num::Num(int X) {
    x = new int(X);
}

Num::~Num() {
    if (x != nullptr) {
        delete x;
        x = nullptr;
    }
}

Num& Num::operator=(const Num& n) {
    if (this == &n) {
        return *this;
    }
    delete x;
    x = new int(*n.x);
    return *this;
}

bool Num::operator==(const Num& n) {
    return *this->x == *n.x;
}

std::ostream& operator<<(std::ostream& cout, const Num& n) {
    cout << *n.x;
    return cout;
}

void test1() {
    Num n1(18);
    Num n2(20);
    Num n3(30);
    n3 = n2 = n1;
    std::cout << n3 << n2 << n1 << std::endl;
    std::cout << (n1 == n2) << std::endl;
}

void test2() {
    Func print;
    print("Hello World");
    Func sum;
    std::cout << sum(12,19) << std::endl;
}

int main() {
    // test1();
    test2();
    return 0;
}