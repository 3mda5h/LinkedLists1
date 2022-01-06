#include <iostream>
#include "Node.h"
#include <cstring>

using namespace std;

void addNode(Student* student, Node* &head);
void printList(Node* node, Node* head);

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

void addNode(Student* student, Node* &head)
{
  //cout << student->getName() << endl;
  Node* current = head; //set current to first node in list
  if(current == NULL) //if list is empty
  {
    head = new Node(student);
    //cout << head->getStudent()->getName() << endl;
  }
  else
  {
    while(current->getNext() != NULL)//while current node is not the last node
    {
      current = current->getNext(); //change current to the next node in the chain
    }
    Node* newNode = new Node(student); //reaches end of list, makes new node with given value
    current->setNext(newNode); //connects former last node in list to new node
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
    Student* student = node->getStudent();
    //cout << student << endl;
   // cout << "called" << endl;
    char* c = node->getStudent()->getName();
   // cout << c << endl;
   // cout << node->getStudent()->getName() << ", ";
    printList(node->getNext(), head); 
  }
}