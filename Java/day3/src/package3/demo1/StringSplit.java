package package3.demo1;

// public String[] split(String regex);
public class StringSplit {
    public static void main(String[] args) {
        String str1 = "aaa,bbb,ccc";
        String str2 = "aaa.bbb.ccc";
        String[] array = str1.split(",");
        String[] array2 = str2.split("\\."); // 正则表达式.要写\\.
        for (int i = 0; i < array.length; i++) {
            System.out.println(array[i]);
        }
        for (int i = 0; i < array2.length; i++) {
            System.out.println(array2[i]);
        }
    }
}
