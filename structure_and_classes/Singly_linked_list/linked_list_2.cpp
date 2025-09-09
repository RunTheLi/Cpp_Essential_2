#include <iostream>

using namespace std;

class Node
{
public:
  Node(int val);
  ~Node();
  int value;
  Node* next;
};

Node::Node(int val) : value(val), next(nullptr)
{
  cout << "+Node" << endl;
}

Node::~Node()
{
  cout << "-Node" << endl;
}

class List
{
public:
  List();
  ~List();
  void push_front(int value);
  bool pop_front(int &value);
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
  head=new_head;
}

bool List::pop_front(int &value)
{
  // implement the pop
  // don't forget to delete the popped node!
  // and fix the return value
  if (head == nullptr) {
    return false;
  }

  Node* popped = head;
  head = head-> next;
  value = popped -> value;
  delete popped;
  return true;
}
// ...

int main()
{
  List list;
  //
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);

  return 0;
}