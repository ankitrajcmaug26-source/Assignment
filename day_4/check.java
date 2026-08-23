import java.util.*;
class check {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of array: ");
        int n=sc.nextInt();
        Integer[] arr=new Integer[n];
        System.out.println("Enter the "+n+" elements of array: ");
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        System.out.println("Enter the number to search: ");
        int key=sc.nextInt();
        if(Arrays.asList(arr).contains(key)){
            System.out.println("Found");
        }else{
            System.out.println("Not Found");
        }
    }
}
