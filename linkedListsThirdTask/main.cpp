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


//TO DO: write deleteNode(...)
void deleteNode(Node*& head, Node*& tail, int target){
    if(!head) return;

    if(head->value == target){
        Node* cur = head;
        Node* next = head->next;
        Node* prev = head->prev;

        if(next) next->prev = prev;
        else tail = prev;

        if(prev) prev->next = next;
        else head = next;

        delete cur;

        return;
    }

    deleteNode(head->next, tail, target);
}


//TO DO: write insertBefore(...)
void insertBefore(Node*& head, Node*& tail, int target, int newValue){
    Node* cur = head;

    while(cur){
        if(cur->value == target){
            Node* n = new Node(newValue);
            n->prev = cur->prev;
            n->next = cur;

            if(cur->prev) cur->prev->next = n;
            else head = n;

            cur->prev = n;

            return;
        }

        cur = cur->next;
    }
}


//TO DO: write insertAfter(...)
void insertAfter(Node*& head, Node*& tail, int target, int newValue){
    Node* cur = head;

    while(cur){
        if(cur->value == target){
            Node* n = new Node(newValue);
            n->next = cur->next;
            n->prev = cur;

            if(cur->next) cur->next->prev = n;
            else tail = n;

            cur->next = n;

            return;
        }

        cur = cur->next;
    }
}


//TO DO: write isSymmetric(Node* head)
bool isSymmetric(Node* head){
    if(!head || !head->next) return true;

    Node* left = head;
    Node* right = head;
    while(right->next) right = right->next;

    while(left && right && left != right && right->next != left){
        if(left->value != right->value) return false;

        left = left->next;
        right = right->prev;
    }

    return true;
}


int main()
{
    Node* head = new Node(0);
    Node* tail = new Node(0);

    cout << "Enter list values (end with 0): ";
    createList(head, tail);
    cout << "List: ";
    printListStartWithHead(head);
    cout << endl;

    while(true){
        cout << "\nMenu:\n"
             << "1 - print list\n"
             << "2 - insert BEFORE value\n"
             << "3 - insert AFTER  value\n"
             << "4 - delete by value\n"
             << "5 - check symmetric\n"
             << "0 - exit\n"
             << "Your choice: ";

        int choice;
        if(!(cin >> choice)) return 0;

        if(choice == 0){
            cout << "Exiting.\n";

            return 0;
        }

        switch(choice){
        case 1: {
            cout << "List: ";
            printListStartWithHead(head);
            cout << endl;

            break;
        }
        case 2: {
            int target, newValue;
            cout << "Insert BEFORE which value? ";
            cin >> target;
            cout << "Value to insert: ";
            cin >> newValue;
            insertBefore(head, tail, target, newValue);
            cout << "Updated list: ";
            printListStartWithHead(head);
            cout << endl;

            break;
        }
        case 3: {
            int target, newValue;
            cout << "Insert AFTER which value? ";
            cin >> target;
            cout << "Value to insert: ";
            cin >> newValue;
            insertAfter(head, tail, target, newValue);
            cout << "Updated list: ";
            printListStartWithHead(head);
            cout << endl;

            break;
        }
        case 4: {
            int target;
            cout << "Delete which value? ";
            cin >> target;
            deleteNode(head, tail, target);
            cout << "Updated list: ";
            printListStartWithHead(head);
            cout << endl;

            break;
        }
        case 5: {
            cout << (isSymmetric(head) ? "Symmetric" : "Not symmetric") << endl;

            break;
        }
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}

