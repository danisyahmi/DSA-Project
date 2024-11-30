#include <iostream>
#include <string>
#include "patient.h"
#include "patient-record.h"

using namespace std;

int main() {
    Patient_Record record;
    try{
    // Test adding patients with dummy data
    record.pushPatient("John Doe", "Flu symptoms", "General");
    record.pushPatient("Jane Smith", "Headache and nausea", "General");
    record.pushPatient("Alice Johnson", "Routine check-up", "Preventive");
    record.pushPatient("Bob Brown", "High blood pressure", "Chronic");
    record.pushPatient("Charlie Davis", "Allergy symptoms", "General");
    
    // Display all patients
    record.display();

    // Pop patients and display the state after each pop
    record.popPatient();
    record.display();
    
    record.popPatient();
    record.display();

    // Pop remaining patients
    record.popPatient();
    record.popPatient();
    record.popPatient();
    

    // Attempt to pop from an empty stack
    record.popPatient();
    // Display all patients
    record.display();

    }
    catch (const std::length_error& e) {  
        std::cerr << "Length error encountered: " << e.what() << std::endl;  
    }  
    return 0;
}