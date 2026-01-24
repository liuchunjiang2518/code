public class Java26_1_24 {
    private String name = "万春宏";
    public static void main() {
        // test1();
        test2();
    }

    public void printHelloWorld() {
        System.out.println("Hello World");
    }

    public static void test1() {
        Java26_1_24 p = new Java26_1_24();
        p.printHelloWorld();
        System.out.println(p.name);

        Java26_1_24Friend f1 = new Java26_1_24Friend();
        f1.sleep();
        f1.name = "万春宏";
        System.out.println(f1.name);
    }

    public static void test2() {
        String a = "hhhh";
        String b = a.toUpperCase();
        System.out.println(b);

    }
}