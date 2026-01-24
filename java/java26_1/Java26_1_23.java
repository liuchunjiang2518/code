import java.util.Random;
import java.util.Scanner;

public class Java26_1_23 {
    public static void main(String[] args) {
        // test1();
        // test2();
        // test3();
        // test4(4, 3);
        // test5();
        // test6();
        // test7();
        // test8();
        test9(1);
    }

    public static void test1() {
        int[] arr1 = {1, 2, 3, 4, 5, 6, 7, 8};
        for (int i = 0; i < arr1.length; i++) {
            System.out.println(arr1[i]);
        }

        int[] arr2 = new int[] {0, 22, 33};
        arr2[0] = 11;

        String[] names = {"万春宏", "刘玉平", "朱家平"};
        System.out.println(names[0]);
        
        int sum = 0;
        for (int i = 0; i < arr2.length; i++) {
            sum += arr2[i];
        }
        System.out.println(sum);

        int count = 0;
        int[] arr3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for (int i = 0; i < arr3.length; i++) {
            if (arr3[i] % 3 == 0) {
                count++;
            }
        }
        System.out.println(count);

        for (int i: arr3) {
            System.out.println(i);
        }
    }

    public static void test2() {
        int[] arr1 = {33, 5, 22, 44, 55};
        int max = arr1[0];
        for (int item: arr1) {
            if (item > max) {
                max = item;
            }
        }
        System.out.println(max);

        Random rd = new Random();
        int[] arr2 = new int[10];
        int sum = 0;
        for (int i = 0; i < arr2.length; i++) {
            arr2[i] = rd.nextInt(1,101);
            sum += arr2[i];
        }
        System.out.println(sum);
        int avg = sum / arr2.length;
        int count = 0;
        for (int item: arr2) {
            if (item < avg) {
                count++;
            }
        }
        System.out.println(count);

        int[] arr3 = {1, 2, 3, 4, 5};
        int temp = 0;
        for (int i = 0; i < arr3.length / 2; i++) {
            temp = arr3[i];
            arr3[i] = arr3[arr3.length - 1 - i];
            arr3[arr3.length - 1 - i] = temp;
        }
        for (int item: arr3) {
            System.out.println(item);
        }
    }

    public static void test3() {
        int[] arr1 = {1, 2, 3, 4, 5, 6};
        Random rd = new Random();
        int temp = 0;
        int idx = 0;
        for (int i = 0; i < arr1.length; i++) {
            idx = rd.nextInt(arr1.length);
            temp = arr1[i];
            arr1[i] = arr1[idx];
            arr1[idx] = temp;
        }
        for (int i = 0; i < arr1.length; i++) {
            System.out.println(arr1[i]);
        }
    }

    public static int test4(int x, int y) {
        int result = x * 2 + y * 2;
        System.out.println(result);
        return result;
    }

    // 重载
    public static double test4(int x) {
        double result = x * x * 3.14;
        return result;
    }

    public static void test4(byte x, byte y) {
        if (x > y) {
            System.out.println(x + "大于" + y);
        } else {
            System.out.println(x + "小于或等于" + y);
        }
    }
    
    public static void printArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            if (i == arr.length - 1) {
                System.out.println(arr[i]);
            } else {
                System.out.print(arr[i] + ", ");
            }
        }
    }

    public static int arrayMax(int[] arr) {
        int max = arr[0];
        for (int item: arr) {
            if (item > max) {
                max = item;
            }
        }
        return max;
    }

    public static int searchArray(int[] arr, int val) {
        int idx = -1;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == val) {
                idx = i;
                System.out.println(val + "在数组存在，索引为" + i);
                break;
            }
        }
        if (idx == -1) {
            System.out.println(val + "在数组不存在");
        }
        return idx;
    }

    // 包含左右索引
    public static int[] copyArray(int[] arr, int from, int to) {
        int[] newArr = new int[to - from + 1];
        int idx = 0;
        for (int i = from; i < to + 1; i++) {
            newArr[idx++] = arr[i];
        }
        return newArr;
    }

    public static void test5() {
        byte x = 1, y = 2;
        test4(x, y);

        int[] arr1 = {1, 2, 3, 5, 6};
        printArray(arr1);

        int[] arr2 = {9, 12, 3, 7, 4};
        System.out.println(arrayMax(arr2));

        searchArray(arr2, 7);

        int[] arr3 = copyArray(arr2, 1, 3);
        printArray(arr3);
    }

    public static int test6() {
        Scanner sc = new Scanner(System.in);
        System.out.println("输入票价");
        int ticket = sc.nextInt();
        System.out.println("输入月份");
        int month = sc.nextInt();
        System.out.println("是否为vip");
        boolean vip = sc.nextBoolean();
        if (month >= 5 && month <= 10) {
            if (vip) {
                ticket *= 0.9;
            } else {
                ticket *= 0.85;
            }
        } else if ((month >= 1 && month <= 4) || (month >= 11 && month <=12)) {
            if (vip) {
                ticket *= 0.7;
            } else {
                ticket *= 0.65;
            }
        } else {
            System.out.println("输入月份有误");
        }
        sc.close();
        System.out.println(ticket);
        return ticket;
    }

    public static char getRandomChar() {
        Random rd = new Random();
        boolean up = rd.nextBoolean();
        char ch;
        if (up) {
            ch = (char)('A' + rd.nextInt(26));
        } else {
            ch = (char)('a' + rd.nextInt(26));
        }
        return ch;
    }

    public static String test7() {
        Random rd = new Random();
        String result = "";
        
        for (int i = 0; i < 4; i++) {
            result = result + getRandomChar();
        }
        result = result + rd.nextInt(10);

        for (int i = 0; i < result.length(); i++) {
            System.out.println(result.charAt(i));
        }

        return result;
    }

    public static void test8() {
        Random rd = new Random();
        int[] arr = new int[6];
        int max_idx = 0, min_idx = 0;
        int sum = 0;
        for (int i = 0; i < arr.length; i++) {
            arr[i] = rd.nextInt(101);
            if (arr[i] > arr[max_idx]) {
                max_idx = i;
            }
            if (arr[i] < arr[min_idx]) {
                min_idx = i;
            }
            sum += arr[i];
        }
        sum = sum - arr[max_idx] - arr[min_idx];
        System.out.println(sum / (arr.length - 2));
    }

    public static void test9() {
        String originalPassword = "19830";
        StringBuilder passwordBuffer = new StringBuilder(originalPassword);

        for (int i = 0; i < passwordBuffer.length(); i++) {
            char currentChar = passwordBuffer.charAt(i);
            char newChar = (char) (((currentChar - '0') + 5) % 10 + '0');
            passwordBuffer.setCharAt(i, newChar);
        }

        String newPassword = passwordBuffer.toString();
        System.out.println("原密码: " + originalPassword);
        System.out.println("加密后密码: " + newPassword);
    }

    public static String test9(int x) {
        String result = "";
        int[] arr = {x, 9, 8, 3, 0};
        for (int i = 0; i < arr.length; i++) {
            arr[i] = (arr[i] + 5) % 10;
        }
        for (int i = 0; i < arr.length / 2; i++) {
            int temp = 0;
            temp = arr[i];
            arr[i] = arr[arr.length - 1 - i];
            arr[arr.length - 1 - i] = temp;
        }
        for (int i = 0; i < arr.length; i++) {
            result = result + arr[i];
        }
        for (int i = 0; i < arr.length; i++) {
            System.out.println(result.charAt(i));;
        }
        return result;
    }
}
