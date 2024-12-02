#include <iostream>
#include <string>
#include "patient.h"
#include "patient-record.h"

using namespace std;

int main() {
    Patient_Record record;
    
    record.pushPatient("John Doe", "Flu symptoms", "General");
    record.pushPatient("Jane Smith", "Headache and nausea", "General");
    record.pushPatient("Alice Johnson", "Routine check-up", "Preventive");
    record.pushPatient("Bob Brown", "High blood pressure", "Chronic");
    record.pushPatient("Charlie Davis", "Allergy symptoms", "General");

    record.display();

    record.updatePatient("John Doe");
    // record.popPatient();
    // record.display();
    
    // record.popPatient();
    // record.display();

    // record.popPatient();
    // record.popPatient();
    // record.popPatient();
    
    // record.popPatient();
    // record.display();

    return 0;
}