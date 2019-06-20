#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node* next_address;
};


struct Node* insertNodeElement(struct Node* head, int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*)); //Alternatively,  | Node* temp = new Node(); |
    temp->data = x;
    temp->next_address = head;
    head = temp;
    return head;
}

void printNodeElements(struct Node* head) {
    if(head == NULL) {
        cout<<"_"<<"\n";
        //cout<<"Null address point has been reached!";
        cout<<"\n";
        return;
    }
    else {
        cout<<head->data<<"\n";
        cout<<"|"<<"\n";
        printNodeElements(head->next_address); //recursive call
    }
}

void reverseprintNodeElements(struct Node* head) {
    if(head == NULL ){
        return;
    }
    else {
        reverseprintNodeElements(head->next_address);
        cout<<head->data<<"\n";
        cout<<"|"<<"\n";
    }
}

int main() {
    struct Node* head = NULL;
    int n, input;
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
    cout<<"The reversed version of the above linked list structure is: "<<"\n";
    reverseprintNodeElements(head);
    cout<<"Reversed!!"
    return 0;
}
