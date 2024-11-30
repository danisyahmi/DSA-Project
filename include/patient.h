#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <ctime>

class Patient{
    private:
    int id;
    std::string name;
    std::string description;
    std::string category;
    std::tm timestamp;
    int appointmentDay, appointmentMonth; // use ctime library to create timestamp
    
    protected:
    Patient* next;
    
    public:
    Patient();
    ~Patient(){}
    void setName(std::string);
    void setDescription(std::string);
    void setCategory(std::string);
    void setNext(Patient*);
    std::string getName();
    std::string getDescription();
    std::string getCategory();
    std::string getTimestamp();
    Patient* getNext();

};

#endif