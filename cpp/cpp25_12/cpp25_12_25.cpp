#include <iostream>
#include <string>

// 引用
int testReference()
{
    // 引用不可更改，必须初始化
    // (int& ref = a) == (int* const ref = &a)
    int a = 10;
    int& b  = a;
    b = 20;
    std::cout << a << std::endl;
    return 0;
}

// 常量引用
void test2(const int& a)
{
    // a 不能修改
    std::cout << a << std::endl;
}

void mySwap(int& x,int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

// int sum在函数结束后会销毁，需要动态内存管理
int* add(int x,int y)
{
    int* sum = new int;
    *sum = x + y;
    return sum;
}

// static
int* testStatic()
{
    static int num = 10;
    return &num;
}

int* test(int* arr,int len)
{
    static int max = arr[0];
    for (int i = 1;i < len;i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return &max;
}

int main()
{
    // testReference();
    // int* res = add(2,5);
    // std::cout << *res << std::endl;
    // delete res;
    // res = nullptr;
    // std::cout << *testStatic() << std::endl;
    int a = 100;
    test2(a);
    return 0;
}