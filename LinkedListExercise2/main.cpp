#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node* next_address;
};

struct Node* head; //global declaration of the head node

void insertNodeElement(int, int);
void printNodeElements();

void insertNodeElement(int x, int position) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    (*temp).data = x; //temp->data = x;
    (*temp).next_address = NULL; //temp->next_address = head;
    if(position == 1) {
        (*temp).next_address = head;
        head = temp;
        return;
    }
    //If position is N, we need to go to the (N-1)th node and modify the linkage addresses to complete the new node insertion.
    //Traversal to reach the position as desired.
    struct Node* temp1 = head;
    for(int i = 0; i < position-2; i++) {
        temp1 = (*temp1).next_address;
    }
    (*temp).next_address = (*temp1).next_address;
    (*temp1).next_address = temp;
}

void printNodeElements() {
    struct Node* temp2 = head;
    cout<<"The linked list structure is: "<<"\n";
    while(temp2 != NULL){
        cout<<(*temp2).data<<"\n";
        cout<<"|"<<"\n";
        temp2 = (*temp2).next_address;
    }
    cout<<"_";
    cout<<"\n";
}

int main()
{
    head = NULL;
    int n, input, pos;
    cout<<"How many numbers do you want to insert into the linked list: ";
    cin>>n;
    cout<<"\n";
    for(int i = 0; i < n; i++) {
        cout<<"Enter element "<<i+1<<": ";
        cin>>input;
        cout<<"Enter the position at which the element must be inserted: ";
        cin>>pos;
        insertNodeElement(input, pos);
        printNodeElements();
    }
    return 0;
}
