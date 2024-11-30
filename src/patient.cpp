#include <iostream>
#include <string>
#include "patient.h"

Patient::Patient()
{
    next = nullptr;
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