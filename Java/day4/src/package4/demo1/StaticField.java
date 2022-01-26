package package4.demo1;

import demo2.Student;

public class StaticField {
    public static void main(String[] args) {
        Student student1 = new Student("郭靖", 19);
        Student student2 = new Student("黄蓉", 16);
        student1.room = "101教室";
        System.out.println(student1.getName() + " " + student1.getAge() + " " + student2.room + " " + student1.getId());
        System.out.println(student2.getName() + " " + student2.getAge() + " " + student2.room + " " + student2.getId());
        Student.methodStatic();// 推荐，静态方法可以直接无对象使用
        student1.methodStatic();// 不推荐
        student2.method();
    }
// 实现Id的自加; static 的应用
}
