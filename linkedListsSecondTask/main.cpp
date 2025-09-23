#include <iostream>
using namespace std;

//написаний код гарний, немає жодних питань - 80/100

class Node{
public:
    int value;
    Node* next;
};


// ================= CREATE =================
Node* createList(int i, int n){
    if(i > n) return nullptr;

    int v;
    cout << "Item #" << i << ": ";
    cin >> v;

    Node* node = new Node();
    node->value = v;
    node->next = createList(i + 1, n);

    return node;
}


// ================= PRINT =================
void printList(Node* head){
    if(!head){
        cout << "\n";
        return;
    }

    cout << head->value << " ";
    printList(head->next);
}


// ================= INSERT BEFORE =================
bool insertBefore(Node*& nodeRef, int target, int newValue){
    if(!nodeRef) return false;

    if(nodeRef->value == target){
        Node* n = new Node();
        n->value = newValue;
        n->next = nodeRef;
        nodeRef = n;

        return true;
    }

    return insertBefore(nodeRef->next, target, newValue);
}


// ================= INSERT AFTER =================
bool insertAfter(Node* node, int target, int newValue){
    if(!node) return false;

    if(node->value == target){
        Node* n = new Node();
        n->value = newValue;
        n->next = node->next;
        node->next = n;

        return true;
    }

    return insertAfter(node->next, target, newValue);
}


// ================= DELETE BEFORE =================
bool deleteBefore(Node*& nodeRef, int target){
    if(!nodeRef || !nodeRef->next) return false;

    if(nodeRef->next->value == target){
        Node* toDel = nodeRef;
        nodeRef = nodeRef->next;
        delete toDel;

        return true;
    }

    return deleteBefore(nodeRef->next, target);
}


// ================= MAIN =================
int main(){
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    Node* head = createList(1, n);

    cout << "Your list: ";
    printList(head);

    int choice, target, value;

    while(true){
        cout << "\nMenu:\n"
             << "1 - print your list\n"
             << "2 - insert BEFORE target\n"
             << "3 - insert AFTER  target\n"
             << "4 - delete element BEFORE target\n"
             << "0 - exit\n"
             << "Your choice: ";

        if(!(cin >> choice)) return 0;

        switch(choice){
        case 1:
            cout << "Your List: ";
            printList(head);

            break;

        case 2:
            cout << "Insert BEFORE which element? ";
            cin >> target;
            cout << "Value to insert: ";
            cin >> value;

            if(!insertBefore(head, target, value))
                cout << "Element not found\n";

            cout << "Updated list: ";
            printList(head);

            break;

        case 3:
            cout << "Insert AFTER which element? ";
            cin >> target;
            cout << "Value to insert: ";
            cin >> value;

            if(!insertAfter(head, target, value))
                cout << "Element not found\n";

            cout << "Updated list: ";
            printList(head);

            break;

        case 4:
            cout << "Delete element BEFORE which target? ";
            cin >> target;

            if(head && head->value == target)
                cout << "Nothing to delete (target is head).\n";
            else if(deleteBefore(head, target))
                cout << "Updated list: ";
            else
                cout << "Nothing to delete (target not found).\n";

            printList(head);

            break;

        case 0:
            cout << "Exiting program.\n";

            return 0;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}
