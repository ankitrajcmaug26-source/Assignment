#include<iostream>
#include<string>
using namespace std;

class Patient{
    private:
        int patientId;
        string name;
        int age;
        string ward;
        const string bloodGroup;
    public:
        //default constructor
        Patient(): patientId(0),name("Unknown"),age(0),ward("General"),bloodGroup("O+"){
            cout<<"Default constructor..."<<endl;
        }
        //Emergency
        Patient(int id, const string& name): patientId(id),name(name),age(0),ward("Emergency"),bloodGroup("0+") {
            cout << "Emergency: "<< name << endl;
        }
        // Constructor 3: Full admission
        Patient(int id, const string& name, int age,const string& ward, const string& bg)
        : patientId(id),name(name),age(age),ward(ward),bloodGroup(bg) {
            cout << "Full admission: " << name << endl;
        }
        // Destructor
        ~Patient() {
            cout << "[Destructor] Patient "<< name<< " discharged." << endl;
        }
        // Display patient record
        void displayRecord() const {
            cout << "\nPatient Record:" << endl;
            cout << "ID       : " << patientId << endl;
            cout << "Name     : " << name << endl;
            cout << "Age      : " << age << endl;
            cout << "Ward     : " << ward << endl;
            cout << "Blood Grp: " << bloodGroup << endl;
        }
        // Transfer patient to another ward
        void transferWard(const string& newWard) {
            cout << "Ward Transfer: "<< name << " + "<< newWard << endl;
            ward = newWard;
        }
};

int main(){
    cout << "===== STACK PATIENTS =====" << endl;
    // 1. Three stack objects using different constructors
    Patient p1(1001,"Meera Joshi",34,"Cardiology","B+");
    Patient p2(1002,"Raj Patel");
    Patient p3;
    cout << "\n===== DYNAMIC PATIENT ARRAY =====" << endl;
    // 2. Create dynamic array of 4 Patient objects Default constructor will be called 4 times
    Patient* patients = new Patient[4];
    cout << "\n===== DISPLAYING DYNAMIC PATIENTS =====" << endl;
    // 3. Display all 4 patients
    for (int i = 0; i < 4; i++) {
        patients[i].displayRecord();
    }
    // 4. Transfer one patient's ward
    cout << "\n===== WARD TRANSFER =====" << endl;
    patients[1].transferWard("ICU");
    // 5. Delete dynamic arrayDestructor will be called 4 times
    cout << "\n===== DELETING DYNAMIC ARRAY =====" << endl;
    delete[] patients;
    cout << "\n===== END OF MAIN =====" << endl;
    return 0;
}