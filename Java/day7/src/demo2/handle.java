package demo2;

import demo1.InterFaceImpl;

// 不能直接new接口对象， 创建实现类的对象
// 如果没有重写所有的抽象方法，则该类必须是抽象类

public class handle {
    public static void main(String[] args) {
        InterFaceImpl impl = new InterFaceImpl();
        impl.method1();
        impl.method3();
    }
}
