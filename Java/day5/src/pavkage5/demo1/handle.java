package pavkage5.demo1;
// 直接访问：如果父子类重名则，等号左边的是谁的就用谁的，没有就向上找
// 间接访问：间接访问的方法在哪，就是谁的.否则就向上找
// 注意如果没有方法或变量一定是向上找
public class handle {
    public static void main(String[] args) {
        class2 Class2 = new class2();// "super()",先父类构造，后子类
        Class2.method();
        Class2.methodZi();// 可以直接用本类的方法

    }
}
