package package1.demo1;

import java.util.Random;
import java.util.ArrayList;


public class Arraylist1 {
    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < 6; i++) {
            Random r = new Random(32);
            int num = r.nextInt() + 1;
            list.add(num);
        }
        System.out.print(list);
    }


}
