#include "iostream"
#include "random"
#include "ctime"
using namespace std;

//复杂判断
bool isZooFree()
{
    int age;
    float height;
    bool flag;
    cin >> age >> height;
    if (age < 0 || height < 0)
    {
        return false;
    }
    return (age < 18 && height < 1.5);
}

// switch
int testSwitch()
{
    int score;
    cin >> score;
    switch (score)
    {
        case 0:
        case 1:
            cout << "good" << endl;
            break;
        case 2:
            cout << "normal" << endl;
            break;
        default:
            cout << "bad" << endl;
    }
    return 0;
}

int live()
{
    int status;
    cin >> status;
    switch (status)
    {
        case 1:
            cout << "屏幕" << endl;
            break;
        case 2:
            cout << "屏幕+摄像头" << endl;
            break;
        case 3:
            cout << "摄像头" << endl;
            break;
        default:
            cout << "输入错误" << endl;
    }
    return 0;
}

// 枚举
int testEnum()
{
    enum Season
    {
        SPRING = 1,
        SUMMER,
        AUTUMN,
        WINTER
    };
    int r1;
    cin >> r1;
    switch (r1)
    {
        case SPRING:
            cout << "spring" << endl;
            break;
        case SUMMER:
            cout << "summer" << endl;
            break;
        case AUTUMN:
            cout << "autumn" << endl;
            break;
        case WINTER:
            cout << "winter" << endl;
            break;
        default:
            cout << "输入错误" << endl;
    }
    return 0;
}

// while
int testWhile()
{
    int count = 9;
    while (count)
    {
        if (count == 5)
        {
            count--;
            continue;
        }
        cout << count << endl;
        count--;
    }
    return 0;
}

int test1(int num)
{
    int res = 0;
    while (num)
    {
        res += num;
        num--;
    }
    cout << res << endl;
    return 0;
}

// do while
int testDoWhile()
{
    int num = 23;
    int count = 0;
    int g_num = -1;
    do
    {
        cin >> g_num;
        count++;
        if (g_num > num)
        {
            cout << "猜大了" << endl;
        }
        else if (g_num < num)
        {
            cout << "猜小了" << endl;
        }
    }while (g_num != num);
    cout << "猜对了" << endl;
    return 0;
}

// 九九乘法表
int test2()
{
    int i = 1;
    while (i < 10)
    {
        int j = 1;
        while (j <= i)
        {
            cout << j << '*' << i << '=' << i * j << '\t';
            j++;
        }   
        cout << endl;
        i++;
    }
    return 0;
}

// for
int testFor()
{
    for (int num = 1;num <= 9;num += 2)
    {
        cout << num << endl;
    }
    return 0;
}

int getRandomNum(int min,int max)
{
    if (min > max) swap(min,max);
    static mt19937 gen(random_device{}() + time(nullptr));
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

int test3()
{
    int balance = 10000;
    for (int i = 1;i <= 20;i++)
    {
        int score = getRandomNum(1,10);
        if (score < 5)
        {
            continue;
        }
        cout << "第" << i << "名员工领了" << endl;
        balance -= 1000;
        if (balance <= 0)
        {
            cout << "领完了" << endl;
            break;
        } 
    }
    return 0;
}

// goto
int testGoto()
{
    int i = 1;
    loop:
        cout << i << endl;
        i++;
        if (i < 10)
        {
            goto loop;
        }
    return 0;
}

// 数组
int testArray()
{
    int arr[6] = {1,2,3,4,5,6};
    for (int i = 0;i < 6;i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}

int main()
{
    // testSwitch();
    // live();
    // testEnum();
    // testWhile();
    // test1(3);
    // testDoWhile();
    // test2();
    // testFor();
    // test3();
    // testGoto();
    testArray();
    return 0;
}