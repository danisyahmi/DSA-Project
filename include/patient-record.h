#ifndef PATIENT_RECORD_H
#define PATIENT_RECORD_H
#include <string>
#include "patient.h"

class Patient_Record : public Patient
{

private:
    Patient *top;
    int userId;
    int totalPatient;

public:
    Patient_Record();
    ~Patient_Record() {};
    void pushPatient(std::string, std::string, std::string);
    Patient* popPatient();
    void updatePatient(std::string name);
    void updatePatient(int id);
    void display();
    void display(int[]);
    // Patient *traverseLastNode();
    bool underflow();
    bool overflow();
};

#endif