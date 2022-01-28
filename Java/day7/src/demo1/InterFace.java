package demo1;

// public , abstract 是其中的固定关键词，没有其他关键词
// 两个关键词可以省略
// 需要类来实现，和抽象类相像
// public class InterFaceImpl implements InerFace{}
public interface InterFace {
    public abstract void method1();

    public void method2();

    abstract void method3();

    void method4();
}
