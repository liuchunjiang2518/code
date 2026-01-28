public class Java26_1_25 {
    public static void main(String[] args) {
        System.out.println("Hello World");
        test1();
    }

    public static void test1() {
        Person person = new Person("万春宏", 19);
        System.out.println(person.getName());
    }
}