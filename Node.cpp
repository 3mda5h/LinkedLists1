#include<iostream>
#include "Node.h"

using namespace std;

Node::Node(Student* newStudent)
{
  student = newStudent;
  next = NULL;
}

Node::~Node()
{
  delete student;
  delete next;
}

void Node::setNext(Node* newNext)
{
  next = newNext;
}

Student* Node::getStudent()
{
  return student;
}

Node* Node::getNext()
{
  return next;
}

