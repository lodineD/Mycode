package package4.demo2;

public class Student {
    private int id;
    private String name;
    private int age;
    static public String room;
    private static int idCounter = 0;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Student() {
        idCounter++;
    }

    public Student(String name, int age) {
        this.name = name;
        this.age = age;
        this.id = ++idCounter;
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

    public void method() {
        System.out.println("这是一个普通方法");
    }

    public static void methodStatic() {
        System.out.println("这是一个静态方法");
    }
}
