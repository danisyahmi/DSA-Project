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
// if there is limit for the stack
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
        newPatient->setNext(top);
        top = newPatient;
    }

    totalPatient++;
}

Patient* Patient_Record::popPatient()
{
    if (underflow())
    {
        cout << "No patients to pop." << endl;
        return nullptr;
    }
    Patient *temp, *poppedNode;
    temp = poppedNode = top;
    top = top->getNext();
    totalPatient--;
    delete temp;
    return poppedNode;
}
// update by name
void Patient_Record::updatePatient(string name)
{

}
// update by id
void Patient_Record::updatePatient(int id)
{
}

void Patient_Record::display()
{

    if (underflow())
    {
        return;
    }

    Patient *current = top;

    cout << endl << "Patients in Record:" << endl;
    cout << "===================" << endl;
    for(int i = 0; i < totalPatient; i++){

        cout << "Name: " << current->getName() << endl;
        cout << "Description: " << current->getDescription() << endl;
        cout << "Category: " << current->getCategory() << endl;
        cout << "Timestamp: " << current->getTimestamp() << endl;
        cout << "-------------------"; 
        cout << endl;
        current = current->getNext();
    } 

}

// Patient *Patient_Record::traverseLastNode()
// {
//     Patient *current = top;
//     while (current->getNext())
//     {
//         current = current->getNext();
//     }
//     return current;
// }