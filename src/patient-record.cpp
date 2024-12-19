#include <iostream>
#include <limits>
#include "patient-record.h"

using namespace std;
int idArr[100] = {}; // selected id, get by find id

// constructor
Patient_Record::Patient_Record()
{
    totalPatient = 0;
    userId = 0;
}
// if stack is empty
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
    return false;
}
// push element into stack
void Patient_Record::pushPatient(string name, string description, string category) // plainning to change this to normal linked list
{
    ++userId;
    Patient *newPatient = new Patient();

    newPatient->setId(userId);
    newPatient->setName(name);
    newPatient->setDescription(description);
    newPatient->setCategory(category);

    // if(overflow()){
    // delete newPatient;
    //     return;
    // }

    newPatient->setNext(top);
    top = newPatient;
    totalPatient++;
}
// pop top element
Patient *Patient_Record::popPatient()
{
    if (this->underflow())
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
// search by id
Patient *Patient_Record::search(int id)
{
    current = top;
    for (int i = 0; i < totalPatient; i++)
    {
        if (current->getId() == id)
        {
            return current;
        }
        current = current->getNext();
    }
    current = nullptr;
    return current;
}
// search by name
int *Patient_Record::search(const string searchedItem)
{
    current = top;
    if (this->underflow())
    {
        current = nullptr;
    }
    int count = 0;
    for (int i = 0; i < totalPatient; i++)
    {
        if (current->getName() == searchedItem || current->getCategory() == searchedItem)
        {
            idArr[count] = current->getId();
            count++;
        }
        current = current->getNext();
    }
    current = top;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < totalPatient; j++)
        {
            if (current->getId() == idArr[i])
            {
                break;
            }
            current = current->getNext();
        }
    }
    return idArr; // found array
}
// update by id
void Patient_Record::updatePatient(Patient *patient)
{    string name, category, description;
    string categoryChoice[] = {
        "General",    // For common or unspecified conditions
        "Chronic",    // For long-term medical conditions
        "Acute",      // For urgent or severe but short-term conditions
        "Preventive", // For routine check-ups or preventive care
        "Palliative"  // For comfort-focused care in terminal conditions
    };
    int choice;

    cout << "\nWhat would you like to change?\n";
    cout << "1. Name\n2. Description\n3. Category\n4. Return\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\nEnter new name: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);
        patient->setName(name);
        break;

    case 2:
        cout << "\nEnter new description: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, description);
        patient->setDescription(description);
        break;

    case 3:
        int size = 5;

        while (true)
        {
            cout << "\n============================\n";
            cout << "   Select a New Category   \n";
            cout << "============================\n";

            for (int i = 0; i < size; i++)
            {
                cout << "[" << i + 1 << "] " << categoryChoice[i] << "\n";
            }

            cout << "\nEnter your choice (1-" << size << "): ";

            cin.clear();
            cin.ignore();
            cin >> choice;
            choice = choice -1;
            if (cin.fail() || choice < 1 || choice > size)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the line
                cout << "\nInvalid input. Please try again.\n";
            }
            else
            {
                category = categoryChoice[choice]; // Adjust for zero-based index

                cout << "\nYou selected: " << category << "\n";
                patient->setCategory(category);
                break; // Exit the loop
            }
        }
        category = categoryChoice[choice];
        patient->setCategory(category);
        break;

        // default:
        //     break;
    }
}
// sort all
int *Patient_Record::sortAsc(){
    
}
// sort selected id in array
int *Patient_Record::sortAsc(int *userid){
    // choose 1 sorting method
}
// display all
void Patient_Record::display()
{
    if (this->underflow())
    {
        return;
    }

    current = top;

    cout << endl
         << "Patients in Record:" << endl;
    cout << "===================" << endl;
    for (int i = 0; i < totalPatient; i++)
    {
        cout << "ID: " << current->getId() << endl;
        cout << "Name: " << current->getName() << endl;
        cout << "Description: " << current->getDescription() << endl;
        cout << "Category: " << current->getCategory() << endl;
        cout << "Timestamp: " << current->getTimestamp() << endl;
        cout << "-------------------";
        cout << endl;
        current = current->getNext();
    }
}
// display by selected id
void Patient_Record::display(int *userId)
{
    if (this->underflow())
    {
        return;
    }

    current = top;

    cout << endl
         << "Search Found:" << endl;
    cout << "===================" << endl;

    int size = sizeof(userId) / 4; // /4 cause sizeof() will return size in byte
    for (int i = 0; i < totalPatient; i++)
    {
        // this loop is to compare current with whole array
        for (int j = 0; j < size; j++)
        {
            if (current->getId() == userId[j])
            {
                cout << "ID: " << current->getId() << endl;
                cout << "Name: " << current->getName() << endl;
                cout << "Description: " << current->getDescription() << endl;
                cout << "Category: " << current->getCategory() << endl;
                cout << "Timestamp: " << current->getTimestamp() << endl;
                cout << "-------------------";
                cout << endl;
            }
        }
        current = current->getNext();
    }
}
// display by id
void Patient_Record::display(Patient* patient)
{
    cout << endl
         << "Search Found:" << endl;
    cout << "===================" << endl;
    cout << "ID: " << patient->getId() << endl;
    cout << "Name: " << patient->getName() << endl;
    cout << "Description: " << patient->getDescription() << endl;
    cout << "Category: " << patient->getCategory() << endl;
    cout << "Timestamp: " << patient->getTimestamp() << endl;
    cout << "-------------------";
    cout << endl;
}
// get last element
Patient *Patient_Record::traverseLastNode()
{
    current = top;
    for (int i = 0; i < totalPatient; i++)
    {
        current = current->getNext();
    }
    return current;
}