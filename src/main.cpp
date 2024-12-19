#include <iostream>
#include <limits>
#include <fstream>
#include "patient-record.h"

using namespace std;

<<<<<<< Updated upstream
int main() {
    int* sorted;
    Patient patient;
    Patient_Record record;
    
    record.pushPatient("John Doe", "Flu symptoms", "General");
    record.pushPatient("Jane Smith", "Headache and nausea", "General");
    record.pushPatient("Alice Johnson", "Routine check-up", "Preventive");
    record.pushPatient("Bob Brown", "High blood pressure", "Chronic");
    record.pushPatient("Bob Brown", "High blood pressure", "Not Chronic");
    record.pushPatient("Charlie Davis", "Allergy symptoms", "General");

    // record.display();

    sorted = record.search("John Doe");
    record.display(sorted);
    sorted = record.search("Jane Smith");
    record.display(sorted);
    sorted = record.search("Bob Brown");
    record.display(sorted);
    sorted = record.search("General");
    record.display(sorted);
    patient = record.search(3);
    record.display(patient);
    record.updatePatient(patient);
    record.display(patient);

    
 
=======
int main()
{
    Patient_Record patientRecord;
    int choice;
    string name, description, category, searchedItem;
    string categoryChoice[] = {
        "General",    // For common or unspecified conditions
        "Chronic",    // For long-term medical conditions
        "Acute",      // For urgent or severe but short-term conditions
        "Preventive", // For routine check-ups or preventive care
        "Palliative"  // For comfort-focused care in terminal conditions
    };
    int id;
    int *foundIds = nullptr;            // Declare foundIds here
    Patient *patientToUpdate = nullptr; // Declare patientToUpdate here
    Patient *poppedPatient = nullptr;   // Declare poppedPatient here

    do
    {
        cout << "\nPatient Record System\n";
        cout << "=====================\n";
        cout << "1. Add Patient\n";
        cout << "2. Search Patient by ID\n";
        cout << "3. Search Patient by Name/Category\n";
        cout << "4. Update Patient\n";
        cout << "5. Display All Patients\n";
        cout << "6. Pop Patient\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Add Patient
            cout << "Enter patient name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter patient description: ";
            getline(cin, description);
            cout << "Enter patient category: \n";
            for (int i = 0; i < 5; i++)
            {
                cout << "[" << i + 1 << "] " << categoryChoice[i] << "\n";
            }
            cin >> choice;
            category = categoryChoice[choice - 1]; // Adjust for zero-based index
            patientRecord.pushPatient(name, description, category);
            cout << "Patient added successfully.\n";
            break;

        case 2: // Search Patient by ID
            cout << "Enter patient ID to search: ";
            cin >> id;
            Patient *foundPatientById;
            foundPatientById = patientRecord.search(id);
            if (foundPatientById)
            {
                patientRecord.display(foundPatientById);
            }
            else
            {
                cout << "Patient not found.\n";
            }
            break;

        case 3: // Search Patient by Name/Category
            cout << "Enter name or category to search: ";
            cin.ignore();
            getline(cin, searchedItem);
            foundIds = patientRecord.search(searchedItem);
            patientRecord.display(foundIds);
            break;

        case 4: // Update Patient
            cout << "Enter patient ID to update: ";
            cin >> id;
            patientToUpdate = patientRecord.search(id);
            if (patientToUpdate)
            {
                patientRecord.updatePatient(patientToUpdate);
                cout << "Patient updated successfully.\n";
            }
            else
            {
                cout << "Patient not found.\n";
            }
            break;

        case 5: // Display All Patients
            patientRecord.display();
            break;

        case 6: // Pop Patient
            poppedPatient = patientRecord.popPatient();
            if (poppedPatient)
            {
                cout << "Popped Patient ID: " << poppedPatient->getId() << endl;
                delete poppedPatient; // Free the memory
            }
            break;

        case 7: // Exit
            cout << "Exiting the system.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 7);

>>>>>>> Stashed changes
    return 0;
}