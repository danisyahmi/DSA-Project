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
    int appointmentDay, appointmentMonth; // use ctime library to create timestamp
    
    public:
    Patient* next;
    Patient();
    ~Patient(){}
    void setName(std::string);
    void setDescription(std::string);
    void setCategory(std::string);
    std::string getName();
    std::string getDescription();
    std::string getCategory();
    

};


#endif