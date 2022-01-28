//set up the getters and setters for student and next pointers, constructor/destructor; linked with Student.h to use student stuff

#ifndef NODE_H
#define NODE_H
#include <iostream> 
#include "Student.h"

using namespace std;

class Node {
  public:
    Node(Student* newStudent);
    ~Node();
    Node* getNext();
    void setNext(Node* newNext);
    Student* getStudent();

  //student and next pointer variables
  private:
    Student* student;
    Node* next;
};

#endif
