import java.util.Scanner;
import java.util.Random;

public class Java26_1_22_2 {
    public static void main(String[] args) {
        // test1();
        // test2();
        // test3();
        // test4();
        // test5();
        // test6();
        test7();
    }
    
    public static void test1() {
        Scanner sc = new Scanner(System.in);
        int flag = sc.nextInt();
        if (flag == 1) {
            System.out.println("这是一个判读语句");
        } else if (flag == 0) {
            System.out.println("外币八部");
        } else {
            System.out.println("hhhh");;
        }
        
        int score = 93;
        if (score > 0 && score < 100) {
            if (score > 95) {
                System.out.println("good");
            } else if (score > 90) {
                System.out.println("normal");
            } else {
                System.out.println("bad");
            }
        }
        
        int day = sc.nextInt();
        switch(day) {
            case 1:
                System.out.println("周一");
                break;
            case 2:
                System.out.println("周二");
                break;
            case 3:
                System.out.println("周三");
                break;
            case 4:
                System.out.println("周四");
                break;
            case 5:
                System.out.println("周五");
                break;
            case 6:
                System.out.println("周六");
                break;
            case 7:
                System.out.println("周日");
                break;
            default:
                System.out.println("输入错误");
                break;
        }

        switch(day) {
            case 1, 2, 3, 4, 5 -> System.out.println("工作日");
            case 6, 7 -> System.out.println("休息日");
            default -> System.out.println("输入错误");
        }

        sc.close();
    }

    public static void test2() {
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < 4; i++) {
            System.out.println(i);
        }

        boolean flag = true;
        while (flag == true) {
            System.out.println("请输入5否则循环");
            int a = sc.nextInt();
            if (a == 5) {
                flag = false;
            }
        }

        int result = 0;
        for (int i = 1; i < 6; i++) {
            result += i;
        }
        System.out.println(result);

        result = 0;
        for (int i = 0; i < 11; i += 2) {
            result += i;
        }
        System.out.println(result);

        int range = 30;
        int count = 0;
        for (int i = 1; i <= range; i++) {
            if (i % 2 == 0 && i % 3 == 0) {
                System.out.println(i);
                count++;
            }
        }
        System.out.println(count);

        sc.close();
    }

    public static void test3() {
        int x = 3, y = 16;
        int mod = y, div = 0;
        while (mod > x) {
            mod -= x;
            div++;
        }
        System.out.println(div);
        System.out.println(mod);
    }

    public static void test4() {
        int num = 1;
        while (num <= 100) {
            if (num % 7 == 0 || num / 10 == 7 || num % 10 == 7) {
                System.out.println("过");
                num++;
                continue;
            }
            System.out.println(num);
            num++;
        }
    }

    public static void test5() {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        int result = 0;
        if (num > 0) {
            for (int i = 1; i < num; i++) {
                if (i * i > num) {
                    result = i - 1;
                    break;
                }
            }
        } else {
            System.out.println("输入错误");
        }
        System.out.println(result);

        sc.close();
    }

    public static void test6() {
        for (int i = 1; i <= 100; i++) {
            if (i == 1) {
                System.out.println(i + "既不是合数也不是质数");
                continue;
            }
            if (i == 2) {
                System.out.println(i + "是质数");
                continue;
            }

            boolean isPrime = true;
            for (int j = 2; j <= (int)Math.sqrt(i) + 1; j++) {
                if (i % j == 0) {
                    System.out.println(i + "是合数");
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                System.out.println(i + "是质数");
            }
        }
    }

    public static void test7() {
        Random rd = new Random();
        int num = rd.nextInt(100);
        Scanner sc = new Scanner(System.in);
        int guessNum = 0;
        while (true) {
            guessNum = sc.nextInt();
            if (guessNum > num) {
                System.out.println("大了");
            } else if (guessNum < num) {
                System.out.println("小了");
            } else {
                System.out.println(num);
                break;
            }
        }
        sc.close();
    }
}
