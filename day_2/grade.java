import java.util.*;
class grade{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the marks in Math: ");
        int ma=sc.nextInt();
        System.out.println("Enter the marks in Science");
        int Science=sc.nextInt();
        System.out.println("Enter the marks in History");
        int his=sc.nextInt();
        int avg=(ma+Science+his)/3;
        System.out.println("Average marks: "+avg);
        if(avg>=90){
            System.out.println("Grade: A");
        }else if(avg>=70 && avg<90){
            System.out.println("Grade: B");
        }else if(avg>=50 && avg<70){
            System.out.println("Grade: C");
        }else if(avg>=30 && avg<50){
            System.out.println("Grade: D");
        }else if(avg>=0 && avg<30){
            System.out.println("Fail");
        }else {
            System.out.println("Invalid Marks Entered");
        }
    }
}