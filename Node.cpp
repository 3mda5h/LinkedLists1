#include<iostream>
#include "Node.h"

using namespace std;

Node::Node(Student* value)
{
  Student* student = new Student();
  student = value;
  Node* next = NULL;
}

void Node::setNextNode(Node* newNext)
{
  next = newNext;
}

Node* Node::getNextNode()
{
  return next;
}

