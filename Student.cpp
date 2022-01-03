#include <iostream>
#include "Student.h"
#include <cstring>

using namespace std;

Student::Student(const char* newName)
{
  name = new char[100]; 
  strcpy(name, newName);
}

Student* Student::getStudent()
{
  return studentp;
}

char* Student::getName()
{
  return name;
}