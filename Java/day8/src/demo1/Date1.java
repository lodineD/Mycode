package demo1;

import java.util.Date;

public class Date1 {
    public static void main(String[] args) {
        Date d1 = new Date();
        System.out.println(d1);
        long date = 1000 * 60 * 60;// 这是ms，表示一小时
        Date d2 = new Date(date);// 表示超前一小时
        System.out.println(d2);// 标准是1970.1.1 00:00:00 中国标准CST再延长8小时
        System.out.println("===========");
        // getTime方法
        System.out.println(d1.getTime()); // 现在时间与标准的毫米差值
        System.out.println(d1.getTime() * 1.0 / 1000 / 60 / 60 / 24 / 356 + "年");
        System.out.println("===========");
        // setTime方法
        long time = System.currentTimeMillis();// 获取当前时间ms
        System.out.println(time);
        d1.setTime(time);// 设置为当前时间
        System.out.println(d1);
    }
}
