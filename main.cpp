#include <iostream>
#include "Node.h"

using namespace std;

void addNode(Student* value);

Node* head = NULL; //first node in list

int main() 
{
  
} 

void addNode(Student* value)
{
  Node* current = head; //set current node to first node
  if(current == NULL)
  {
    head = new Node(value);
  }
  else
  {
    
  }
}