#include <iostream>
#include <string>
#include <utility>

int sort()
{
    // 初始化
    int* arr = new int[10] {3,5,1,11,99,66,22,2,8,6};
    const int len = 10;
    
    // 选择排序
    int min_idx;
    int temp;
    for (int i = 0;i < len - 1;i++)
    {
        min_idx = i;
        for (int j = i + 1;j < len;j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j; 
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }

    // 遍历数组
    for (int i = 0;i < len;i++)
    {
        std::cout << arr[i] << std::endl;
    }

    return 0;
}

struct Stu
{
    // 结构体可以有默认值
    std::string name = "null";
    char sex = 'n';
    int age = -1;
};

// 结构体
int testStruct()
{
    struct Stu liu = {"刘玉平",'m',45};
    struct Stu wan;
    wan.name = "万春宏";
    wan.sex = 'm';
    wan.age = 19;
    std::cout << wan.name << wan.sex << wan.age << std::endl;
    struct Stu students[3];
    students[0] = wan;
    std::cout << students[0].name << std::endl;
    struct Stu* S = new Stu {};
    *S = wan;
    std::cout << S->name << std::endl;
    return 0;
}

// 函数
int max(int val1,int val2,int val3)
{
    int max = val1 > val2 ? val1:val2;
    max = val3 > max ? val3:max;
    return max;
}

int func(int num)
{
    if (num == 1)
    {
        return 1;
    }
    return num + func(num - 1);
}

typedef struct Num
{
    int max;
    int min;
}Num;

Num func2(int val1,int val2)
{
    Num num;
    num.max = val1 > val2 ? val1:val2;
    num.min = val1 < val2 ? val1:val2;
    return num;
}

void mySwap(int& x,int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

void printArr(int* arr,int len)
{
    for (int i = 0;i < len;i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

void sort2(int* arr,int len)
{
    int min_idx;
    for (int i = 0;i < len - 1;i++)
    {
        min_idx = i;
        for (int j = i + 1;j < len;j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        std::swap(arr[i],arr[min_idx]);
    } 
}

int main()
{
    int arr[10] = {3,5,1,11,99,66,22,2,8,6};
    int len = sizeof(arr) / sizeof(arr[0]);
    // sort();
    // testStruct();
    std::cout << func(4) << std::endl;
    return 0;
}