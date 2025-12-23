#include "iostream"
#include "string"
#include "cstring"
#include "random"
#include "ctime"
using namespace std;
#define MAX 0x7fffffff // 符号常量

// cout打印到控制台
int testCout()
{
    // endl换行
    cout << "我是万春宏" << endl; 
    cout << 10 << endl;
    cout << 10 << endl << 20 << endl;
    cout << "我是" << "谁" << endl;
    cout << "If you want to learn IT," << "come to itheima" << endl;
    return 0;
}

// 常量
int testConst()
{
    /*
        整型(整数) 21;
        实型(小数) 21.3;
        字符 'c';
        字符串 "abcd";
    */
    return 0;
}

// 标识符
int testVariables()
{
    int age = 18;
    float height = 1.75;
    char rank = 'A';
    string name = "WanChunhong";
    cout << name << "年龄是" << age << "身高是" << height << "等级是" << rank << endl;
    int bmi = 30;
    cout << bmi << endl;
    bmi = bmi - 20;
    cout << bmi << endl;
    int a,b,c;
    a = 1;
    b = 2;
    c = 3;
    cout << a << b << c << endl;
    unsigned int num; // (0 ~ 2 ^ 32 - 1)
    return 0;
}

// 字符串
int testString()
{
    string chun = "Chun";
    string str1 = "12";
    string str2 = "34";
    string res = str1 + str2;
    int num = 123;
    string name = "Wan" + chun + "Hong" + to_string(num);
    cout << name << endl << res;
    return 0;
}

// 布尔类型
int testBool()
{
    bool flag = true;
    cout << flag << endl << !flag << endl;
    return 0;
}

int testCin()
{
    int num;
    string str;
    cout << "输入一个整数" << endl;
    cin >> num;
    cout << "输入一个字符串" << endl;
    cin >> str;
    cout << num << endl;
    cout << str << endl;
    return 0;
}
 
// 算术运算符
int testArithOps()
{
    int a = 10,b = 9;
    int res = 0;
    a += b;
    b = b / 3;
    b++;
    res = --a * b;
    int c = 10 % 3;
    cout << res << endl << c << endl;
    return 0;
}

// 比较运算符
int testCmp()
{
    // c的风格 比较的内存地址
    char s1[] = "hello";
    char s2[] = "hello";
    cout << (s1 == s2) << endl;
    int result = strcmp(s1,s2);
    cout << result << endl;
    // cpp风格 比较的内容
    string str1 = "hello";
    string str2 = "Hello";
    cout << (str1 >= str2) << endl;
    cout << (s1 == str1) << endl;
    int num1 = 12, num2 = 5;
    bool r1 = num1 >= num2;
    cout << r1 << endl; 
    return 0;
}

// 三元运算符
int testTernaryOperator()
{
    int num1,num2;
    cin >> num1;
    cin >> num2;
    int res = num1 > num2 ? num1 : num2;
    cout << res << endl;
    return 0;
}

int test1()
{
    int score1,score2;
    int sugar = 0;
    cin >> score1;
    cin >> score2;
    score1 < score2 ? sugar++ : sugar;
    cout << sugar << endl;
    return 0;
} 

// if判断
int testIf()
{
    int money;
    bool computer = false;
    cin >> money; 
    if(money > 10000)
    {
        computer = true;
        money -= 10000;
        cout << "获得电脑" << endl;
    }
    cout << "钱还有" << money << endl;
    bool love;
    cin >> love; // 输入0或1
    if(love)
    {
        cout << "good" << endl;
    }
    else
    {
        cout << "bad" << endl;
    }
    return 0;
}

int love()
{
    string love;
    cin >> love;
    if(love == "wan")
    {
        cout << "wanlove" << endl;
    }
    else if(love == "chun")
    {
        cout << "chunlove" << endl;
    }
    else
    {
        cout << "honglove" << endl;
    }
    return 0;
}

int guess()
{
    int num = 3;
    int count = 3;
    int guess_num;
    while (count)
    {
        count--;
        cout << "剩余次数：" << count + 1 <<endl;
        cin >> guess_num;
        if (guess_num == num)
        {
            cout << "猜对了" << endl;
            break;
        }
        else if (guess_num < num)
        {
            cout << "猜小了" << endl;
        }
        else
        {
            cout << "猜大了" << endl;
        }
        if (count == 0)
        {
            cout << "次数用完啦，正确数字是：" << num << endl;
        }
 
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

int pork()
{
    int num = getRandomNum(1,10);
    string color = getRandomNum(0,1) ? "Red" : "Black";
    string suit;
    if (color == "Red")
    {
        suit = getRandomNum(0,1) ? "Heart" : "Diamond";
    }
    else
    {
        suit = getRandomNum(0,1) ? "Spade" : "Club ";
    }
    // cout << num << color << suit << endl;
    int guess_num;
    string guess_color;
    string guess_suit;
    bool flag = true;
    while (flag)
    {
        cout << "猜数字" << endl;
        cin >> guess_num;
        if (guess_num == num)
        {
            cout << "猜对了" << "猜颜色" << endl;
            cin >> guess_color;
            if (guess_color == color)
            {
                cout << "猜对了" << "猜花色" << endl;
                cin >> guess_suit;
                if (guess_suit == suit)
                {
                    cout << "猜对了" << num << color << suit << endl;
                    flag = false;
                }
            }
            else
            {
                cout << "错误" << endl;
            }
        }
        else
        {
            cout << "错误" << endl;
        }
    }
    return 0;
}

int main()
{
    // testCout();
    // testConst();
    // testVariables();
    // testString();
    // testBool();
    // testCin();
    // testArithOps();
    // testCmp();
    // testTernaryOperator();
    // test1();
    // testIf();
    // love();
    // guess();
    pork();
    return 0;
}