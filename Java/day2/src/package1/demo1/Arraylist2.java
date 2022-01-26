package package1.demo1;

import package1.demo2.Student;
import java.util.ArrayList;

public class Arraylist2 {
    public static void main(String[] args) {
        ArrayList<Student> list = new ArrayList<>();
        Student st1 = new Student(18, "赵丽颖");
        Student st2 = new Student(20, "唐嫣");
        Student st3 = new Student(25, "景甜");
        Student st4 = new Student(19, "柳岩");

        list.add(st1);
        list.add(st2);
        list.add(st3);
        list.add(st4);

        for (int i = 0; i < 4; i++) {
            Student st = list.get(i);
            st.showStudent();
        }
    }
}
