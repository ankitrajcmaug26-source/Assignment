import java.util.*;
class largest {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of array: ");
        int n=sc.nextInt();
        int[] arr=new int[n];
        System.out.println("Enter the "+n+" elements of array: ");
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        int max=Integer.MIN_VALUE;
        for(int num:arr){
            if(num>max){
                max=num;
            }
        }
        System.out.println("The largest element is: "+max);
    }
}
