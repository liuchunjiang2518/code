// 多态案例，电脑组装
#include <iostream>

class CPU {
public:
    virtual ~CPU() = default; 
    virtual void caculator() = 0;
};

class GPU {
public:
    virtual ~GPU() = default;
    virtual void display() = 0;
};

class Memory {
public:
    virtual ~Memory() = default;
    virtual void storage() = 0;
};

class IntelCPU: public CPU {
public:
    void caculator() override {
        std::cout << "[Intel CPU] 开始计算..." << std::endl;
    } 
};

class AMDCPU: public CPU {
public:
    void caculator() override {
        std::cout << "[AMD CPU] 开始计算..." << std::endl;
    } 
};

class NvidiaGPU: public GPU {
public:
    void display() override {
        std::cout << "[Nvidia GPU] 开始渲染画面..." << std::endl;
    } 
};

class AMDGPU: public GPU {
public:
    void display() override {
        std::cout << "[AMD GPU] 开始渲染画面..." << std::endl;
    } 
};

class SamsungMemory: public Memory {
public:
    void storage() override {
        std::cout << "[Samsung Memory] 开始存储数据..." << std::endl;
    } 
};

class Computer {
public:
    Computer(CPU* s_cpu, GPU* s_gpu, Memory* s_mem) {
        cpu = s_cpu;
        gpu = s_gpu;
        mem = s_mem;
    }

    void work() {
        cpu->caculator();
        gpu->display();
        mem->storage();
    }

    ~Computer() {
        delete cpu;
        delete gpu;
        delete mem;
    }

private:
    CPU* cpu;
    GPU* gpu;
    Memory* mem;
};

int main() {
    std::cout << "Hello World" << std::endl;
    Computer computer1(new IntelCPU(), new NvidiaGPU(), new SamsungMemory());
    Computer computer2(new AMDCPU(), new AMDGPU(), new SamsungMemory());
    Computer computer3(new IntelCPU(), new AMDGPU(), new SamsungMemory());
    int choose;
    std::cin >> choose;
    switch (choose) {
        case 1:
            computer1.work();
            break;
        case 2:
            computer2.work();
            break;
        case 3:
            computer3.work();
            break;
    }
    return 0;
}