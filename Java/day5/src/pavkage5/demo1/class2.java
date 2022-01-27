package pavkage5.demo1;

import java.awt.*;

// 这是子类，与C++不同，可以直接给变量赋值
// this可以直接调用本类的方法
public class class2 extends class1{
    int num = 20;
    int numZi;
    public class2(){
        super();// 要么不写，写了只能有一个
    }
    @Override
    public void method(){// 重写：先用子类的
        int num = 10;
        super.method();// 使用父类的
        System.out.println(super.num); // 父类的成员变量
        System.out.println(this.num); // 本类的成员变量
        System.out.println(num); // 局部变量
    }
    public void methodZi(){
        this.method();
        System.out.println("本类this方法使用成功");
    }
}
