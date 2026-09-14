class consoleInput {
    public static float getFloat(String [] args){
        String objString=getString();
        float data=Float.parseFloat(objString);
        return data;
    }
    public static int getInt(){
        return Integer.parseInt(getString());
    }
    public static String getString(){
        try{
            byte arrInput[]=new byte[100];
            int length=System.in.read(arrInput);
            byte[] arrFinal=new byte[length-2];
            System.arraycopy(arrInput,0, arrFinal,0, length-2);
            String objString=new String(arrFinal);
            return objString;
        }catch(Exception e){
            e.printStackTrace();
        }
        return null;
    }
}



class Date{
    private int day;
    private int month;
    private int year;
    private int[] noOfDays={0,31,28,31,30,31,30,31,31,30,31,30,31};

    public void setDate(int dd,int mm,int yy){
        if(yy<1950 || yy>3000) year=2026;
        else year=yy;
        if(mm<1 || mm>12) month=1;
        else month=mm;
        if(dd<1 || dd>daysinmonth(month)) day=1;
        else day=dd;
    }

    public boolean isleap(int yy){
        return  (yy%400==0) || (yy %4==0 && yy%100 !=0);
    }

    public void addDays(int daysToAdd){
        int tday=day+daysToAdd;
        while(tday > daysinmonth(month)){
            tday -=noOfDays[month];
            month++;
            if(month >12) {
                month=1;
                year++;
            }
        }
        day=tday;
    }

    public int daysinmonth(int mm){
        if(mm==2){
            if(isleap(year)){
                return 29;
            }else return 28;
        }
        return noOfDays[mm];
    }

    public void addmonth(int monthToAdd) {

        int totalMonths = (year * 12) + (month - 1);

        totalMonths += monthToAdd;

        year = totalMonths / 12;

        month = totalMonths % 12 + 1;

        if(day > daysinmonth(month)) {
            day = daysinmonth(month);
        }
    }
    
    public void addyear(int yearToAdd){
        year+=yearToAdd;
        if(day>daysinmonth(month)){
            day=daysinmonth(month);
        }
        
    }

    public int getDay(){
        return day;
    }

    public int getMonth(){
        return month;
    }

    public int getYear(){
        return year;
    }
    public void Display(){
        System.out.println(getDay()+" / "+ getMonth()+" / "+getYear());
    }
}

public class assignment {
    public static void main(String[] args){
        Date d=new Date();
        consoleInput input=new consoleInput();
        boolean flag=true;
        while(flag){
            System.out.println("Choose the choice: ");
            System.out.println("1. Set Day");
            System.out.println("2. Add Days");
            System.out.println("3. Add Months");
            System.out.println("4. Add year");
            System.out.println("5. Displays");
            System.out.println("6. Compare Dates");
            System.out.println("7. Exit");
            int choice=input.getInt();
            switch(choice){
                case 1:
                        System.out.println("Enter the date in (dd/mm/yyyy) way:");
                        int dd=input.getInt();
                        int mm=input.getInt();
                        int yy=input.getInt();
                        d.setDate(dd, mm, yy);
                        break;
                case 2:
                        System.out.println("Enter the number of days to add: ");
                        int days=input.getInt();
                        d.addDays(days);
                        break;
                case 3:
                        System.out.println("Enter the number of months to add: ");
                        int month=input.getInt();
                        d.addmonth(month);
                        break;
                case 4:
                        System.out.println("Enter the number of year to add: ");
                        int year=input.getInt();
                        d.addyear(year);
                        break;
                case 5:
                        d.Display();
                        break;
                case 6:
                        break;
                case 7:
                        flag=false;
                        break;
                default:
                     System.out.println("Chose the valid option");
            }
        }
    }
}
