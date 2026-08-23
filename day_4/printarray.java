import java.util.*;
class printarray {
    public static void main(String[] arge){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of array: ");
        int n=sc.nextInt();
        int[] arr=new int[n];
        System.out.println("Enter the element of array: ");
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        System.out.println("Element of array: ");
        for(int num:arr){
            System.out.print(num+" ");
        }
        System.out.println();
    }    
}
