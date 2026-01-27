#include "student.h"

Student::Student() : id(-1), name("") {}

Student::Student(int i, const std::string& n) : id(i), name(n) {}

std::string Student::getName() const{
    return name;
}


int Student::getId() const{
    return id;
}