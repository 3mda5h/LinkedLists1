//Linked List - a linked list of nodes containing student pointers, use can add 
//Emily MacPherson, 1/10/22
#include <iostream>
#include "Node.h"
#include <cstring>

using namespace std;

void addNode(Student* &value, Node* &head);
void printList(Node* node, Node* head);
void deleteNode(char* name, Node* &head, Node* previous, Node* node);

int main() 
{
  Node* head = NULL; //beginning of list
  char input[100];
  while(strcmp(input, "quit") != 0)
  {
    cout << "Type ADD, DELETE, PRINT, or QUIT" << endl;
    cin.getline(input, 100);
    for(int i = 0; i < strlen(input); i++)
    {
      input[i] = tolower(input[i]);
    }
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
      deleteNode(input, head, head, head);
    }
    if(strcmp("print", input) == 0)
    {
      //cout << "head:"<<head->getStudent() << endl;
      printList(head, head);
    }
  }
} 

//adds node to the end of the list
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

//deletes node with given name from list
void deleteNode(char* name, Node* &head, Node* previous, Node* node)
{
  if(node == head && strcmp(node->getStudent()->getName(), name) == 0) //if first node in list and names match
  {
    head = head->getNext(); //2nd node is now the head node
    delete node; //delete first node
  }
  else if(strcmp(node->getStudent()->getName(), name) == 0) //if not the first node and names match
  {
    previous->setNext(node->getNext()); //previous node connected to next node
    delete node;
  }
  else
  {
    previous = node;    
    deleteNode(name, head, previous, node->getNext());
  }
}

//prints out every element in the list
void printList(Node* node, Node* head)
{
  if(node == head) //first call of function
  {
    cout << "List: ";
  }
  if(node != NULL) 
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
