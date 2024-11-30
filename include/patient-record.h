#ifndef PATIENT_RECORD_H
#define PATIENT_RECORD_H
#include <string>
#include "patient.h"

class Patient_Record : public Patient
{

private:
    Patient *top;
    int totalPatient;

public:
    Patient_Record();
    ~Patient_Record() {};
    void pushPatient(std::string, std::string, std::string);
    void popPatient();
    void updatePatient(std::string name);
    void updatePatient(int id);
    void deletePatient();
    void display();
    Patient *traverseLastNode();
    bool underflow();
    bool overflow();
};

#endif