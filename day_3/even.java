import java.util.*;
class even {
    public static void printeven(int n){
        int i=1;
        while(i<=n){
            if(i%2==0){
                System.out.print(i+" ");
            }
        }
        System.out.println();
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the range to print even number: ");
        int n=sc.nextInt();
        printeven(n);
    }
}
