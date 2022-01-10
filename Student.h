#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student
{
  public:
    Student(char* name); //constructor
    ~Student(); //deconstructor
    char* getName(); //returns name of student
    char* name;
};

#endif