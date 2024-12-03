import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] sarray = new String[10];
        for(int i=0; i<10; i++) {
            sarray[i] = sc.next();
        }
        for(int i=0; i<10; i+=2) {
            System.out.println(sarray[i]);
        }
    }
}