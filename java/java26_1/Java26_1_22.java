import java.util.Scanner;

public class Java26_1_22 {
    public static void main(String[] args) {
        System.out.println("Hello World");
        // test1();
        // test2();
        // test3();
        // test4();
        // test5();
        // test6();
        // test7();
        // test8();
        test9();
    }

    // 变量，字面量
    public static void test1() {
        int a = 100;
        int max = 1000, min = 12;
        min = min + 1000;
        min -= 12;
        min--;
        System.out.println(max > min);
        System.out.println(a);
        System.out.println(true);
        System.out.println("name" + '\t' + "age"); // 前面字符串补齐8个字符
        System.out.println("abcd" + '\t');
        System.out.println(017); // 八进制
        System.out.println(0x7fffffff); // 十六进制
        System.out.println(0b101011);
        System.out.println("What's wrong with you");
        long n = 999999999L;
        System.out.println(n);
        float f = 3.14F;
        System.out.println(f);
    }

    public static void test2() {
        String name = "万春宏";
        int age = 19;
        double height = 175.1;
        System.out.println(name);
        System.out.println(age);
        System.out.println(height);
    }

    public static void test3() {
        Scanner sc = new Scanner(System.in);
        int i = sc.nextInt();
        System.out.println(i);
        sc.close();
    }

    public static void test4() {
        System.out.println(1.2 + 1.01);
        System.out.println(10 % 3);
        System.out.println(1234 / 3);
    }

    public static void test5() {
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入一个三位数");
        int a = sc.nextInt();
        System.out.println(a % 10);
        System.out.println(a /10 % 10);
        System.out.println(a / 100);
        sc.close();
    }

    public static void test6() {
        byte a = 10, b = 21;
        System.out.println(a + b); // a,b两个byte加后为int同样还有char short
        byte result = (byte)(a + b);
        System.out.println(result);
        System.out.println(3.7 + "Hello" + true + a);
        // 字符加数字得数字通过ASII，字符串加数字为字符串拼接
        System.out.println(a++);
        int x = 10;
        int y = x++;
        y++;
        System.out.println(x == y);
        double num1 = 12.1;
        int num2 = 12;
        System.out.println(num1 > num2);
    }

    public static boolean test7() {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        sc.close();
        System.out.println(a > b);
        boolean result = a > b;
        return result;
    }

    public static boolean test8() {
        // 短路与或
        int a = 10, b = 10;
        boolean result = a++ < 5 && b++ > 5;
        System.out.println(b);
        result = a == 20 || b == 20 || a + b == 20;
        return result;
    }

    // 三元
    public static void test9() {
        Scanner sc = new Scanner(System.in);
        int num1 = sc.nextInt();
        int num2 = sc.nextInt();
        sc.close();
        int num3 = num1 > num2 ? 20 : 9;
        System.out.println(num3);
    }
}