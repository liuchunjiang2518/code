import java.util.Scanner;
import java.util.StringJoiner;

public class Java26_1_28 {
    public static void main(String[] args) {
        // test1();
        // test2();
        // test3();
        // test4();
        // test5();
        // test6();
        // test7();
        // test8();
        // test9();
        test10();
    }

    public static void test1() {
        Role r1 = new Role("万春宏", 100, 25);
        Role r2 = new Role("徐国平", 75, 40);
        r1.attack(r2, 15);

        int num = 520;
        String str = "万春宏";
        System.out.printf("num:%d,str:%s\n", num, str);
    }

    public static void test2() {
        Goods[] arr = new Goods[3];
        Goods g1 = new Goods("G001", "手机", 8888.88, 1000);
        Goods g2 = new Goods("F1452", "南瓜", 12.5, 20000);
        Goods g3 = new Goods("S025", "保温杯", 50.0, 300);

        arr[0] = g1;
        arr[1] = g2;
        arr[2] = g3;

        for (int i = 0; i < arr.length; i++) {
            Goods goods = arr[i];
            System.out.printf("%s, %s, %.2f, %d\n", goods.getId(), goods.getName(), goods.getPrice(), goods.getCount());
        }
    }

    public static void test3() {
        Student[] students = new Student[3];
        Student s1 = new Student("s001", "WanChunhong", 19);
        Student s2 = new Student("s002", "LiuYuping", 20);
        Student s3 = new Student("s003", "ZhaoZilong", 25);
        students[0] = s1;
        students[1] = s2;
        students[2] = s3;

        Scanner sc = new Scanner(System.in);

        students = Student.insertStudent(students, sc);
        Student.printStudents(students);
        Student.deleteStudent(students, "s002");
        Student.printStudents(students);
        Student.updateStudent(students, "s003", sc);
        Student.printStudents(students);

        sc.close();
    }

    public static void test4() {
        String str1 = "abc";
        System.out.println(str1);

        String str2 = new String();
        System.out.println(str2);

        char[] chs = {'a', 'b', 'c'};
        String str3 = new String(chs);
        System.out.println(str3);

        byte[] bts = {97, 98, 99, 100};
        String str4 = new String(bts);
        System.out.println(str4);
    }

    public static void test5() {
        String str1 = "abc";
        String str2 = new String("abc");
        String str3 = "abc";
        String str4 = "ABC";
        Scanner sc = new Scanner(System.in);
        String str5  = sc.next(); // str5 为 new 出的对象;
        sc.close();
        
        System.out.println(str1 == str2);
        System.out.println(str1.equals(str2));
        System.out.println(str1 == str3);
        System.out.println(str1.equalsIgnoreCase(str4));
        System.out.println(str1 == str5);
    }

    public static void test6() {
        String userId = "WanChunhong";
        String password = "123456";

        Scanner sc = new Scanner(System.in);
        int count = 3;
        while (count > 0) {
            String scUserId = sc.next();
            String scPassword = sc.next();

            if (userId.equals(scUserId) && password.equals(scPassword)) {
                System.out.println("输入成功");
                break;
            } else {
                System.out.println("输入错误，还有" + (count - 1) + "次机会");
            }
        }

        sc.close();
    }

    public static void test7() {
        String str1 = "WanChunhong";
        for (int i = 0; i < str1.length(); i++) {
            System.out.print(str1.charAt(i));
        }
        System.out.println();
    }

    public static void test8() {
        String str1 = "ABdf23!Ggl9";
        int up = 0, down = 0, num = 0;
        for (int i = 0; i < str1.length(); i++) {
            char ch = str1.charAt(i);
            if (ch >= '0' && ch <= '9') {
                num++;
            } else if (ch >= 'A' && ch <= 'Z') {
                up++;
            } else if (ch >= 'a' && ch <= 'z') {
                down++;
            } else {
                System.out.printf("错误字符String[%d]:%c\n", i, str1.charAt(i));
            }
        }
        System.out.println("UP:" + up + " DOWN:" + down + " NUM:" + num);
    }

    public static void test9() {
        int[] arr1 = {1, 2, 3, 4, 5, 6};
        String str1 = "[" + arr1[0];
        for (int i = 1; i < arr1.length; i++) {
            str1 = str1 + ", " + arr1[i];
        }
        str1 += "]";
        System.out.println(str1);

        StringJoiner sj1 = new StringJoiner(", ", "[", "]");
        for (int num: arr1) {
            sj1.add(String.valueOf(num));
        }
        String str2 = sj1.toString();
        System.out.println(str2);
    }

    public static void test10() {
        String str1 = "abcd";
        String str2 = new String();
        for (int i = str1.length() - 1; i >= 0; i--) {
            str2 += str1.charAt(i);
        }
        System.out.println(str2);
    }
}