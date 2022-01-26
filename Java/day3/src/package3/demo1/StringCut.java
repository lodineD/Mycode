package package3.demo1;

// public String subString(int index); 截取从参数部分到末尾
// public String subString(int begin, int end); 截取
//[begin, end）;
public class StringCut {
    public static void main(String[] args) {
        String str1 = "helloworld";
        String str2 = str1.substring(5);
        String str3 = str1.substring(4, 7);
        System.out.println(str2);
        System.out.println(str3);
    }
}
