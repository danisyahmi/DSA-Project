#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
#include "patient.h"

Patient::Patient()
{
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

std::tm Patient::getTimestamp() {
    return this->timestamp;
}

// return timestamp in string
std::string Patient::timestampToString()
{
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timestamp); // convert timestamp to char array in format set
    this->timestampString = std::string(buffer);
    return this->timestampString;
}

Patient* Patient::getNext()
{
    return next;
}

std::string Patient::getId() {
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

void Patient::setNext(Patient* next)
{
    this->next = next;
}

void Patient::setId(std::string id) {
    this->id = id;
}

void Patient::setTimestamp(tm timestamp) {
    this->timestamp = timestamp;
}

void Patient::setTimestampString(std::string timestampString) {
    this->timestampString = timestampString;
}