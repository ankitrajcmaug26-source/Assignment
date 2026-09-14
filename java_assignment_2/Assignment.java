

class consoleInput {
    public static float getFloat(){
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

abstract class Employee{
    protected String name;
    protected String address;
    protected int age;
    protected String gender;
    protected float basicSalary;

    public Employee(String name,String address,int age,String gender,float basicSalary){
        this.name=name;
        this.address=address;
        this.age=age;
        this.gender=gender;
        this.basicSalary=basicSalary;
    }
    public String getName(){ 
        return name;
    }
    public void setName(String name){
        this.name=name;
    }
    public String getAddress(){
        return address;
    }
    public void setAddress(String address){
        this.address=address;
    }
    public int getAge(){
        return age;
    }
    public void setAge(int age){
        if(age<18 || age>65) this.age=21;
        else this.age=age;
    }
    public String getGender(){
        return gender;
    }
    public void setGender(String gender){
        this.gender=gender;
    }
    public float getBasicSalary(){
        return basicSalary;
    }
    public void setBasicSalary(float basicSalary){
        this.basicSalary=basicSalary;
    }
    public abstract void display();

}
class Manager extends Employee{
    protected float hra;
    public Manager(String name,String address,int age,String gender,float basicSalary,float hra){
        super(name, address, age, gender, basicSalary);
        this.hra=hra;
    }
    public float getHra(){
        return hra;
    }
    public void getHra(float hra){
        this.hra=hra;
    }

    public void display(){
        System.out.println("Desgination : Manager ");
        System.out.println("Name : "+name);
        System.out.println("Address : "+address);
        System.out.println("Age: "+age);
        System.out.println("Gender : "+gender);
        System.out.println("Basic Salary: "+basicSalary);
        System.out.println("Hra :"+hra);
    }
}

class Engineer extends Employee{
    protected float overtime;
    public Engineer(String name,String address,int age,String gender,float basicSalary,float overtime){
        super(name,address,age,gender,basicSalary);
        this.overtime=overtime;
    }
    public float getOvertime(){
        return overtime;
    }
    public void setOvertime(float overtime){
        this.overtime=overtime;
    }
    public void display(){
        System.out.println("Desgination : Engineer ");
        System.out.println("Name : "+name);
        System.out.println("Address : "+address);
        System.out.println("Age: "+age);
        System.out.println("Gender : "+gender);
        System.out.println("Basic Salary: "+basicSalary);
        System.out.println("Overtime :"+overtime);
    }
}

class Sales extends Employee{
    protected float bonus;
    public Sales(String name,String address,int age,String gender,float basicSalary,float bonus){
        super(name, address, age, gender, basicSalary);
        this.bonus=bonus;
    }
    public float getBonus(){
        return bonus;
    }
    public void setBonus(float bonus){
        this.bonus=bonus;
    }

    public void display(){
        System.out.println("Desgination : Sales ");
        System.out.println("Name : "+name);
        System.out.println("Address : "+address);
        System.out.println("Age: "+age);
        System.out.println("Gender : "+gender);
        System.out.println("Basic Salary: "+basicSalary);
        System.out.println("Bonus :"+bonus);
    }
}



class Assignment{
    static Employee[] employees=new Employee[100];
    static consoleInput input=new consoleInput();
    static int count=0;

    public static void add(){
        boolean flag=true;
        while(flag){
            System.out.println();
            System.out.println("Chosse to add according to profession: ");
            System.out.println("1 Manager");
            System.out.println("2 Engineer ");
            System.out.println("3 salesPerson");
            System.out.println("4 return main menu");
            int choice=input.getInt();
            switch(choice){
                case 1:
                    addManager();
                    break;
                case 2:
                    addEngineer();
                    break;
                case 3:
                    addSales();
                    break;
                case 4:
                    flag=false;
                    break;
                default:
                    System.out.println("Choose the correct option");
                    break;
            }
        }
    }


    public static void addManager(){
        if(count>employees.length){
            System.out.println("Employee array is full.");
            return;
        }
        System.out.println();
        System.out.println("Enter Manager Name:");
        String name=input.getString();
        System.out.println("Enter Manager Address: ");
        String address=input.getString();
        System.out.println("Enter age:");
        int age=input.getInt();
        System.out.println("Enetr gender(true(men) / false(female))");
        String gender=input.getString();
        System.out.println("Enter Basic Salary: ");
        float salary=input.getFloat();
        System.out.println("Enter hra: ");
        float hra=input.getFloat();

        Employee manager=new Manager(name, address, age, gender, salary, hra);
        employees[count++]=manager;
        System.out.println("Manager addes successfully.");
        System.out.println();

    }



    public static void addEngineer(){
        if(count>employees.length){
            System.out.println("Employee array is full.");
            return;
        }
        System.out.println();
        System.out.println("Enter Engineer Name:");
        String name=input.getString();
        System.out.println("Enter Engineer Address: ");
        String address=input.getString();
        System.out.println("Enter age:");
        int age=input.getInt();
        System.out.println("Enetr gender(true(men) / false(female))");
        String gender=input.getString();
        System.out.println("Enter Basic Salary: ");
        float salary=input.getFloat();
        System.out.println("Enter overtime: ");
        float hra=input.getFloat();

        Employee engineer=new Engineer(name, address, age, gender, salary, hra);
        employees[count++]=engineer;
        System.out.println("Engineer addes successfully.");
        System.out.println();
    }


    public static void addSales(){
        if(count>employees.length){
            System.out.println("Employee array is full.");
            return;
        }
        System.out.println();
        System.out.println("Enter Sales Person Name:");
        String name=input.getString();
        System.out.println("Enter Sales Person Address: ");
        String address=input.getString();
        System.out.println("Enter age:");
        int age=input.getInt();
        System.out.println("Enetr gender(true(men) / false(female))");
        String gender=input.getString();
        System.out.println("Enter Basic Salary: ");
        float salary=input.getFloat();
        System.out.println("Enter Bonus: ");
        float hra=input.getFloat();

        Employee salesperson=new Sales(name, address, age, gender, salary, hra);
        employees[count++]=salesperson;
        System.out.println("Sales Person addes successfully.");
        System.out.println();

    }

    public static void display(){
        if(count==0){
            System.out.println("No Employee is available");
            return;
        }
        for(int tmp=0;tmp<count;tmp++){
            System.out.println();
            System.out.println("Employee: "+(tmp+1));

            employees[tmp].display();
        }
    }

    public static void sort(){
        if(count==0) {
            System.out.println("No Employee is available to sort. ");
            return;
        }
        boolean flag=true;
        while(flag){
            System.out.println();
            System.out.println(" Chosee the option ");
            System.out.println("1. Sort by Name Ascending.");
            System.out.println("2. Sort by Name Descending.");
            System.out.println("3. sort by Designation.");
            System.out.println("4. Exit");
            int choice=input.getInt();
            switch(choice){
                case 1:
                        sortAscending();
                        break;
                case 2:
                        sortDescending();
                        break;
                case 3:
                        System.out.println("In not implemented. ");
                        break;
                case 4:
                        flag=false;
                        break;
                default:
                        System.out.println("Choose the correct option.");
            }

        }
    }


    public static void sortAscending(){
        for(int outer=0;outer<count-1;outer++){
            for(int inner=0;inner<count-1-outer;inner++){
                if(employees[inner].getName().compareTo(employees[inner+1].getName())>0){
                    Employee temp=employees[inner];
                    employees[inner]=employees[inner+1];
                    employees[inner+1]=temp;
                }
            }
        }
        display();
    }

    public static void sortDescending(){
        for(int outer=0;outer<count-1;outer++){
            for(int inner=0;inner<count-outer-1;inner++){
                if(employees[inner].getName().compareTo(employees[inner+1].getName())<0){
                    Employee temp=employees[inner];
                    employees[inner]=employees[inner+1];
                    employees[inner+1]=temp;
                }
            }
        }
        display();
    }

    public static void delete(){

    }
    public static void load(){

    }
    public static void save(){

    }
    public static void main(String[] args){
        consoleInput input=new consoleInput();
        boolean flag=true;
        while(flag){
            System.out.println();
            System.out.println("Chose the option: ");
            System.out.println("==== Menu Driven ====");
            System.out.println("1. Add Employee ");
            System.out.println("2. Display ");
            System.out.println("3. Delete ");
            System.out.println("4. Sort ");
            System.out.println("5. Save ");
            System.out.println("6. Load ");
            System.out.println("7. Exit ");

            int choice=input.getInt();
            switch(choice){
                case 1: 
                        add();
                        break;
                case 2:
                        display();
                        break;
                case 3:
                        delete();
                        break;
                case 4:
                        sort();
                        break;
                case 5:
                       save();
                       break;
                case 6:
                        load();
                        break;
                case 7:
                        flag=false;
                        break;
                default:
                       System.out.println("Chose the correct option ");

            }
        }
    }
}