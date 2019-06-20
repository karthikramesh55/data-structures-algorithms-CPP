#include <iostream>
#include <cstdlib>

using namespace std;

struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};

struct Node* head; //declaration of the pointer to the head-node.

struct Node* getNewNode(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); //newNode is a local variable to this function.
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
};

void insertNodeAtHead(int x) {
    struct Node* newNode = getNewNode(x); //newNode is a local variable to this function as has not relation to the previous function.
    if(head == NULL) {
        head = newNode;
        return;
    }
    else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void insertNodeAtTail(int x) {
    struct Node* temp = head;
    struct Node* newNode = getNewNode(x); //newNode is a local variable to this function as has not relation to the previous functions.
    if(head == NULL) {
        head = newNode;
        return;
    }
    else {
        //Go to the last node
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void printNodeElements() {
    struct Node* temp = head;
    cout<<"Forward print implementation: "<<"\n";
    while(temp != NULL) {
        cout<<temp->data<<"\n";
        cout<"\n";
        temp = temp->next;
    }
    cout<<"\n";
}

void reversePrintNodeElements(){
    struct Node* temp = head;
    cout<<"Reverse print implementation: "<<"\n";
    if(temp == NULL) {
        return;
    }
    //Going to the last node.
    while(temp->next != NULL) {
        temp = temp->next;
    }
    //Traversing backwards using the 'prev' pointer and printing.
    while(temp != NULL) {
        cout<<temp->data;
        cout<<"\n";
        temp = temp->prev;
    }
    cout<<"\n";

}

int main() {
    head = NULL; //Currently, an empty list.
    insertNodeAtHead(2);
    printNodeElements();
    reversePrintNodeElements();
    insertNodeAtHead(5);
    printNodeElements();
    reversePrintNodeElements();
    insertNodeAtHead(9);
    printNodeElements();
    reversePrintNodeElements();
    insertNodeAtTail(15);
    printNodeElements();
    reversePrintNodeElements();
    return 0;
}
