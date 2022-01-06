#include<iostream>
#include "Node.h"

using namespace std;

Node::Node(Student* newStudent)
{
  Student* student = newStudent;
  //cout << student->getName();
  Node* next = NULL;
}

void Node::setNext(Node* newNext)
{
  next = newNext;
}

Student* Node::getStudent()
{
  //cout << student << endl;
  //cout << student->getName();
  return student;
}

Node* Node::getNext()
{
  return next;
}

