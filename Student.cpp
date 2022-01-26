#include <iostream>
#include "Student.h"
#include <cstring>

using namespace std;

Student::Student(char* newName, char* newId, double newGpa)
{
  name = new char[100];
  id = new char[100];
  strcpy(name, newName);
  strcpy(id, newId);
  gpa = newGpa;
}

Student::~Student()
{
  delete name;
}

char* Student::getName()
{
  return name;
}

char* Student::getId()
{
  return id;
}

double Student::getGpa()
{
  return gpa;
}