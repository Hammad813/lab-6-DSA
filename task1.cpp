#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* Next;
};
void insertatbegining(Node* &head,int value)
{   // allocate the memory for new node
    Node* new_node = new Node(); // if pass the value in constructor
    // Assign the data to new node
    new_node->data = value ;
    new_node->Next=head;
    head=new_node;
};
void printlist(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->Next;
    }
    cout << "NULL" << endl;
}
void deletenode(Node*& head, int value) {
    if (head == NULL) {
        cout << "The list is empty. Nothing to delete." << endl;
        return;
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->Next;
        delete temp;
        cout << "Node with value " << value << " deleted." << endl;
        return;
    }
    Node* current = head;
    while (current->Next != NULL && current->Next->data != value) {
        current = current->Next;
    }

    if (current->Next == NULL) {
        cout << "Value " << value << " not found in the list." << endl;
        return;
    }
    Node* temp = current->Next;
    current->Next = current->Next->Next;
    delete temp;
    cout << "Node with value " << value << " deleted." << endl;
}
bool search(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return true;
        }
        temp = temp->Next;
    }
    return false;
}
int main() {
    cout << "*** LAB 5 ***" << endl;
    Node* head = NULL;
    int size;
    cout << "How many values do you want to enter in the linked list? " << endl;
    cin >> size;
    int value;
    for (int i = 0; i < size; i++) {
        cout << "Enter the value for block " << i + 1 << " of the linked list: " << endl;
        cin >> value;
        if (value > 0) {
            insertatbegining(head, value);
        }
    }
    cout << "Linked List is: " << endl;
    printlist(head);
    cout << "Enter the value to be deleted: " << endl;
    cin >> value;
    deletenode(head, value);
    cout << "The updated list is: " << endl;
    printlist(head);
    cout << "Enter the value to search: " << endl;
    cin >> value;
    if (search(head, value)) {
        cout << "Value " << value << " found in the list." << endl;
    } else {
        cout << "Value " << value << " not found in the list." << endl;
    }
    return 0;
}