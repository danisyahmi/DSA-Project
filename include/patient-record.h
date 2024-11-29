#ifndef PATIENT_RECORD_H
#define PATIENT_RECORD_H
#include <string>
#include "patient.h"

class Patient_Record : Patient{
    private: 
    int totalPatient;
    Patient* top;
    public:

    ~Patient_Record(){};
    void pushPatient();
    void popPatient();
    void updatePatient(std::string name);
    void updatePatient(int id);
    void deletePatient();
    Patient* traverseLastNode();
    bool underflow();
    bool overflow();

};

#endif