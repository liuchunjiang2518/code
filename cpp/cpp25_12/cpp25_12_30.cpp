#include <iostream>
#include <string>

// 继承
class Animal {
protected:
    std::string name;
public:
    Animal(const std::string& n);
    virtual ~Animal() = default;
    virtual void speak() const;
};

class Dog: public Animal {
    public:
    Dog(const std::string& n);
    void speak() const override;
};

Animal::Animal(const std::string& n): name(n) {}

Dog::Dog(const std::string& n): Animal::Animal(n) {}

void Animal::speak() const {
    std::cout << "发出叫声" << std::endl;
}

void Dog::speak() const {
    std::cout << name << "汪汪叫" << std::endl;
}

void test1() {
    Dog wangcai("旺财");
    wangcai.speak();
}

int main() {
    std::cout << "Hello World" <<std::endl;
    // test1();
    return 0;
}