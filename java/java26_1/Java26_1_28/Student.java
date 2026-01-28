import java.util.Scanner;

public class Student {
    private String id;
    private String name;
    private int age;

    public Student() {}
    public Student(String id, String name, int age) {
        this.id = id;
        this.name = name;
        this.age = age;
    }

    public String getId() {
        return id;
    }
    public void setId(String id) {
        this.id = id;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public int getAge() {
        return age;
    }
    public void setAge(int age) {
        this.age = age;
    }
    
    @Override
    public String toString() {
        return "Student [id=" + id + ", name=" + name + ", age=" + age + "]";
    }

    public static void printStudents(Student[] students) {
        for (int i = 0; i < students.length; i++) {
            if (students[i] == null) {
                continue;
            } else {
                System.out.println(students[i]);
            }
        }
    }

    public static int findFirstNullIndex(Student[] students) {
        if (students == null) {
            return -1;
        }
        for (int i = 0; i < students.length; i++) {
            if (students[i] == null) {
                return i;
            }
        }
        return students.length;
    }

    public static boolean isStudentsFull(Student[] students) {
        return findFirstNullIndex(students) == students.length; 
    }

    public static boolean isIdExist(Student[] students, String id) {
        for (int i = 0; i < students.length; i++) {
            if (students[i] == null) {
                break;
            }
            if (students[i].getId().equals(id)) {
                return true;
            }
        }
        return false;
    }

    public static Student[] insertStudent(Student[] students, Scanner sc) {
        String id;
        while (true) {
            id = sc.nextLine();
            if (!isIdExist(students, id)) {
                break;
            }
        }
        String name = sc.nextLine();
        int age = sc.nextInt();
        sc.nextLine();
        
        Student student = new Student(id, name, age);
        if (isStudentsFull(students)) {
            Student[] newSpace = new Student[students.length + 1];
            for (int i = 0; i < students.length;i++) {
                newSpace[i] = students[i];
            }
            newSpace[students.length] = student;
            return newSpace; 
        } else {
            students[findFirstNullIndex(students)] = student;
            return students;
        }
    }

    public static void deleteStudent(Student[] students, String id) {
        int idx = -1;
        for (int i = 0; i < students.length; i++) {
            if (students[i] != null && students[i].getId().equals(id)) {
                idx = i;
            }
        }

        if (idx != -1) {
            for (int i = idx; i < students.length - 1; i++) {
                students[i] = students[i + 1];
            }
            students[students.length - 1] = null;           
        }
    }

    public static void updateStudent(Student[] students, String id, Scanner sc) {
        int idx = -1;
        for (int i = 0; i < students.length; i++) {
            if (students[i] != null && students[i].getId().equals(id)) {
                idx = i;
            }
        }

        if (idx != -1) {
            String name = sc.nextLine();
            int age = sc.nextInt();
            sc.nextLine();

            students[idx].setAge(age);
            students[idx].setId(id);
            students[idx].setName(name);
        }
    }
}
