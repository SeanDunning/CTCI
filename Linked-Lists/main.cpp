#include <iostream>

using namespace std;

class Node {

public:
   Node *next;
   int data;

    Node () {};
    ~Node() {};

    Node(int d) {
    data = d;
    next = NULL;

  }

};
class LinkedList {

public:

  Node *head;
  int sizeLL = 1;

  LinkedList() { head = NULL;}
  LinkedList(Node *n) {head = n;}
  ~LinkedList() {
    Node* ptr = head;
    while(head) {
      ptr = head->next;
      delete head;
      head = ptr;
    }
  }

  void appendNodeEnd(Node *node) {

    if (head == NULL){ //set head if doesn't exist
        head = node;
        head->next = NULL;
        return;
      }

    Node *n = head;

    while(n->next){ //move next til end of list
      n = n->next;
      sizeLL++;
      }
    n->next = node;
    sizeLL++;
  }

  void printList() {
    Node *n = head;
    cout << n->data << endl;
    while (n->next != NULL) { //move next until end of list
      n = n->next;
      cout << n->data << endl;
    }
  }

  void deleteDuplicate() {
    bool numSeen[sizeLL]; //if a number is "visited"
    int dupCount = 0; //keep track of duplicates

    Node *n = head; //begin traversal
    while (n->next->next != NULL) {
        if (numSeen[n->next->data] == false) { //no duplicate
          numSeen[n->next->data] = true; //
          n = n->next;
        } else { //duplicate found
          n->next = n->next->next; //n->next is duplicate, bypass it
          n = n->next; //move along linked list
          dupCount++; //count of duplicate
        }
    }
  cout << "Duplicates found: " << dupCount << endl;
  }
};
int main()
{
    Node *head = new Node(5);
    LinkedList ll(head);

    Node *n1 = new Node(27);
    Node *n2 = new Node(43);
    Node *n3 = new Node(47);
    Node *n4 = new Node(27);
    Node *n5 = new Node(25);
    Node *n6 = new Node(12);
    ll.appendNodeEnd(n1);
    ll.appendNodeEnd(n2);
    ll.appendNodeEnd(n3);
    ll.appendNodeEnd(n4);
    ll.appendNodeEnd(n5);
    ll.appendNodeEnd(n6);

    ll.printList(); //print list
    ll.deleteDuplicate(); //find duplicates

    return 0;
}
