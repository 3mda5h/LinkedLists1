#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "Student.h"

using namespace std;

class Node
{
  public:
    Node(Student*);
    ~Node();
    Node* getNextNode();
    void setNextNode(Node* newNext);
  private:
    Student* s;
    Node* next;
};

#endif