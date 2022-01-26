//Linked List - a linked list of nodes containing student pointers. User can add, delete, and print out whole list or gpa averages
//Emily MacPherson, 1/10/22
#include <iostream>
#include "Node.h"
#include <cstring>
#include <iomanip>

using namespace std;

void addNode(Student* &value, Node* &head, Node* previous, Node* current);
void printList(Node* node, Node* head);
void deleteNode(char* id, Node* &head, Node* previous, Node* current);
void average(Node* node, int numofnodes, double sum);

int main() 
{
  cout << fixed << setprecision(2); //so gpa float will round to the 100ths or print 2 trailing 0s
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
      cout << "Enter student ID" << endl;
      char id[100];
      cin.getline(id, 100);
      cout << "Enter student GPA" << endl;
      char gpa[100];
      cin.getline(gpa, 100);
      double dub = atof(gpa);
      Student* newStudent = new Student(name, id, dub);
      addNode(newStudent, head, NULL, head);
    }
    if(strcmp("delete", input) == 0)
    {
      if(head == NULL)
      {
        cout << "The list is empty" << endl;
      }
      else
      {
        cout << "Enter student ID" << endl;
        cin.getline(input, 100);
        deleteNode(input, head, head, head);
      }
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

//adds new node into list in order of lowest id to highest
void addNode(Student* &value, Node* &head, Node* previous, Node* current)
{
  if(head == NULL) //if list is empty
  {
    head = new Node(value);
  }
  else if(current == head) 
  {
    if(atoi(value->getId()) < atoi(head->getStudent()->getId()))//if new id is lower than head id
    {
      //replace head node with new node
      Node* newNode = new Node(value);
      newNode->setNext(head);
      head = newNode;
    }
    else if(current->getNext() == NULL) //if new id is greater & head node is last node 
    {
      //add new node after head
      Node* newNode = new Node(value);
      current->setNext(newNode);
    }
    else //if new id is greater & head node not last node
    {
      addNode(value, head, current, current->getNext()); //next node
    }
  }
  else
  {
    if((atoi(value->getId()) >= atoi(current->getStudent()->getId()) )) //if new id is greater than or equal to current id
    {
      if(current->getNext() == NULL) //if current node is last node
      {
        //add new node to end of list
        Node* newNode = new Node(value);
        current->setNext(newNode);
      }
      else
      {
        addNode(value, head, current, current->getNext()); //next node
      }
    }
    else //new id is less than current node 
    {
      //insert node in between previous node and current node
      Node* newNode = new Node(value); 
      newNode->setNext(current);
      previous->setNext(newNode);

    }
  }
}

//deletes node with given id from list
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

//prints out the average gpa of all students
void average(Node* node, int numofnodes, double sum)
{
  numofnodes++; //keeps track of total amount of nodes in list
  sum += node->getStudent()->getGpa();
  if(node->getNext() == NULL) //last node
  {
    cout << "Average GPA: " << sum / numofnodes << endl;
  }
  else
  {
    average(node->getNext(), numofnodes, sum);
  }
}
