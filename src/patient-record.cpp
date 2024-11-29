#include <iostream>
#include "patient-record.h"

using namespace std;

bool Patient_Record::underflow()
{
    if (totalPatient < 0)
    {
        return true;
    }
    return false;
}

bool Patient_Record::overflow()
{ 
    // if want to set limit for the record
    return true;
}

void Patient_Record::pushPatient()
{
    Patient* newPatient = new Patient();
    if(overflow()){
        cout << "the stack is full" << endl;
    }
    if(top == nullptr){
        top = newPatient;
    }
    else{
        newPatient->next = top;
        top = newPatient;
    }
    totalPatient++;
}

void Patient_Record::popPatient()
{
    if(top == nullptr){
        cout << "there is no Patient" << endl;
    }
    top = top->next;
    totalPatient--;
}

void Patient_Record::updatePatient(string name)
{

}

void Patient_Record::updatePatient(int id)
{

}

void Patient_Record::deletePatient()
{
    
}
Patient* Patient_Record::traverseLastNode()
{
    Patient* temp = new Patient();
    temp = top;
    while(temp->next){
        temp = temp->next;
    }   
    return temp;
}