#include <iostream>
#include "patient-record.h"

using namespace std;

Patient_Record::Patient_Record()
{
    totalPatient = 0;
}

bool Patient_Record::underflow()
{
    
    if (totalPatient == 0)
    {
        cout << endl
             << "the stack is empty" << endl;
        return true;
    }
    return false;
    
}

bool Patient_Record::overflow()
{
    cout << "the stack is full" << endl;
    return true;
}

void Patient_Record::pushPatient(string name, string description, string category)
{
    Patient *newPatient = new Patient();
    newPatient->setName(name);
    newPatient->setDescription(description);
    newPatient->setCategory(category);

    // if(overflow()){
    // delete newPatient;
    //     return;
    // }
    if (top == nullptr || underflow())
    {
        top = newPatient;
    }
    else
    {
        newPatient->next = top;
        top = newPatient;
    }

    totalPatient++;
}

void Patient_Record::popPatient()
{
    if (top == nullptr)
    {
        cout << "No patients to pop." << endl;
        return;
    }
    Patient *temp = top;
    top = top->next;
    delete temp;
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

void Patient_Record::display()
{

    if (underflow())
    {
        return;
    }

    Patient *current = top;

    cout << totalPatient << endl;
    cout << "Patients in Record:" << endl;
    cout << "===================" << endl;
    for(int i = 0; i < totalPatient; i++){

        cout << "Name: " << current->getName() << endl;
        cout << "Description: " << current->getDescription() << endl;
        cout << "Category: " << current->getCategory() << endl;
        cout << "-------------------"; // Separator for clarity
        cout << endl;
        current = current->next;
    } 

}

Patient *Patient_Record::traverseLastNode()
{
    Patient *temp = top;
    while (temp->next)
    {
        temp = temp->next;
    }
    return temp;
}