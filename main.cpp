//Linked List - a linked list of nodes containing student pointers, use can add 
//Emily MacPherson, 1/10/22
#include <iostream>
#include "Node.h"
#include <cstring>

using namespace std;

void addNode(Student* &value, Node* &head, Node* previous);
void printList(Node* node, Node* head);
void deleteNode(char* id, Node* &head, Node* previous, Node* current);
void average(Node* node, int numofnodes, double sum);

int main() 
{
  Node* head = NULL; //beginning of list
  char input[100];
  while(strcmp(input, "quit") != 0)
  {
    cout << "Type ADD, DELETE, PRINT, AVERAGE, or QUIT" << endl;
    cin.getline(input, 100);
    for(int i = 0; i < strlen(input); i++)
    {
      input[i] = tolower(input[i]);
    }
    if(strcmp("add", input) == 0)
    {
      cout << "Enter student name" << endl;
      char name[100];
      cin.getline(name, 100);
      cout << "Enter student id" << endl;
      char id[100];
      cin.getline(id, 100);
      cout << "Enter student gpa" << endl;
      char gpa[100];
      cin.getline(gpa, 100);
      Student* newStudent = new Student(name, id, gpa);
      addNode(newStudent, head, NULL);
    }
    if(strcmp("delete", input) == 0)
    {
      cout << "Enter name of student" << endl;
      cin.getline(input, 100);
      deleteNode(input, head, head, head);
    }
    if(strcmp("average", input) == 0)
    {
      average(head, 0, 0);
    }
    if(strcmp("print", input) == 0)
    {
      //cout << "head:"<<head->getStudent() << endl;
      printList(head, head);
    }
  }
} 

//adds node to the end of the list
void addNode(Student* &value, Node* &head, Node* previous, Node* current)
{
  if(head == NULL) //if list is empty
  {
    head = new Node(value);
  }
  else
  {
    if(current->getStudent()->getGpa() < previous->getStudent()->getGpa())
    {
      addNode(value, head, current->getNext(),current);
    }
    Node* newNode = new Node(value);
    previous->setNext(newNode);
    newNode->setNext(current->getNext());
  }
}

//deletes node with given name from list
void deleteNode(char* id, Node* &head, Node* previous, Node* current)
{
  if(current == head && strcmp(current->getStudent()->getId(), id) == 0) //if first node in list and names match
  {
    head = head->getNext(); //2nd node is now the head node
    delete current; //delete first node
  }
  else if(strcmp(current->getStudent()->getId(), id) == 0) //if not the first node and ids match
  {
    previous->setNext(current->getNext()); //previous node connected to next node
    delete current;
  }
  else
  {
    previous = current;    
    deleteNode(id, head, previous, current->getNext());
  }
}

//prints out every element in the list
void printList(Node* node, Node* head)
{
  if(node == head) //first call of function
  {
    cout << "List: " << endl;
  }
  if(node != NULL) 
  {
    cout << node->getStudent()->getName() << ", " << node->getStudent()->getId() << ", " << node->getStudent()->getGpa() << endl;
    printList(node->getNext(), head); 
  }
}

void average(Node* node, int numofnodes, double sum)
{
  numofnodes++;
  sum += atof(node->getStudent()->getGpa());
  if(node->getNext() == NULL) //last node
  {
    cout << "average gpa: " << sum / numofnodes << endl;
  }
  else
  {
    average(node->getNext(), numofnodes, sum);
  }
}
