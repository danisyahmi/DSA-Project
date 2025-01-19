#pragma once

#ifndef EMERGENCY_H
#define EMERGENCY_H
#include <string>
#include <ctime>
#include "patient-record.h"

class Emergency : public Patient_Record
{
public:
    Emergency();
    ~Emergency() {}
    void addPatient(std::string id, const std::string& name, const std::string& category);
    void removePatient();
    void viewPatients() const;
    std::string checkQueue() const;

};

#endif
