#include <iostream>

using namespace std;

class Node
{
public:
  Node(int val);
  int value;
  Node* next;
};

class List
{
public:
  List();
  ~List();
  void push_front(int value);
  bool pop_front(int &value);
  void push_back(int value);
  bool pop_back(int &value);
  int  at(int index);
  void insert_at(int index, int value);
  void remove_at(int index);
  int size();
private:
  // other members you may have used
  Node* head;
  Node* tail;
};

// ...

int List::at(int index){
    if(index < 0) {
        cout << "Index out of range" << endl;
        return -1;
    }

    Node* current = head;
    int i = 0;

    while(current != nullptr && i < index) {
        current = current->next;
        i++;
    }

    if(current == nullptr) {
        return -1;
    }

    return current->value;
}

void List::insert_at(int index, int value){
    if(index == 0) {
        push_front(value);
        return;
    }

    if(index == size()) {
        push_back(value);
        return;
    }

    Node* current = head;
    for(int i = 0; i < index -1; i++) {
        current = current->next;
    }

    Node* newNode = new Node(value);
    newNode->next = current->next;
    current->next = newNode;
}

void List::remove_at(int index){
  if(index < 0 || index >= size()) {
    cout << "Index out of range!" << endl;
    return;
  }

  if (index == 0) {
    int dummy;
      pop_front(dummy);
        return;
    }

  if(index == size() - 1) {
    int dummy;
      pop_back(dummy);
        return;
    }

    Node* current = head;
    for(int i = 0; i < index - 1; i++) {
      current = current->next;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

List::List() : head(nullptr), tail(nullptr) {}

List::~List(){
    Node* current = head;
    while(current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    tail = nullptr;
}

bool List::pop_back(int &value)
{
    if (head == nullptr) {
        return false;  
    }

    if (head == tail) {
        value = head->value;
        delete head;
        head = nullptr;
        tail = nullptr;
        return true;
    }

    Node* current = head;
    while (current->next != tail) {
        current = current->next;
    }

    value = tail->value;
    delete tail;
    tail = current;
    tail->next = nullptr;

    return true;
}
// ...

void List::push_front(int value)
{
  Node* new_head = new Node(value);
  new_head->next = head;
  head = new_head;
  if (tail == nullptr) tail = head;
}

bool List::pop_front(int &value)
{
  if (head == nullptr) {
    return false;
  }

  Node* popped = head;
  head = head-> next;
  value = popped -> value;
  delete popped;
  

  if(head == nullptr) {
    tail = nullptr;
  }
  return true;
}

int List::size(){
    int count = 0;
    Node* current = head;
    while(current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void List::push_back(int value)
{
    Node* newNode = new Node(value);

    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

Node::Node(int val) : value(val), next(nullptr) {}

void printList(List &list)
{
    for (int i = 0; i < list.size(); i++)
    {
        cout << "list[" << i << "] == " << list.at(i) << endl;
    }
}
int main()
{
  List list;
  //
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);
  printList(list);
  cout << endl;

  list.remove_at(2);
  printList(list);
  cout << endl;

  list.insert_at(1, 6);
  printList(list);

  return 0;
}