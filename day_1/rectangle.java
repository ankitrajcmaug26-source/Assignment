import java.util.*;
class rectangle {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the length of rectangel:");
        int len=sc.nextInt();
        System.out.println("Enter the width of rectangle:");
        int wid=sc.nextInt();
        System.out.println("Area of rectangle with length"+len+" and width "+wid+" are: "+len*wid);
    }
}
