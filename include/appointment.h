#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include "patient-record.h"
#include "patient.h"

class Appointment : public Patient_Record // emergency inherit patient record
{

public:
    void setAppointment();
    void updateAppointment();
    void cancelAppointment();
};

#endif