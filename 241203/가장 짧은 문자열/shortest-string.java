import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int s1 = sc.next().length();
        int s2 = sc.next().length();
        int s3 = sc.next().length();
        if (s1 < s2) {
            if (s2 < s3) System.out.println(s3-s1);
            else if (s1 < s3) System.out.println(s2-s1);
            else System.out.println(s2-s3);
        }
        else {
            if (s1 < s3) System.out.println(s3-s2);
            else if (s2 < s3) System.out.println(s1-s2);
            else System.out.println(s1-s3);
        }
    }
}