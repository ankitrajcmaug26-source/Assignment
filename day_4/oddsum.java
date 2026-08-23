import java.util.*;
class oddsum {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter a number: ");
        int n=sc.nextInt();
        int sum=0;
        for(int i=1;i<=n;i++){
            if(i%2==1){
                sum+=i;
            }
        }
        System.out.println("The Sum of odd numbers from 1 to "+n+" is: "+sum);
    }
}
