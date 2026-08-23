import java.util.*;
class average {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of array: ");
        int n=sc.nextInt();
        int[] arr=new int[n];
        System.out.println("Enter the "+n+" elements of array: ");
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        double sum=0;
        for(int num:arr){
            sum+=num;
        }
        System.out.println("Average of array: "+sum/n);
    }
}
