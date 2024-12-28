#include <iostream>
#include <limits>
#include <fstream>
#include "patient-record.h"

using namespace std;

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
    Patient *patientToPrint = nullptr;

    //----------------------------------------------------------------------------------------------------------
    // Adding 20 dummy patient records for testing
    string dummyNames[20] = {
    "Charlie",
    "Diana",
    "Ethan",
    "George",
    "Hanna",
    "Fiona",
    "Alice",
    "Kevin",
    "Isaac",
    "Michael",
    "Bob",
    "Julia",
    "Paula",
    "Nina",
    "Laura",
    "Oliver",
    "Rachel",
    "Quentin",
    "Samuel",
    "Tina"
    };
    for (int i = 1; i < 5; ++i)
    {
        
        string name = "Patient " + dummyNames[i];
        string description = "Description for patient " + dummyNames[i];
        string category;

        // Assign categories in a round-robin fashion
        switch (i % 5)
        {
        case 1:
            category = "General";
            break;
        case 2:
            category = "Chronic";
            break;
        case 3:
            category = "Acute";
            break;
        case 4:
            category = "Preventive";
            break;
        case 0:
            category = "Palliative";
            break;
        }

        patientRecord.pushPatient(name, description, category);
        
    }
    cout << "20 dummy patients added successfully.\n";
    //----------------------------------------------------------------------------------------------------------

    do
    {
       cout << "\n=====================\n";
        cout << " Patient Record System \n";
        cout << "=====================\n";
        cout << "1. Add Patient\n";
        cout << "2. Search Patient by ID\n";
        cout << "3. Search Patient by Name/Category\n";
        cout << "4. Update Patient\n";
        cout << "5. Display All Patients\n";
        cout << "6. Pop Patient\n";
<<<<<<< HEAD
        cout << "7. Print Patient to File\n"; // New option
        cout << "8. Get Patient from File\n"; // New option
        cout << "9. Exit\n";
=======
        cout << "7. Sort Patients by Name\n";
        cout << "8. Exit\n";
>>>>>>> 7f6886dadb061b783138fb9af25a73b85ded576a
        cout << "=====================\n";
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
            cout << "Select patient category:\n";
            for (int i = 0; i < 5; i++)
            {
                cout << "[" << i + 1 << "] " << categoryChoice[i] << "\n";
            }
            cout << "Enter your choice (1-5): ";
            cin >> choice;

            // Validate category choice
            if (choice < 1 || choice > 5)
            {
                cout << "Invalid category choice. Please try again.\n";
                break;
            }

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
                delete poppedPatient;
            }
            else
            {
                cout << "No patients to pop.\n";
            }
            break;

<<<<<<< HEAD
        case 7: // Print Patient to File
            cout << "Enter patient ID to print to file: ";
            cin >> id;
            patientToPrint = patientRecord.search(id);
            if (patientToPrint)
            {
                patientRecord.printToFile(patientToPrint, 2);
                cout << "Patient record printed to file successfully.\n";
            }
            else
            {
                cout << "Patient not found.\n";
            }
            break;

        case 8: // Get Patient from File
            patientRecord.getFromFile();
            break;

        case 9: // Exit
=======
        case 7: // Sort Patients by Name
            patientRecord.sortByName(); 
            cout << "Patients sorted by name successfully.\n";
            break;

        case 8: // Exit
>>>>>>> 7f6886dadb061b783138fb9af25a73b85ded576a
            cout << "Exiting the system. Thank you!\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
<<<<<<< HEAD
    } while (choice != 9);
=======
    } while (choice != 8);
>>>>>>> 7f6886dadb061b783138fb9af25a73b85ded576a

    return 0;
}