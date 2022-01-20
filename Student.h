#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student
{
  public:
    Student(char* name, char* id, char* gpa); //constructor
    ~Student(); //deconstructor
    char* getName(); //returns name of student
    char* getId();
    char* getGpa();
    char* name;
    char* id;
    char* gpa;
};

#endif