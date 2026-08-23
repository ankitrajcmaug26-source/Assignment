import java.util.*;
class factorial {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number to calculate the factorial: ");
        int n=sc.nextInt();
        long f=1;
        for(int i=n;i>0;i--){
            f*=i;
        }
        System.out.println("Factorial of "+n+" is: "+f);
    }
}
