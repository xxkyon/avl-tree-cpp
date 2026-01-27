#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student{
    private:
    int id;
    std::string name;

    public:
    Student();
    Student(int id, const std::string& name);
    
    std::string getName() const;
    int getId() const;
};

#endif

