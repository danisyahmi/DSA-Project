#ifndef PATIENT_RECORD_H
#define PATIENT_RECORD_H
#include <string>
#include "patient.h"

class Patient_Record
{
private:
    Patient *top;
    int userId;
    int totalPatient;

public:
    Patient *current;
    Patient_Record();
    ~Patient_Record() {};
    void pushPatient(std::string, std::string, std::string);
    Patient* popPatient();
    Patient search(int);
    int* search(const std::string);
    void updatePatient(Patient&);
    void display();
    void display(int*);
    void display(Patient);
    Patient *traverseLastNode();
    bool underflow();
    bool overflow();
};

#endif