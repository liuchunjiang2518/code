#include <iostream>
#include <fstream>
#include <string>

void test1() {
    std::ofstream ofs;
    ofs.open("cpp26_1_12.txt", std::ios::out);
    ofs << "Hello World" << std::endl << "I'm WanChunhong" << std::endl << "Who Are You";
    ofs.close();
}

void test2() {
    std::ifstream ifs;
    ifs.open("cpp26_1_12.txt", std::ios::in);
    if (!ifs.is_open()) {
        std::cout << "文件打开失败" << std::endl;
        return;
    }
    std::string data;
    while (getline(ifs, data)) {
        std::cout << data << std::endl;
    }
}

class Test {
public:
    char name[64];
    int age;
};

void test3() {
    std::ofstream ofs;
    ofs.open("cpp_26_1_12_Test.txt", std::ios::out | std::ios::binary);
    Test wanchunhong = {"万春宏", 19};
    ofs.write((const char*)& wanchunhong, sizeof(Test));
    ofs.close();
}

void test4() {
    std::ifstream ifs;
    ifs.open("cpp26_1_12_Test.txt", std::ios::in | std::ios::binary);
    if (!ifs.is_open()) {
        std::cout << "文件打开失败" << std::endl;
        return;
    }
    Test wanchunhong;
    ifs.read((char*)& wanchunhong, sizeof(Test));
    std::cout << wanchunhong.name << wanchunhong.age <<std::endl;
}

int main() {
    std::cout << "Hello World" << std::endl;
    int choose;
    std::cin >> choose;
    switch(choose) {
        case 1:
            test1();
            break;
        case 2:
            test2();
            break;
        case 3:
            test3();
            break;
        case 4:
            test4();
            break;
    }
    return 0;
}