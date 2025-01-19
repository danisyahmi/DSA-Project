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
    void addPatient(std::string, std::string, std::string);
    Patient* deletePatient(std::string);
    Patient* searchID(std::string);
    std::string* search(const std::string);
    void updatePatient(Patient*);
    void display();
    void display(std::string*);
    void display(Patient*);
    void newPatient(Patient*, std::string newUserID, std::string, std::string, std::string);
    Patient *traverseLastNode();
    void printToFile(Patient*, int);
    void getFromFile();
    bool underflow();
    bool overflow();
    void sortByName();
};

#endif