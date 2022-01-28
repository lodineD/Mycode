package demo1;

//  try{
//      可能出现的错误代码
//   }
//  catch(异常类名 异常变量名){
//       异常的处理代码
//}    可以使下面程序继续执行
public class TryCatch {
    public static void main(String[] args) {
        System.out.println("开始");
        method();
        System.out.println("结束");
    }

    public static void method() {
//        int []arr = {1,2,3};
//        System.out.println(arr[3]);// Exception in thread "main" java.lang.ArrayIndexOutOfBoundsException: Index 3 out of bounds for length 3
////        at demo1.TryCatch.method(TryCatch.java:16)
////        at demo1.TryCatch.main(TryCatch.java:11)
        try {
            int[] arr = {1, 2, 3};
            System.out.println(arr[3]);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("你访问的数组不存在！");
//            e.printStackTrace();
            System.out.println(e.getMessage());
        }
    }
}
