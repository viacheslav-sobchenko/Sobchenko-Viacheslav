#include <iostream>
using namespace std;

class Node{
    public:
        int value;
        Node* next;
};

Node* creatList(){
    int count;
    cout << "Enter the number of items: ";
    cin >> count;

    Node* head = nullptr;
    Node* cur = nullptr;

    for(int i = 0; i < count; i++){
        int value;
        cout << "Item №" << i + 1 << ": ";
        cin >> value;

        Node* newNode = new Node();
        newNode -> value = value;
        newNode -> next = nullptr;

        if(!head){
            head = newNode;
            cur = newNode;
        } else{
            cur -> next = newNode;
            cur = newNode;
        }
    }

    return head;
}

void printList(Node* head){
    Node* cur = head;

    while(cur){
        cout << cur -> value << " ";
        cur = cur -> next;
    }

    cout << endl;
}

void addBefore(Node* & head, int target, int newValue){
    if(!head) return;

    if(head -> value == target){
        Node* newNode = new Node();

        newNode -> value = newValue;
        newNode -> next = head;
        head = newNode;

        return;
    }

    Node* prev = head;
    Node* cur = head -> next;

    while(cur){
        if(cur -> value == target){
            Node* newNode = new Node();

            newNode -> value = newValue;
            newNode -> next = cur;
            prev -> next = newNode;

            return;
        }

        prev = cur;
        cur = cur -> next;
    }

    cout << "Item not found :(" << endl;
}

void addAfter(Node* & head, int target, int newValue){
    Node* cur = head;

    while(cur){
        if(cur -> value == target){
            Node* newNode = new Node();

            newNode -> value = newValue;
            newNode -> next = cur -> next;
            cur -> next = newNode;

            return;
        }

        cur = cur -> next;
    }

    cout << "Item not found :(" << endl;
}

int main(){
    Node* head = creatList();

    cout << "Your list: ";
    printList(head);

    int choice, target, newValue;

    while(true){
        cout << "\nMenu:\n"
             << "1 - add itme before target\n"
             << "2 - add item after target\n"
             << "0 - end Code ^-^\n"
             << "Your choice: ";
        if(!(cin >> choice)) break;

        switch(choice){
            case 1:
                cout << "Add before which element? ";
                cin >> target;
                cout << "Value to add: ";
                cin >> newValue;
                addBefore(head, target, newValue);
                cout << "Updated list: ";
                printList(head);
                break;

            case 2:
                cout << "Add after which element? ";
                cin >> target;
                cout << "Value to add: ";
                cin >> newValue;
                addAfter(head, target, newValue);
                cout << "Updated list: ";
                printList(head);
                break;

             case 0:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice, try again! >-<" << endl;
        }
    }

    return 0;
}

