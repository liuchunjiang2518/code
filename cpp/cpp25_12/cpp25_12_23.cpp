#include <iostream>
#include <random>
#include <string>
using namespace std;

int getRandomNum(int min, int max)
{
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

int test1()
{
    int arr[10];
    int g_arr[10];
    int count = 0;
    for (int i = 0;i < 10;i++)
    {
        arr[i] = getRandomNum(1,10);
    }
    for (int i = 0;i < 10;i++)
    {
        cin >> g_arr[i];
    }
    for (int i = 0;i < 10;i++)
    {
        if (arr[i] == g_arr[i])
        {
            cout << "第" << i + 1 << "个数相等" << endl;
            count++;
        }
    }
    for (int i = 0;i < 10;i++)
    {
        cout << arr[i] << ' ';
    }
    cout << "猜对了" << count << "次" << endl;
    return 0;
}

int testArray()
{
    // 数组定义后长度固定
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    cout << arr << endl;
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << len << endl;
    enum Color
    {
        RED = 1,
        YELLOW,
        BLUE
    };
    Color v[] = {RED,RED,BLUE,YELLOW};
    for (int i = 0;i < 4;i++)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
    for (int i:arr)
    {
        cout << i << endl;
    }
    return 0;
}

int test2()
{
    int arr[10];
    for (int& i:arr)
    {
        i = getRandomNum(1,100);
    }
    int max = arr[0];
    int min = arr[0];
    for (int i:arr)
    {
        if (i > max)
        {
            max = i;
        }
        if (i < min)
        {
            min = i;
        }
    }
    cout << min << ' ' << max << endl;
    return 0;
}

// 多维数组
int testNDArray()
{
    int arr[2][3] = 
    {
        {15,9,20},
        {7,23,19}
    };
    for (auto& i:arr)
    {
        for (int j:i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
    int arr2[2][2][3] = 
    {
        {
            {1,9,14},
            {19,5,39}
        },
        {
            {99,34,2},
            {8,62,0}
        }
    };
    for (auto& i:arr2)
    {
        cout << "---" << endl;
        for (auto& j:i)
        {
            for (int& k:j)
            {
                cout << k << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}

int test3()
{
    string names[] =
    {
        "Landon","Avery","Kamden","Bentley","Finnegan",
        "Nash","Emmett","Greyson","Noah","Jace",
        "Jaxton","Sawyer","Zachary","Eli","Keegan",
        "Lincoln","Isaac","Asher","Declan","Theo",
        "Levi","Dominic","Austin","Wyatt","Carter",
        "Logan","Luke","Max","Ethan","Miles",
        "Oliver","Hudson","Owen","William","Joshua",
        "Benjamin","Henry","Lucas", "Alexander","Jackson",
        "Mason","Grayson","Ryder","Elijah","Liam",
        "Caleb","Thomas","Cooper","Hunter","Connor"
    };
    string arr[2][2][5];
    for (int i = 0; i < 2; ++i)
    {
        string major = (i == 0) ? "物理" : "数学";
        for (int j = 0;j < 2;++j)
        {
            string class_name = (j == 0) ? "一班" : "二班";
            for (int k = 0;k < 5;++k)
            {
                int id = getRandomNum(0, 49);
                arr[i][j][k] = names[id];
                cout << major << class_name << arr[i][j][k] << endl;
            }
        }
    }
    return 0;
}

// 指针
int testPointer()
{
    int num = 10;
    int* p = &num;
    cout << p << endl;
    cout << p + 1 << endl; // 进4位，因为int型
    // int* pb; // 野指针
    // cout << pb << endl;
    int* pa = NULL; // 空指针
    int* pc = nullptr;

    int arr[] = {2,4,6,8};
    int* parr = arr;
    cout << *(parr + 1) << endl;
    
    const int* p1 = &num;
    // *p = 20; 不可以
    int num2 = 20;
    p = &num2;

    int* const p2 = &num;
    // p2 = &num2 不可以
    *p2 = 20;

    const int* const p3 = &num;

    return 0;
}

// 内存分配
int testMemAlloc()
{
    /*
        new type
        new type[n]
        delete 仅可用于new的内存空间
        delete pointer
        delete[] pointer
    */
    int* p = new int;
    delete p;
    int* arr = new int[5] {1,2,3,4,5};
    int* new_arr = new int[4];
    int j = 0;
    for (int i = 0;i < 5;i++)
    {
        if (i == 2)
        {
            continue;
        }
        new_arr[j++] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    return 0;
}

int test4()
{
    int* arr = new int[10] {3,5,1,11,99,66,22,2,8,6};
    int* new_arr = new int[8];
    int j = 0;
    for (int i = 0;i < 10;i++)
    {
        if (i == 0 || i == 5)
        {
            continue;
        }
        new_arr[j++] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    for (int i = 0;i < 8;i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}

int test5()
{
    int* arr = new int[4] {3,6,9,0};
    int* new_arr = new int[6];
    int k = 0;
    for (int i = 0;i < 6;i++)
    {
        if (i == 1 || i == 3)
        {
            new_arr[i] = 7;
        }
        else
        {
            new_arr[i] = arr[k++];
        }
    }
    delete[] arr;
    arr = new_arr;
    for (int i = 0;i < 6;i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}

int sort()
{
    int* arr = new int[10] {3,5,1,11,99,66,22,2,8,6};
    int temp = 0;
    for (int i = 0;i < 9;i++)
    {
        for (int j = i + 1;j < 10;j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0;i < 10;i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}

int main()
{ 
    cout << "Hello World" << endl;
    // test1();
    // testArray();
    // test2();
    // testNDArray();
    // test3();
    // testPointer();
    // test4();
    // test5();
    sort();
    return 0;
}