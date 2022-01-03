#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student
{
  public:
    Student(const char* name);
    Student* getStudent();
    char* getName();
    Student* studentp;
    char* name;
};

#endif