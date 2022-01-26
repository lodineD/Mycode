package package3.demo1;

// public char[] toCharArray();
// public byte[] getBytes();
// public   String replace (CharSequence oldString,CharSequence newString);
public class StringsSwitch {
    public static void main(String[] args) {
        char[] chars = "Hello".toCharArray();
        System.out.println(chars.length);
        System.out.println(chars[0]);
        System.out.println("==========");

        byte[] bytes = "abc".getBytes();
        System.out.println(bytes.length);
        System.out.println(bytes[0]);
        System.out.println("==========");

        String str1 = "你他妈的sb";
        str1 = str1.replace("他妈的sb", "小可爱的**");
        System.out.println(str1);
    }
}
