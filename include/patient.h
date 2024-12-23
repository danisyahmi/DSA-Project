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
    std::tm apppoinment;
    
    protected:
    Patient* next;
    
    public:
    Patient();
    ~Patient(){}
    void setName(std::string);
    void setDescription(std::string);
    void setCategory(std::string);
    void setNext(Patient*);
    void setId(int);
    void setTimestamp(std::tm);
    int getId();
    std::string getName();
    std::string getDescription();
    std::string getCategory();
    std::tm getTimestamp();
    std::string timestampToString();
    Patient* getNext();

};

#endif