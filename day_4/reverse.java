import java.util.*;
class reverse {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the string: ");
        String s=sc.next();
        String rev="";
        for(int i=s.length()-1;i>=0;i++){
            rev+=s.charAt(i);
        }
        System.out.println("Reversed String: "+rev);
    }
}
