
#include <iostream>
#include <String>
#include <limits>
#include <fstream>
#include "patient-record.h"
#include "emergency.h"

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
    string id, patientToDeleteID;
    string* foundIds = nullptr;            // Declare foundIds here
    Patient* patientToUpdate = nullptr; // Declare patientToUpdate here
    Patient* patientToDelete = nullptr;   // Declare patientToDelete here
    Patient* patientToPrint = nullptr;
    Emergency emergencyQueue;

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

    for (int i = 1; i < 20; ++i)
    {

        string name = dummyNames[i];
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

        patientRecord.addPatient(name, description, category);
    }
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
        cout << "6. Delete Patient\n";
        cout << "7. Print Patient to File\n"; // New option
        cout << "8. Get Patient from File\n"; // New option
        cout << "9. Sort Patients by Name\n";
        cout << "10. Emergency Patient\n";
        cout << "11. Exit\n";
        cout << "=====================\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
            patientRecord.addPatient(name, description, category);
            cout << "Patient added successfully.\n";
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
            patientToUpdate = patientRecord.searchID(id);
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

        case 6: // delete Patient
            cout << "Enter patient ID to delete: ";
            getline(cin, patientToDeleteID);
            patientToDelete = patientRecord.deletePatient(patientToDeleteID);
            if (patientToDelete)
            {
                cout << "Popped Patient ID: " << patientToDelete->getId() << endl;
                delete patientToDelete;
            }
            else
            {
                cout << "No patients to pop.\n";
            }
            break;

        case 7: // Print Patient to File
            cout << "Enter patient ID to print to file: ";
            getline(cin, id);
            patientToPrint = patientRecord.searchID(id);
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
            patientRecord.sortByName();
            cout << "Patients sorted by name successfully.\n";
            break;

        case 10: // Emergency Operations
            int emergencyChoice;
            do
            {
                cout << "\n=== Emergency ===\n";
                cout << "1. Add Emergency Patient\n";
                cout << "2. Remove Highest Priority Patient\n";
                cout << "3. View Emergency Queue\n";
                cout << "4. Back to Main Menu\n";
                cout << "============================\n";
                cout << "Enter your choice: ";
                cin >> emergencyChoice;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                string patientId;
                switch (emergencyChoice)
                {
                case 1: // Add Emergency Patient
                    patientRecord.display();
                    cout << "\nEnter the ID of the patient to add to the emergency queue: ";

                    cin >> patientId;

                    // Search for the patient in the record by ID
                    patientToPrint = patientRecord.searchID(patientId);
                    if (patientToPrint != nullptr)
                    {
                        emergencyQueue.addPatient(
                            patientToPrint->getId(), // Convert ID back to integer if necessary.
                            patientToPrint->getName(),
                            patientToPrint->getCategory()
                        );
                        cout << "Emergency patient added successfully.\n";
                    }
                    else
                    {
                        cout << "Patient ID not found. Please try again.\n";
                    }
                    break;

                case 2: // Remove Highest Priority Patient
                    emergencyQueue.removePatient();
                    break;

                case 3: // View Emergency Queue
                    emergencyQueue.viewPatients();
                    break;

                case 4: // Back to Main Menu
                    break;

                default:
                    cout << "Invalid choice. Please try again.\n";
                    break;
                }
            } while (emergencyChoice != 4);
            break;

        case 11:
            cout << "Exiting the system. Thank you!\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 11);
    return 0;
}