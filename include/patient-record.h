#pragma once

#ifndef PATIENT_RECORD_H
#define PATIENT_RECORD_H
#include <string>
#include <fstream>
#include <vector>
#include "patient.h"
class Patient_Record
{
private:
    Patient* top;
    int userId;
    int totalPatient;

public:
    Patient* current;
    Patient_Record();
    ~Patient_Record() {};
    void addPatient(std::string, std::string, std::string);
    Patient* deletePatient(std::string);
    Patient* searchID(std::string);
    std::vector<std::string>search(const std::string& , int& );
    void updatePatient(Patient*);
    void display();
    void display(const std::vector<std::string>& userIds);
    void display(Patient*);
    Patient* traverseLastNode();
    void printToFile(Patient*, int);
    void getFromFile();
    bool underflow();
    bool overflow();
    void sortByName();
};

#endif
