package package4.demo1;

import java.util.Arrays;
import java.lang.Math;

public class ArraysField {
    public static void main(String[] args) {
        String line = "asdfqweroiuopuafa;sjdf";
        char[] chars = line.toCharArray();
        Arrays.sort(chars);
        for (int i = chars.length - 1; i >= 0; i--) {
            System.out.print(chars[i]);
        }
    }
}
