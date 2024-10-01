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
void findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->Next != NULL) {
        slow = slow->Next;
        fast = fast->Next->Next;
    }

    if (slow != NULL) {
        cout << "The middle element is: " << slow->data << endl;
    }
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
    cout << "\nFinding the middle element of the linked list..." << endl;
    findMiddle(head);
    return 0;
}