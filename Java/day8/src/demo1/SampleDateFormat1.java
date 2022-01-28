package demo1;

// https://www.bilibili.com/video/BV18J411W7cE?p=208

import java.text.SimpleDateFormat;
import java.util.Date;

public class SampleDateFormat1 {
    public static void main(String[] args) {
        SimpleDateFormat sdf = new SimpleDateFormat();
        Date d = new Date();
        String s = sdf.format(d);
        System.out.println(s);// 格式化输出 默认模式
        System.out.println("==========");

        SimpleDateFormat sdf2 = new SimpleDateFormat("yyyy年MM月dd日 HH:mm:ss");
        Date d2 = new Date();
        String s1 = sdf2.format(d2);
        System.out.println(s1);// 格式化输出,加参
    }
}
