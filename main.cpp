#include <iostream>
#include "Node.h"

using namespace std;

void addNode(Student* value);
void printList(Node* next);

Node* first = NULL; //first node in list

int main() 
{
  Student* bob = new Student("bob");
  addNode(bob);
  printList(first);
  Student* joe = new Student("joe");
  addNode(joe);
  printList(first);
} 

void addNode(Student* value)
{
  Node* current = first; //set current node to first node
  if(current == NULL)
  {
    first = new Node(value);
  }
  else
  {
    while(current->getNext() != NULL)//while current node is not the last node
    {
      current = current->getNext(); //change current to the next node in the chain
    }
    Node* newNode = new Node(value); //reaches end of list, makes new node with given value
    current->setNext(newNode); //former last node in list connected to new node
  }
}

void printList(Node* next)
{
  if(next == first)
  {
    cout << "List: ";
  }
  if(next != NULL)
  {
    cout << next->getStudent()->getName() << ", ";
  }
}