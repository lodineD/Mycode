package package1.demo1;

import java.util.Random;
import java.util.ArrayList;

public class Arraylist4 {
    public static void main(String[] args) {
        Random r = new Random();
        ArrayList<Integer> list1 = new ArrayList<>();
        ArrayList<Integer> list2 = new ArrayList<>();
        for (int i = 0; i < 20; i++) {
            int num = r.nextInt(31) + 1;
            list1.add(num);
            if (num % 2 == 0) {
                list2.add(num);
            }
        }
        System.out.println(list1);
        System.out.println(list2);
    }


}
