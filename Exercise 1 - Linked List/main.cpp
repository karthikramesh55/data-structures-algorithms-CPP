#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node* next_address;
};

struct Node* head_node; //The parent node of the linked list with an initial value of NULL

void insertNode(int);
void printNodeElements();

void insertNode(int x) {
    struct Node* temp = new Node(); //Alternatively, struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    (*temp).data = x; //Alternatively, temp -> data = x;
    (*temp).next_address = head_node; //This statement covers the case even when the head_node is NULL. So the following 3 code sentences not required.
    //(*temp).next_address = NULL; //Alternatively, temp -> next_address = NULL;
    //if(head_node != NULL) {
    //    (*temp).next_address = head_node; //Alternatively, temp -> next_address = head_node;
    //}
    head_node = temp;
}

void printNodeElements() {
    struct Node* temp = head_node;
    cout<<"The linked list is: "<<"\n";
    while(temp != NULL) {
        cout<<(*temp).data<<"\n";
        cout<<"|"<<"\n";
        temp = (*temp).next_address; //Traversal logic to traverse through the consecutive list elements. The (temp = temp -> next_address) works too.
    }
    cout<<"__";
    cout<<"\n";
}
int main()
{
    head_node = NULL; //Initial value of the parent node 'head_node' is NULL;
    int n, input;
    cout<<"How many numbers do you want to insert into the linked list"<<"\n";
    cin>>n;
    for(int i = 0; i < n; i++) {
        cout<<"Enter the number "<<i+1<<": ";
        cin>>input;
        insertNode(input);
        printNodeElements();
        cout<<"\n";
    }
    return 0;
}
