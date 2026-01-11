#include <iostream>

// 动态多态
class Animal {
public:
    virtual void speak() {
        std::cout << "动物叫" << std::endl;
    }
};

class Cat: public Animal {
public:
    void speak() {
        std::cout << "喵喵" << std::endl;
    }
};

void test1(Animal& cat, Animal& animal) {
    cat.speak();
    std::cout << sizeof(cat) << std::endl;
    std::cout << sizeof(animal) << std::endl;
}

class Calculator {
public:
    int num2;
    int num1;

    int getResult(char oper) {
        switch (oper) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
            case '/':
                return num1 / num2;
            default:
                return 0;
        }
    }
};

// 抽象类中，子类必须重写父类的纯虚函数
class AbstractCalculator {
public:
    int num1;
    int num2;
    
    virtual int getResult() = 0;

    virtual ~AbstractCalculator() = default;
};

class AddCalculator: public AbstractCalculator {
    public:
    int getResult() override {
        return num1 + num2;
    }
};

void test2() {
    Calculator c;
    c.num1 = 20;
    c.num2 = 10;
    std::cout << c.getResult('+') << std::endl;
    AbstractCalculator* ac = new AddCalculator;
    ac->num1 = 20;
    ac->num2 = 10;
    std::cout << ac->getResult() << std::endl;
    delete ac;
    ac = nullptr;
}

// 多态案例
class AbstractDrinking {
public:
    void makeDrink() {
        std::cout << "开始制作饮品..." << std::endl;
        Boil();
        Brew();
        PourInCup();
        PutSth();
        std::cout << std::endl << "饮品制作完成！" << std::endl << std::endl;
    }

protected:
    virtual void Boil() = 0;
    virtual void Brew() = 0;
    virtual void PourInCup() = 0;
    virtual void PutSth() = 0;
};

class Coffee: public AbstractDrinking {
protected:
    virtual void Boil() override {
        std::cout << "正在煮水... (用于咖啡)";
    }
    virtual void Brew() override {
        std::cout << "正在用沸水冲泡咖啡粉...";
    }
    virtual void PourInCup() override {
        std::cout << "将冲泡好的咖啡倒入咖啡杯...";
    }
    virtual void PutSth() override {
        std::cout << "添加牛奶和糖...";
    }
};

class Tea: public AbstractDrinking {
protected:
    virtual void Boil() override {
        std::cout << "正在煮水... (用于茶)";
    }
    virtual void Brew() override {
        std::cout << "正在用沸水冲泡茶叶...";
    }
    virtual void PourInCup() override {
        std::cout << "将冲泡好的茶水倒入茶杯...";
    }
    virtual void PutSth() override {
        std::cout << "添加柠檬片...";
    }
};

void doDrinking(AbstractDrinking* abs) {
    abs->makeDrink();
    delete abs;
    abs = nullptr;
}

void test3() {
    doDrinking(new Coffee);
    doDrinking(new Tea);
}

int main() {
    std::cout << "Hello World" << std::endl;
    Cat cat;
    Animal animal;
    int choose;
    std::cin >> choose;
    switch(choose) {
        case 1:
            test1(cat, animal);
            break;
        case 2:
            test2();
            break;
        case 3:
            test3();
            break;
    }
    return 0;
}