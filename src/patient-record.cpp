#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "patient-record.h"

using namespace std;
std::string idArr[100] = {}; // selected id, get by find id

// constructor
Patient_Record::Patient_Record()
{
    top = nullptr;
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
void Patient_Record::addPatient(string name, string description, string category) // plainning to change this to normal linked list
{
    ++userId;
    cout << userId << endl;
    string newUserID = "P" + to_string(userId);
    Patient *newPatient = new Patient();
    newPatient->setId(newUserID);
    newPatient->setName(name);
    newPatient->setDescription(description);
    newPatient->setCategory(category);
    newPatient->setNext(top);
    top = newPatient;
    this->printToFile(newPatient, 1);
    totalPatient++;
}


// delete element
// tak
Patient *Patient_Record::deletePatient(string deleteID)
{
    if (this->underflow())
    {
        cout << "No patients to delete." << endl;
        return nullptr;
    }

    Patient *current = top;
    Patient *previous = nullptr;

    // Search for the patient with the given ID
    while (current != nullptr && current->getId() != deleteID)
    {
        previous = current;
        current = current->getNext();
    }

    // If the patient was not found
    if (current == nullptr)
    {
        cout << "Patient with ID " << deleteID << " not found." << endl;
        return nullptr;
    }

    // If the patient to delete is the top node
    if (current == top)
    {
        top = top->getNext();
    }
    else
    {
        // Bypass the current node
        previous->setNext(current->getNext());
    }

    // Delete the current node
    delete current;
    totalPatient--;

    cout << "Patient with ID " << deleteID << " has been deleted." << endl;
    return nullptr; // Return nullptr as the patient has been deleted
}
// search by id
Patient *Patient_Record::searchID(string id)
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
string *Patient_Record::search(const string searchedItem)
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
{
    string name, category, description;
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
            choice = choice - 1;
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
        this->printToFile(patient, 1);
        break;
    }
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
        cout << "Timestamp: " << current->timestampToString() << endl;
        cout << "-------------------";
        cout << endl;
        current = current->getNext();
    }
}
// display by selected id
void Patient_Record::display(string *userId)
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
                cout << "Timestamp: " << current->timestampToString() << endl;
                cout << "-------------------";
                cout << endl;
            }
        }
        current = current->getNext();
    }
}
// display by id
void Patient_Record::display(Patient *patient)
{
    cout << endl
         << "Search Found:" << endl;
    cout << "===================" << endl;
    cout << "ID: " << patient->getId() << endl;
    cout << "Name: " << patient->getName() << endl;
    cout << "Description: " << patient->getDescription() << endl;
    cout << "Category: " << patient->getCategory() << endl;
    cout << "Timestamp: " << patient->timestampToString() << endl;
    cout << "-------------------";
    cout << endl;
}
// get last element
Patient *Patient_Record::traverseLastNode()
{
    current = top;
    for (int i = 0; i <= totalPatient; i++)
    {
        current = current->getNext();
    }
    return current;
}

void Patient_Record::newPatient(Patient *newPatient)
{
    if(top != nullptr){
    newPatient->setNext(top);
    top = newPatient;
    }else{
    top = newPatient;
    }
    cout << newPatient->getId() << endl;
}

void Patient_Record::printToFile(Patient *patient, int filechoice)
{
    ofstream fout;
    string filename;
    filechoice == 1 ? filename = "ALLPATIENT.txt" : filename = "PATIENT.txt";

    fout.open(filename);

    if (filechoice == 2)
    {
        // Output the patient data
        fout << patient->getId()
             << '\t' << patient->getName()
             << '\t' << patient->getDescription()
             << '\t' << patient->getCategory()
             << '\t' << patient->timestampToString() << endl;
    }
    else
    {
        patient = top;
        for (int i = 0; i <= totalPatient; i++)
        {
            fout << patient->getId()
                 << '\t' << patient->getName()
                 << '\t' << patient->getDescription()
                 << '\t' << patient->getCategory()
                 << '\t' << patient->timestampToString() << endl;
            patient = patient->getNext();
        }
    }

    fout.close();
}
void Patient_Record::getFromFile()
{
    ifstream fin;
    string line, id, name, description, category, timestamp;
    fin.open("ALLPATIENT.txt");

    // Loop to read each line from the file
    while (getline(fin, line))
    {                            // getline will return a whole line until '\n'. it will take the whole line
    Patient *temp = new Patient();
        istringstream iss(line); // construct an string stream to parse the whole line of string
        // get data until ',' is found, data is seperated by ','
        getline(iss, id, '\t');
        getline(iss, name, '\t');
        getline(iss, description, '\t');
        getline(iss, category, '\t');
        getline(iss, timestamp, '\t');
        if (id.empty() || name.empty() || description.empty() || category.empty() || timestamp.empty())
        {
            continue; // Skip this line if any field is empty
        }
        else
        {
            ++userId;
            temp->setId(id);
            temp->setName(name);
            temp->setDescription(description);
            temp->setCategory(category);
            temp->setTimestampString(timestamp);
            temp->setNext(top);
            top = temp;
            totalPatient++;
        }
    }
    fin.close();
    // cout << "\nNew Patient Created\n";
}

// Mae Yang buat
void Patient_Record::sortByName()
{
    if (top == nullptr || top->getNext() == nullptr)
    {
        // If the list is empty or has only one element, no need to sort
        return;
    }

    bool swapped;
    Patient *current, *nextNode, *lastSorted = nullptr;
    do
    {
        swapped = false;
        current = top;

        while (current != nullptr && current->getNext() != nullptr && current->getNext() != lastSorted)
        {
            nextNode = current->getNext();
            if (current->getName() > nextNode->getName())
            {
                string tempId = current->getId();
                string tempName = current->getName();
                string tempDescription = current->getDescription();
                string tempCategory = current->getCategory();
                tm tempTimestamp = current->getTimestamp();

                current->setId(nextNode->getId());
                current->setName(nextNode->getName());
                current->setDescription(nextNode->getDescription());
                current->setCategory(nextNode->getCategory());
                current->setTimestamp(nextNode->getTimestamp());

                nextNode->setId(tempId);
                nextNode->setName(tempName);
                nextNode->setDescription(tempDescription);
                nextNode->setCategory(tempCategory);
                nextNode->setTimestamp(tempTimestamp);

                swapped = true;
            }
            current = current->getNext();
        }
        lastSorted = current;
    } while (swapped);
    cout << "\nList has been sorted\n";
}
