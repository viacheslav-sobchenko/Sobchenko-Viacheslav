#include <iostream>
using namespace std;


class Node {
public:
    int value;
    Node* prev;
    Node* next;

    //constructor for the convenience
    Node(int value) {
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }
};

//create doubly-linked list
void createList(Node*& head, Node*& tail) {
    //clean up two pointers in case they are pointing at something already
    head, tail = nullptr;

    int value;
    cin >> value;
    //if we haven't entered anything for head - exit
    if (!value) {
        return;
    }
    head = new Node(value);
    Node* cur = head;
    cin >> value;
    //now we create next node, point its prev pointer to out current node and our cur's next pointer to it. 
    // Then we can move cur to this next node to repeat
    while (value) {
        Node* temp = new Node(value);
        temp->prev = cur;
        cur->next = temp;
        cur = cur->next;
        cin >> value;
    }
    tail = cur;
}

//print doubly-linked-list(from head to tail)
void printListStartWithHead(Node* head) {
    Node* cur = head;
    while (cur != nullptr) {
        //do not forget to access node's value, not the node itself: 
        // otherwise it will just print the address of the node
        cout << cur->value << " ";
        cur = cur->next;
    }
}

//TODO: write deleteNode(...)

//TODO: write insertBefore(...)

//TODO: write insertAfter(...)
// 
//TODO: write isSymmetric(Node* head)

int main()
{
    Node* head = new Node(0);
    Node* tail = new Node(0);

    createList(head, tail);
    printListStartWithHead(head);
}

