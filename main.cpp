#include <iostream>
#include "Node.h"
#include <cstring>

using namespace std;

void addNode(Student* &value, Node* &head);
void printList(Node* node, Node* head);
void deleteNode(char* name, Node* &node, Node* &head);

int main() 
{
  Node* head = NULL; //beginning of list
  char input[100];
  while(strcmp(input, "quit") != 0)
  {
    cout << "Type ADD, DELETE, PRINT, or QUIT" << endl;
    cin.getline(input, 100);
    if(strcmp("add", input) == 0)
    {
      cout << "Enter name of student" << endl;
      cin.getline(input, 100);
      Student* newStudent = new Student(input);
      addNode(newStudent, head);
    }
    if(strcmp("delete", input) == 0)
    {
      cout << "Enter name of student" << endl;
      cin.getline(input, 100);

    }
    if(strcmp("print", input) == 0)
    {
      //cout << "head:"<<head->getStudent() << endl;
      printList(head, head);
    }
  }
} 

void addNode(Student* &value, Node* &head)
{
  Node* current = head; //set current to first node in list
  if(current == NULL) //if list is empty
  {
    head = new Node(value);
  }
  else
  {
    while(current->getNext() != NULL)//while current node is not the last node
    {
      current = current->getNext(); //change current to the next node in the chain
    }
    Node* newNode = new Node(value); //reaches end of list, makes new node with given value
    current->setNext(newNode); //connects former last node in list to new node
  }
}

void deleteNode(char* name, Node* &node, Node* &head);
{
  if(node == head && strcmp(node->getStudent()->getName(), name) == 0)
  {
    head = head->getNext();
    delete node;
  }
  else if(strcmp(node->getStudent()->getName(), name) == 0)
  {
    node->getNext()
  }
  else
  {
    deleteNode(name, node->getNext(), head);
  }
}

void printList(Node* node, Node* head)
{
  if(node == head) //first call of function
  {
    cout << "List: ";
  }
  if(node != NULL) //if there's another node
  {
    if(node->getNext() == NULL) //if last node
    {
      cout << node->getStudent()->getName() << endl;
    }
    else
    {
      cout << node->getStudent()->getName() << ", ";
    }
    printList(node->getNext(), head); 
  }
}
