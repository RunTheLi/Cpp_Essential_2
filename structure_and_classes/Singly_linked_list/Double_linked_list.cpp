// An empty list:
//
//  Node*
// +------+
// | head |-->nullptr
// +------+
//
//  Node*
// +------+
// | tail |-->nullptr
// +------+
//
//
//
// A list with two elements:
//
//  Node*      Node         Node
//
//            +-----+      +-----+
//   nullptr<-|prev |   +--|prev |
// +------+   +-----+<--+  +-----+
// | head |-->|value|      |value|
// +------+   +-----+  +-->+-----+
//            |next |--+   |next |-->nullptr
//            +-----+      +-----+
//                           ^
// +------+                  |
// | tail |------------------+
// +------+

class Node
{
public:
  Node(int val);
  int value;
  Node* prev;
  Node* next;
};

class List
{
public:
  List();
  List(List &other);
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

int List::at(int index){
    if (index < 0) {
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
    int n = size();
    if (index == n) {
        push_back(value);
        return;
    }
    if (index < 0 || index > n) {
        cout << "Index out of range" << endl;
        return;
    }

    Node* current = head;
    for(int i = 0; i < index -1; i++) {
        current = current->next;
    }

    Node* newNode = new Node(value);
    Node* nextNode = current->next;

    newNode->next = current->next;
    newNode->prev = current;
    current->next = newNode;

    if (nextNode != nullptr) nextNode->prev = newNode;
    else tail = newNode;
}

void List::remove_at(int index){
    int n = size();
  if(index < 0 || index >= n) {
    cout << "Index out of range!" << endl;
    return;
  }

  if (index == 0) {
    int dummy;
      pop_front(dummy);
        return;
    }

  if (index == size() - 1) {
    int dummy;
      pop_back(dummy);
        return;
    }

    Node* current = head;
    for (int i = 0; i < index; i++) {
      current = current->next;
    }

    Node* prevNode = current->prev;
    Node* nextNode = current->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    delete current;
}

List::List() : head(nullptr), tail(nullptr) {}

List::List(const List& other) : head(nullptr), tail(nullptr) {
    Node* current = other.head;
    while (current != nullptr) {
        this->push_back(current->value);
        current = current->next;
    }
}

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
    if (tail == nullptr) return false;
    Node* popped = tail;
    value = popped->value;
    tail = tail->prev;
    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    delete popped;
    return true;
}
// ...

void List::push_front(int value)
{
  Node* newNode = new Node(value);
  newNode->next = head;
  newNode->prev = nullptr;
  if(head != nullptr) {
    head->prev = newNode;
  } else {
    tail = newNode;
  }
  head = newNode;
}

bool List::pop_front(int &value)
{
  if (head == nullptr) {
    return false;
  }

  Node* popped = head;
  head = head-> next;
  value = popped -> value;
  
  if(head != nullptr) {
    head -> prev = nullptr;
  } else {
    tail = nullptr;
  }

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

void List::push_back(int value)
{
    Node* newNode = new Node(value);
    newNode -> prev = tail;
    newNode -> next = nullptr;
    if (tail != nullptr) {
        tail->next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;
}

Node::Node(int val) : value(val), prev(nullptr), next(nullptr) {}

void printList(List &list) {
for (int i = 0; i < list.size(); ++i) {
cout << "list[" << i << "] == " << list.at(i) << endl;
}
}

int main() {
List list1;
list1.push_back(1);
list1.push_back(2);
list1.push_back(3);
list1.push_back(4);


cout << "list1" << endl;
printList(list1);


// Make a copy of list1
List list2 = list1; // uses deep copy constructor


cout << "\nlist2" << endl;
printList(list2);


// Modify list1
list1.insert_at(1, 6);
list1.remove_at(3);


cout << "\nlist1 after modification" << endl;
printList(list1);


cout << "\nlist2 remains unchanged" << endl;
printList(list2);


return 0;
}
