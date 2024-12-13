#include <iostream>
#include <string>
#include "patient.h"
#include "patient-record.h"

using namespace std;

int main() {
    int* sorted;
    Patient patient;
    Patient_Record record;
    
    record.pushPatient("John Doe", "Flu symptoms", "General");
    record.pushPatient("Jane Smith", "Headache and nausea", "General");
    record.pushPatient("Alice Johnson", "Routine check-up", "Preventive");
    record.pushPatient("Bob Brown", "High blood pressure", "Chronic");
    record.pushPatient("Bob Brown", "High blood pressure", "Not Chronic");
    record.pushPatient("Charlie Davis", "Allergy symptoms", "General");

    // record.display();

    sorted = record.search("John Doe");
    record.display(sorted);
    sorted = record.search("Jane Smith");
    record.display(sorted);
    sorted = record.search("Bob Brown");
    sorted = record.search("Bob Brown");
    record.display(sorted);
    patient = record.search(1);
    record.display(patient);
 
    return 0;
}