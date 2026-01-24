import java.util.Random;
import java.util.Scanner;

public class Java26_1_23_2 {
    public static void main(String[] args) {
        // test1(1897);
        // test2();
        // System.out.println(test3());
        // test4();
        test5();
    }

    public static int test1(int num) {
        int len = 0;
        int current = num;
        while (current > 0) {
            len++;
            current /= 10;
        }
        current = num;
        int[] arr = new int[len];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = current % 10;
            current /= 10;
            System.out.println(arr[i]);
        }
        return len;
    }

    public static boolean isInRandomArr(int[] arr, int num) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == num) {
                return true;
            }
        }
        return false;
    }

    public static void test2() {
        int[] arr = {2, 588, 888, 1000, 10000};
        int[] randomArr = new int[5];
        Random rd = new Random();
        int idx = 0;
        for (int i = 0; i < arr.length;) {
            idx = rd.nextInt(5);
            if (!isInRandomArr(randomArr, arr[idx])) {
                randomArr[i] = arr[idx];
                i++;
            }
        }
        for (int i = 0; i < randomArr.length; i++) {
            System.out.println(randomArr[i]);
        }
    }

    public static boolean contains(int[] arr, int num) {
        for (int i = 0; i < arr.length - 1; i++) {
            if (num == arr[i]) {
                return true;
            }
        }
        return false;
    }

    public static int[] createRandomArr() {
        Random rd = new Random();
        int[] arr = new int[7];
        for (int i = 0; i < arr.length;) {
            if (i < arr.length - 1) {
                int redNumber = rd.nextInt(33) + 1;
                if (!contains(arr, redNumber)) {
                    arr[i] = redNumber;
                    i++;
                }
            } else {
                arr[i] = rd.nextInt(16) + 1;
                i++;
            }
        }

        for (int i = 0; i < arr.length; i++) {
            if (i < arr.length - 1) {
                System.out.print(arr[i] + ", ");
            } else {
                System.out.println(arr[i]);
            }
        }

        return arr;
    }
 
    public static int[] createArr() {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[7];
        for (int i = 0; i < arr.length;) {
            if (i < arr.length - 1) {
                int current = i + 1;
                System.out.println("输入第" + current + "个红球数字");
                int redNumber = sc.nextInt();
                if (redNumber > 0 && redNumber < 34) {
                    if (!contains(arr, redNumber)) {
                        arr[i] = redNumber;
                        i++;
                    }
                } else {
                    System.out.println("请输入一个正确的红球数字");
                }
            } else {
                System.out.println("输入蓝球数字");
                int blueNumber = sc.nextInt();
                if (blueNumber > 0 && blueNumber < 17) {
                    arr[i] = blueNumber;
                    i++;
                } else {
                    System.out.println("请输入一个正确的蓝球数字");
                }
            }
        }
        sc.close();
        return arr;
    }

    public static int test3() {
        int[] randomArr = createRandomArr();
        int[] arr = createArr();

        int blue = 0;
        int red = 0;

        for (int i = 0; i < arr.length; i++) {
            if (i < arr.length - 1) {
                if (contains(randomArr, arr[i])) {
                    red++;
                }
            } else {
                if (randomArr[i] == arr[i]) {
                    blue++;
                }
            }
        }

        if (red == 6 && blue == 1) {
            return 10000000;
        } else if (red == 6 && blue == 0) {
            return 5000000;
        } else if (red == 5 && blue == 1) {
            return 3000;
        } else if ((red == 5 && blue == 0) || (red == 4 && blue == 1)) {
            return 200;
        } else if ((red == 4 && blue == 0) || (red == 3 && blue == 1) || (red == 2 && blue == 1)) {
            return 10;
        } else if ((red == 1 && blue == 1) || (red == 0 && blue == 1)) {
            return 5;
        } else {
            return 0;
        }
    }

    public static void test4() {
        int[][] arr = new int[][] {
            {1, 2, 3},
            {4, 5, 6}
        };
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                System.out.println(arr[i][j]);
            }
        }
    }

    public static void test5() {
        int[][] arr1 = {
            {1, 2, 3},
            {4, 5, 6, 7}
        };
        System.out.println(arr1[1][3]);

        int[][] arr2 = new int[2][3];
        int[] arr2_1 = {0, 1, 2};
        int[] arr2_2 = {3, 4, 5};
        arr2[0] = arr2_1;
        arr2[1] = arr2_2;
        
        int[][] arr3 = new int[2][];
        int[] arr3_1 = {1, 2};
        int[] arr3_2 = {1, 2, 3};
        arr3[0] = arr3_1;
        arr3[1] = arr3_2;

        int[][] arr = {
            {22, 66, 44},
            {77, 33, 88},
            {25, 45, 65},
            {11, 66, 99}
        };
        int sum = 0;
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                sum += arr[i][j];
            }
        }
        System.out.println(sum);
    }
}
