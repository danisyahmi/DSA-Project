#ifndef PATIENT_RECORD_H
#define PATIENT_RECORD_H
#include <string>
#include <fstream>
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
    Patient* search(int);
    int* search(const std::string);
    void updatePatient(Patient*);
    int* sortAsc();
    int* sortAsc(int*);
    void display();
    void display(int*);
    void display(Patient*);
    Patient *traverseLastNode();
    void printToFile(Patient*, int);
    void getFromFile();
    bool underflow();
    bool overflow();
    void sortByName();
};

#endif