#ifndef PATIENT_H
#define PATIENT_H

#include <string>

class Patient{
    private:
    int id;
    
    protected:
    std::string name;
    std::string description;
    std::string category;
    int appointmentDay, appointmentMonth;
    
    public:
    Patient* next;
    Patient();
    ~Patient(){}

};


#endif