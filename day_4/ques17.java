class ques17 {
    public static void main(String[] args){
        for(int i=1;i<=5;i++){
            for(int j=1;j<=i;j++){
                int num=2*j-1;
                System.out.print(num);
                if(j<i){
                    System.out.print("*");
                }
            }
            System.out.println();
        }
    }    
}
