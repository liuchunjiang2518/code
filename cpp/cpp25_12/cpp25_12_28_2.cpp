#include <iostream>
#include <string>

// 友元
// 让其它类或函数访问私有属性
class Building;
class BadGuy {
public:
    Building* room;
    BadGuy();
    ~BadGuy();
    void visit();
};

class Building {
    friend void visit(Building* room);
    friend class GoodGuy;
    friend void BadGuy::visit();
public:
    Building () {
        sittingRoom = "客厅";
        bedRoom = "卧室";
    }
    std::string sittingRoom;
private:
    std::string bedRoom;
};

void visit(Building* room) {
    std::cout << "友元函数：" << room->sittingRoom << room->bedRoom << std::endl;
}

BadGuy::BadGuy() {
    room = new Building;
}

BadGuy::~BadGuy() {
    delete room;
    room = nullptr;
}

void BadGuy::visit() {
    std::cout << "友元成员函数：" << room->sittingRoom << room->bedRoom << std::endl;
}

class GoodGuy {
public:
    Building* room;
    GoodGuy();
    ~GoodGuy();
    void visit();
};

GoodGuy::~GoodGuy() {
    delete room;
    room = nullptr;
}

GoodGuy::GoodGuy() {
    room = new Building;
}

void GoodGuy::visit() {
    std::cout << "友元类：" << room->sittingRoom << room->bedRoom << std::endl;
}

void test1() {
    Building* room = new Building;
    visit(room);
    delete room;
    room = nullptr;
}

void test2() {
    GoodGuy gg;
    gg.visit();
}

void test3() {
    BadGuy bg;
    bg.visit();
}

int main() {
    std::cout << "Hello World" << std::endl;
    test1();
    test2();
    test3();
    return 0;
}