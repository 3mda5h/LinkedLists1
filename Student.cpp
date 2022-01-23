#include <iostream>
#include "Student.h"
#include <cstring>

using namespace std;

Student::Student(char* newName, char* newId, char* newGpa)
{
  name = new char[100];
  gpa = new char[100]; 
  id = new char[100];
  strcpy(name, newName);
  strcpy(gpa, newGpa);
  strcpy(id, newId);


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

char* Student::getGpa()
{
  return gpa;
}