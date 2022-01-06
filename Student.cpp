#include <iostream>
#include "Student.h"
#include <cstring>

using namespace std;

Student::Student(char* newName)
{
  name = new char[100]; 
  strcpy(name, newName);
}

char* Student::getName()
{
  return name;
}