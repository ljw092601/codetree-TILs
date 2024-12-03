import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        IntWrapper a = new IntWrapper(sc.nextInt());
        IntWrapper b = new IntWrapper(sc.nextInt());
        cal(a, b);
        System.out.println(a.value() + " " + b.value());
    }

    public static void cal(IntWrapper a, IntWrapper b) {
        if (a.value() < b.value()) {
            a.a *= 2;
            b.a += 25;
        }
        else {
            b.a *= 2;
            a.a += 25;
        }
    }
}

class IntWrapper {
    int a;

    IntWrapper(int a) {
        this.a = a;
    }

    public int value() {
        return this.a;
    }
}