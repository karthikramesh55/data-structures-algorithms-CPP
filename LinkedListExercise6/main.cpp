#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node* next_address;
};

//struct Node* head;

struct Node* insertNodeElement(struct Node* head, int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = x;
    temp->next_address = head;
    head = temp;
    return head;
};

void printNodeElements(struct Node* head) {
    if(head==NULL) {
        cout<<"_"<<"\n";
        return;
    }
    else {
        cout<<head->data<<"\n";
        cout<<"|"<<"\n";
        printNodeElements(head->next_address);
    }
}

struct Node* reverseLinkedList(struct Node* head) {
    //if(head == NULL) {
    //    return head;
    //}
    if(head->next_address == NULL) {
        return head;
    }
    else {
        struct Node* h = reverseLinkedList(head->next_address);
        head->next_address->next_address = head;
        head->next_address = NULL;
        //struct Node* q = p->next_address;
        //q->next_address = p;
        //p->next_address = NULL;
        return h;
        //cout<<"|"<<"\n";
        //cout<<p->data<<"\n";
        //cout<<"\n";
        //cout<<p->data<<"\n";
    }
}

int main() {
    struct Node* head = NULL;
    int n, input;
    char choice;
    cout<<"How many elements do you want to enter into the linked list structure: ";
    cin>>n;
    cout<<"\n";
    for(int i = 0; i < n; i++) {
        cout<<"Enter element "<<i+1<<" : ";
        cin>>input;
        head = insertNodeElement(head, input);
        printNodeElements(head);
    }
    cout<<"\n";
    cout<<"Do you want to reverse the linked list using recursion? (Y/N): ";
    cin>>choice;
    if(choice == 'Y') {
        head = reverseLinkedList(head);
        printNodeElements(head);
    }
    else {
        cout<<"Kein problem, Herr Karthik!";
    }
    return 0;
}
