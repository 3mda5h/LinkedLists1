#include <iostream>
#include "Student.h"
#include <cstring>

using namespace std;

Student::Student(char* newName)
{
  name = new char[100]; 
  strcpy(name, newName);
}

Student::~Student()
{
  delete name;
}

char* Student::getName()
{
  return name;
}