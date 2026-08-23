import java.util.*;
class sort {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of array: ");
        int n=sc.nextInt();
        System.out.println("Enter the "+n+" elements of array: ");
        int[] arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        Arrays.sort(arr);
        System.out.print("Sorted Array: ");
        for(int num:arr){
            System.out.print(num+" ");
        }
        System.out.println();
    }
}
