#include <iostream>

using namespace std;

class Node
{
public:
  Node(int val);
  int value;
  Node* next;
};

Node::Node(int val) : value(val), next(nullptr) {}

class List
{
public:
  List();
  ~List();
  void push_front(int value);
  bool pop_front(int &value);
  void push_back(int value);
  bool pop_back(int &value);
  int size();
private:
  // other members you may have used
  Node* head;
  Node* tail;
};

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


int main()
{
  List list;
  //
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);

  int value = 0;
  while (list.pop_back(value))
  {
    cout << value << endl;
  }
  return 0;
}