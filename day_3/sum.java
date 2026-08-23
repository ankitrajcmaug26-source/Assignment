import java.util.*;
class sum{
    public static int sumOfTwoNumbers(int x,int y){
        return x+y;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the first number");
        int num1=sc.nextInt();
        System.out.println("Enter the second number");
        int num2=sc.nextInt();
        int val=sumOfTwoNumbers(num1,num2);
        System.out.println("Sum of two number "+num1+" and "+num2+" is : "+val);
    }
}