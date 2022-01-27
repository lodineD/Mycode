package demo2;

import demo1.QunYuan;
import demo1.QunZhu;
import java.util.Random;
//import java.util.Scanner;

public class HandleHongBao {
    public static void main(String[] args) {
        QunZhu qunZhu = new QunZhu();
        QunYuan qunYuan1 = new QunYuan();
        QunYuan qunYuan2 = new QunYuan();
        QunYuan qunYuan3 = new QunYuan();
        Random r = new Random();
//        Scanner s = new Scanner(System.in);
        int num = r.nextInt(100);
//        System.out.println("请输入群员数");
//        int numYuan = s.nextInt();
        num = num/3;
        qunZhu.remainSum(num);
        qunYuan1.remainSum(num);
        qunYuan2.remainSum(num);
        qunYuan3.remainSum(num);
        System.out.println(qunZhu.getId()+" "+qunZhu.getSum());
        System.out.println(qunYuan1.getId()+" "+qunYuan1.getSum());
        System.out.println(qunYuan2.getId()+" "+qunYuan2.getSum());
        System.out.println(qunYuan3.getId()+" "+qunYuan3.getSum());
    }
}
