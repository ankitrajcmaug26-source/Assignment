import java.util.Scanner;

public class positive {

    public static int askForPositiveNumber(Scanner sc) {
        int num;

        do {
            System.out.print("Enter a positive number: ");
            num = sc.nextInt();
        } while (num <= 0);

        return num;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int num = askForPositiveNumber(sc);

        System.out.println("You entered a positive number: " + num);
    }
}