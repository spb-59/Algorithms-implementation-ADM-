#include <iostream>

template <typename T>

struct node {
  node* next;
  T data;
};

template <typename T>
class LinkedList {
 private:
  node<T>* head;

 public:
  LinkedList() { head = nullptr; }

  void insertBeg(T value) {  // to insert a beggining of a linked list
    node<T>* newNode = new node<T>{nullptr, value};
    newNode->next = head;
    head = newNode;
  }

  void insertLasr(T value) {  // to onsert at end of list
    node<T>* newNode = new node<T>(value);
    if (head == nullptr) {
      head = newNode;
      return;
    }
    node<T>* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  void deleteNode(T value) {
    if (head == nullptr) {
      return;
    }
    if (head->data == value) {
      node<T>* temp = head;
      head = head->next;
      delete temp;
      return;
    }
    node<T>* temp = head;
    while (temp->next != nullptr && temp->next->data != value) {
      temp = temp->next;
    }
    if (temp->next == nullptr) {
      // node<T> with the given value not found
      return;
    }
    node<T>* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
  }

  void printList() {
    node<T>* temp = head;
    while (temp != nullptr) {
      std::cout << temp->data << " ";
      temp = temp->next;
    }
    std::cout << std::endl;
  }
};

int main(void){

LinkedList<int> list;
 list.insertBeg(1);
 list.insertBeg(1);
 list.insertBeg(1);
 list.insertBeg(1);

 list.printList();

 list.deleteNode(1);

 list.printList();



}
