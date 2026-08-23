import java.util.*;
class count {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of array: ");
        int n=sc.nextInt();
        int[] arr=new int[n];
        System.out.println("Enter the "+n+" element of array: ");
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        int pos=0,neg=0;
        for(int num:arr){
            if(num>0) pos++;
            else if(num<0) neg++;
        }
        System.out.println("Positive number in the array: "+pos);
        System.out.println("Negative number in the array: "+neg);
    }
}
