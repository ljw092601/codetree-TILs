import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        for(char c : s.toCharArray()) {
            if (c != ' ') System.out.print(c);
        }
        String s = sc.nextLine();
        for(char c : s.toCharArray()) {
            if (c != ' ') System.out.print(c);
        }
    }
}