import java.util.*;
class table {
    public static void printMultiplicationTable(int n){
        for(int i=1;i<=10;i++){
            System.out.println(n+" x "+i+" = "+ n*i);
        }
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number to print the table: ");
        int n=sc.nextInt();
        printMultiplicationTable(n);
    }
}
