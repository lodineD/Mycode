package package4.demo1;

import java.lang.Math;

// public static double abc(double num) 绝对值
// public static double ceil(double num) 向上取整
// public static double floor(double num) 向下取整
// public static long round(double num) 四舍五入

public class MathField {
    public static void main(String[] args) {
        double num = 2.3;
        System.out.println(Math.ceil(num));// 3.0
        System.out.println(Math.round(num));// 2 long int型
    }
}
