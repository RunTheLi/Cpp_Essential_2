#include <iostream>
#include <sstream>

using namespace std;

class Node
{
public:
  Node(int val);
  ~Node();
  int value;
  Node* next;
};

Node::Node(int val) : value(val), next(nullptr) {}
Node::~Node() {}

class List
{
public:
  List();
  ~List();
  void push_front(int value);
  bool pop_front(int &value);
  int  size();
private:
  Node* head;
};

List::List() : head(nullptr) {}

List::~List(){
    Node* current = head;
    while(current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

void List::push_front(int value)
{
  Node* new_head = new Node(value);
  new_head->next = head;
  head = new_head;
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
// ...

int main()
{
  List list;
  for (int i = 0; i <= 5; i++)
  {
    list.push_front(i);
    cout << "pushed " << i << ", size: " << list.size() << endl;
  }
  cout << endl;
  for (int i = 0; i <= 3; i++)
  {
    int value;
    list.pop_front(value);
    cout << "popped " << i << ", size: " << list.size() << endl;
  }
  return 0;
}