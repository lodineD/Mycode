package demo1;

public class QunYuan extends User{
    int Id;
    double sum;
    static int numId = 1;
    public QunYuan(){
        Id = ++numId;
        sum = 0.0;
    }
    public void remainSum(int num){
        sum = sum + num;
    };

    public int getId() {
        return Id;
    }

    public double getSum() {
        return sum;
    }
}
