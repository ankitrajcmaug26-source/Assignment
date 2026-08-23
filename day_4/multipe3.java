import java.util.*;
class multipe3 {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the range: ");
        int n=sc.nextInt();
        for(int i=1;i<=n;i++){
            System.out.print(i*3+" ");
        }
        System.out.println();
    }
}
