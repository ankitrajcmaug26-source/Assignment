import java.util.*;
class printname {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number of name: ");
        int n=sc.nextInt();
        String[] names=new String[n];
        System.out.println("Enter the "+n+" names: ");
        for(int i=0;i<n;i++){
            names[i]=sc.next();
        }
        System.out.println("Names in the array: ");
        for(String name:names){
            System.out.println(name);
        }
    }
}
