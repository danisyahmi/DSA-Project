#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <ctime>

class Patient{
    private:
    int id = 0;
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
    int getId();
    std::string getName();
    std::string getDescription();
    std::string getCategory();
    std::string getTimestamp();
    Patient* getNext();

};

#endif