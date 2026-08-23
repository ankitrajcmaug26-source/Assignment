import java.util.*;
class palindrome {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the string: ");
        String s=sc.next();
        int si=0,ei=s.length()-1;
        while(si<ei){
            if(s.charAt(si)!=s.charAt(ei)){
                System.out.println("String "+s+" is not a palindrome.");
                break;
            }
            si++;
            ei--;
        }
        if(si==ei){
            System.out.println("String "+s+" is a palindrome.");
        }
    }
}
