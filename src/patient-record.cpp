#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "patient-record.h"

using namespace std;

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
void Patient_Record::addPatient(string name, string description, string category) // plainning to change this to normal linked list
{
    ++userId;
    string newUserID = "P" + to_string(userId);
    Patient *newPatient = new Patient();
    newPatient->setId(newUserID);
    newPatient->setName(name);
    newPatient->setDescription(description);
    newPatient->setCategory(category);
    newPatient->setNext(top);
    top = newPatient;
    printToFile(newPatient, 1);
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
    while (current != nullptr) // Loop until current is nullptr
    {
        if (current->getId() == id) // Compare IDs
        {
            return current; // Return the patient if found
        }
        current = current->getNext(); // Move to the next patient
    }
    // current = nullptr;
    return current;
}
// search by name
vector<string> Patient_Record::search(const string &searchedItem, int &size)
{
    vector<string> foundIds; // Store matching IDs

    current = top;
    if (this->underflow()) // Check for underflow
    {
        size = 0;        // No patients
        return foundIds; // Return empty vector
    }

    // Find matching patients
    for (int i = 0; i < totalPatient; i++)
    {
        if (current->getName() == searchedItem || current->getCategory() == searchedItem)
        {
            foundIds.push_back(current->getId()); // Dynamically add ID
        }
        current = current->getNext();
    }

    // Set size to the number of matches
    size = foundIds.size();

    // Return the vector of found IDs
    return foundIds;
}

// update by id
void Patient_Record::updatePatient(Patient *patient)
{
    cout << patient->getId();
    int size = 5;
    int choice = 0;
    string name, category, description;
    string categoryChoice[] = {
        "General",
        "Chronic",
        "Acute",
        "Preventive",
        "Palliative"};

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
            cin >> choice;
            if (cin.fail() || choice < 1 || choice > size)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nInvalid input. Please try again.\n";
            }
            else
            {
                choice = choice - 1;
                category = categoryChoice[choice];
                cout << "\nYou selected: " << category << '\n';
                patient->setCategory(category);

                break; // Exit the loop
            }
        }
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
    cout << "==============================================================================================================" << endl;

    cout << left
         << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(40) << "Description"
         << setw(20) << "Category"
         << setw(25) << "Timestamp"
         << endl;

    cout << "==============================================================================================================" << endl;

    for (int i = 0; i < totalPatient; i++)
    {
        cout << left
             << setw(10) << current->getId()
             << setw(20) << current->getName()
             << setw(40) << current->getDescription()
             << setw(20) << current->getCategory()
             << setw(25) << current->timestampToString()
             << endl;
        current = current->getNext();
    }
    cout << "==============================================================================================================" << endl;
}
// display by selected id
void Patient_Record::display(const vector<string> &userIds)
{
    if (this->underflow())
    {
        cout << "No patients in the record.\n";
        return;
    }
    if (userIds.empty())
    {
        cout << "No IDs to search for.\n";
        return;
    }

    current = top;

    cout << endl << "==============================================================================================================" << endl;
    // Display table header
    cout << left << setw(12) << "ID"
         << setw(20) << "Name"
         << setw(30) << "Description"
         << setw(15) << "Category"
         << setw(20) << "Timestamp" << endl;

    cout << string(100, '=') << endl; // Divider line

    // Traverse the linked list
    while (current != nullptr)
    {
        for (const auto &id : userIds)
        {
            if (current->getId() == id)
            {
                cout << left << setw(12) << current->getId()
                     << setw(20) << current->getName()
                     << setw(30) << current->getDescription()
                     << setw(15) << current->getCategory()
                     << setw(20) << current->timestampToString() << endl;
                break;
            }
        }
        current = current->getNext();
    }
}

// display by id
void Patient_Record::display(Patient *patient)
{
    if (patient == nullptr)
    {
        cout << "No patient found." << endl;
        return;
    }

    cout << endl;
    cout << left << setw(12) << "ID"
         << setw(20) << "Name"
         << setw(30) << "Description"
         << setw(15) << "Category"
         << setw(20) << "Timestamp" << endl;

    cout << string(100, '=') << endl; // Divider line

    cout << left << setw(12) << patient->getId()
         << setw(20) << patient->getName()
         << setw(30) << patient->getDescription()
         << setw(15) << patient->getCategory()
         << setw(20) << patient->timestampToString() << endl;

    cout << string(100, '-') << endl; // Bottom divider line
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

void Patient_Record::printToFile(Patient *patient, int filechoice)
{
    ofstream fout;
    string filename;
    filechoice == 1 ? filename = "ALLPATIENT.txt" : filename = "PATIENT.txt";

    fout.open(filename);

    if (filechoice == 2)
    {
        fout << std::string(95, '-') << std::endl;

        // Output the patient data
        fout << std::left << std::setw(10) << "ID"
             << std::setw(20) << "Name"
             << std::setw(30) << "Description"
             << std::setw(15) << "Category"
             << std::setw(20) << "Timestamp" << std::endl;

        fout << std::string(95, '-') << std::endl;

        fout << std::left << std::setw(10) << patient->getId()
             << std::setw(20) << patient->getName()
             << std::setw(30) << patient->getDescription()
             << std::setw(15) << patient->getCategory()
             << std::setw(20) << patient->timestampToString() << std::endl;
        fout << std::string(95, '-') << std::endl;
    }
    else
    {
        patient = top;
        while (patient)
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
    {
        Patient *temp = new Patient;
        // getline will return a whole line until '\n'. it will take the whole line
        istringstream iss(line); // construct an string stream to parse the whole line of string
        // get data until ',' is found, data is seperated by ','
        getline(iss, id, '\t');
        getline(iss, name, '\t');
        getline(iss, description, '\t');
        getline(iss, category, '\t');
        getline(iss, timestamp, '\t');

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

    fin.close();
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