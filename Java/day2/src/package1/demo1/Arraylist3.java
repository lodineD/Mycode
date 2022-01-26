package package1.demo1;

import java.util.ArrayList;

public class Arraylist3 {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();
        list.add("张三丰");
        list.add("宋远桥");
        list.add("张无忌");
        list.add("殷梨亭");
        printList(list);
    }

    public static void printList(ArrayList<String> list) {
        System.out.print("{");
        for (int i = 0; i < 4; i++) {
            System.out.print(list.get(i) + "@");
            if (i == 3) {
                System.out.print(list.get(i) + "}");
            }
        }
    }


}
