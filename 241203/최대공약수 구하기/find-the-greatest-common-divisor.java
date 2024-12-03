import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        common(n, m);
    }

    static void common(int a, int b) {
        int num = 0;
        for(int i=1; i<=Math.max(a,b); i++) {
            if (a%i == 0 && b%i == 0) num = i;
        }
        System.out.println(num);
    }
}