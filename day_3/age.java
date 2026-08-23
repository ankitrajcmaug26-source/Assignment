import java.util.*;
class age{
    public static void checkAgeCategory(int age){
        if(age>60){
            System.out.println("You are an Senior Citizen");
        }else if(age<18){
            System.out.println("You are a Minor");
        }else{
            System.out.println("You are an Adult");
        }
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the age of the person: ");
        int age=sc.nextInt();
        checkAgeCategory(age);
    }
}