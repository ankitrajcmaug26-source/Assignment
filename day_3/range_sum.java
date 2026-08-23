import java.util.*;

class range_sum {
    public static int sum(int n){
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=i;
        }
        return sum;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the range to sum: ");
        int n=sc.nextInt();
        int val=sum(n);
        System.out.println("The sum of Numbers from 1 to "+n+" is: "+val);
    }    
}
