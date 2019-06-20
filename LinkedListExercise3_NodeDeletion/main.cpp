#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node* next_address;
};

struct Node* head; //The head node

void insertNodeElement(int);
void printNodeElements();
void deleteNode(int);

void insertNodeElement(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    (*temp).data = x;
    (*temp).next_address = head;
    head = temp;
}

void printNodeElements() {
    struct Node* temp1 = head;
    cout<<"The linked list structure is: "<<"\n";
    while(temp1 != NULL) {
        cout<<(*temp1).data<<"\n";
        cout<<"|"<<"\n";
        temp1 = (*temp1).next_address;
    }
    cout<<"_";
    cout<<"\n";
}

void deleteNode(int position) {
    struct Node* temp2 = head;
    if(position == 1) {
        head = (*temp2).next_address; //The head node points to the second node (or the node after the node-to-be-deleted)
        delete(temp2);
        return;
    }
    for(int i = 0; i < position-2; i++) { // Traversing to the (N-1)th node
        temp2 = (*temp2).next_address; //temp2 points to the (N-1)th node.
    }
    struct Node* temp3 = (*temp2).next_address; //Nth node
    (*temp2).next_address = (*temp3).next_address; //(N+1)th node
    delete(temp3);
}

int main()
{
    head = NULL;
    int n, input, position_del;
    char del_choice;
    cout<<"Enter the number of elements that you want to insert into the linked list structure: ";
    cin>>n;
    cout<<"\n";
    for(int i = 0; i < n; i++) {
        cout<<"Enter element "<<i+1<<" : ";
        cin>>input;
        insertNodeElement(input);
        printNodeElements();
    }
    cout<<"Do you want to delete any node? (Y/N): ";
    cin>>del_choice;
    if(del_choice == 'Y') {
        cout<<"Enter the position of the node to be deleted: ";
        cin>>position_del;
        deleteNode(position_del);
        printNodeElements();
    }
    else {
        cout<<"Alrighty! Have a great day!";
    }
    return 0;
}
