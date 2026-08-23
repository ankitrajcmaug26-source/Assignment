import java.util.*;
class binary {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of array: ");
        int n=sc.nextInt();
        int[] arr=new int[n];
        System.out.println("Enter the "+n+" element of array: ");
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        Arrays.sort(arr);
        System.out.println("Enter the number to search: ");
        int key=sc.nextInt();
        int idx=Arrays.binarySearch(arr, key);
        if(idx>=0){
            System.out.println("The number "+key+" found at index: "+idx);
        }else{
            System.out.println("Not Found");
        }
    }
}
