#include <iostream>
#include <string>
#include <ctime>
#include "patient.h"

Patient::Patient()
{
    id += 1;
    next = nullptr;
    std::time_t now = std::time(nullptr);
    this->timestamp = *std::localtime(&now); // get localtime
}

std::string Patient::getName()
{
    return name;
}

std::string Patient::getDescription()
{
    return description;
}

std::string Patient::getCategory()
{
    return category;
}

// return timestamp in string
std::string Patient::getTimestamp()
{
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timestamp); // convert timestamp to char array in format set
    return std::string(buffer);
}

Patient *Patient::getNext()
{
    return next;
}

int Patient::getId(){
    return id;
}

void Patient::setName(std::string name)
{
    this->name = name;
}

void Patient::setDescription(std::string description)
{
    this->description = description;
}

void Patient::setCategory(std::string category)
{
    this->category = category;
}

void Patient::setNext(Patient *next)
{
    this->next = next;
}