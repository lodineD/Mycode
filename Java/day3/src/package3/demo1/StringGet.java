package package3.demo1;
// String.equals()方法具有对称性
//   “abc”.equals()推荐 常量在前
//   str.equals("abc") 不推荐
public class StringGet {
    public static void main(String[] args) {
        String str1 = new String();
        String str2 = "abc";
  /*      str1 = null;
        String str2 = "abc";
        System.out.println("abc".equals(str1)); // false
        System.out.println(str1.equals("abc")); // 报错*/
        String str3 = "qwer";
        String str4 = str3.concat(str2);
        System.out.println(str4);
        System.out.println(str4.length());
        System.out.println(str4.indexOf("rab"));// 查找首次出现的位置，没有则为-1；


    }
}
