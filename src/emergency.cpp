
#include "emergency.h"
#include <iostream>
#include <queue>
#include <vector>

struct PatientDetails {
    std::string id;
    std::string name;
    std::string category;
};

struct ComparePriority {
    bool operator()(const PatientDetails& a, const PatientDetails& b) {
        return a.category < b.category;
    }
};


static std::priority_queue<PatientDetails, std::vector<PatientDetails>, ComparePriority> patientQueue;
static const int MAX_QUEUE_SIZE = 10; // Set maximum queue size 


Emergency::Emergency() {}

// Add a patient to the queue
void Emergency::addPatient(std::string id, const std::string& name, const std::string& category) {
    PatientDetails newPatient = { id, name, category };
    patientQueue.push(newPatient);
    std::cout << "Patient added successfully: \nID = " << id << " \nName = " << name << " \nCategory = " << category << '\n';
}

// Remove the highest-priority patient
void Emergency::removePatient() {
    if (!patientQueue.empty()) {
        const PatientDetails& topPatient = patientQueue.top();
        std::cout << "Removing patient: \nID = " << topPatient.id
            << " \nName = " << topPatient.name
            << " \nCategory = " << topPatient.category << '\n';
        patientQueue.pop();
    }
    else {
        std::cout << "No patients in the queue to remove.\n";
    }
}

// Check the queue status   
std::string Emergency::checkQueue() const {
    if (patientQueue.empty()) {
        return "QUEUE STATUS = EMPTY";
    }
    else if (patientQueue.size() >= MAX_QUEUE_SIZE) {
        return "QUEUE STATUS = FULL";
    }
    else {
        return "QUEUE STATUS = NOT FULL & NOT EMPTY";
    }
}

// View all patients in descending order of priority
void Emergency::viewPatients() const {

    /*if (patientQueue.empty()) {
        std::cout << "No patients in queue.\n";
        return;
    }*/

    // Temporary copy of the queue to display patients without modifying the original queue
    std::priority_queue<PatientDetails, std::vector<PatientDetails>, ComparePriority> tempQueue = patientQueue;

    std::cout << "Patient List (Descending Order of Priority):\n";
    std::cout << "\n=====================================================";
    std::cout << "\nEMERGENCY QUEUE ";
    std::cout << "\n=====================================================\n";
    std::cout << checkQueue() << std::endl; // Add the queue status output
    std::cout << "=====================================================";
    std::cout << "\nID\t|\tNAME\t|\tCATEGORY";
    std::cout << "\n-----------------------------------------------------\n";
    while (!tempQueue.empty()) {
        const PatientDetails& patient = tempQueue.top();
        std::cout << "\n" << patient.id << "\t|\t"
            << patient.name << "\t|\t"
            << patient.category << '\n';
        std::cout << "\n-----------------------------------------------------";
        tempQueue.pop();
    }
}