package demo1;

public class QunZhu extends User {
    int Id = 1;
    double sum = 100.0;

    public double getSum() {
        return sum;
    }

    public int getId() {
        return Id;
    }

    public void remainSum(int num) {
        sum = sum - num;
    }
}
