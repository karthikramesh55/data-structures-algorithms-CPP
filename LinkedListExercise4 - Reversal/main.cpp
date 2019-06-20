#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node* next_address;
};

//struct Node* head; //The head node has been declared in the main() block to perform the reversal and passed by value

struct Node* insertNodeElement(struct Node, int);
void printNodeElements(struct Node);
struct Node* nodeStructureReversal(struct Node);

struct Node* insertNodeElement(struct Node* head, int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = x;
    temp->next_address = head;
    head = temp;
    return head;
}

void printNodeElements(struct Node* head) {
    struct Node* temp1 = head;
    cout<<"The linked list structure is: "<<"\n";
    while(temp1 != NULL) {
        cout<<temp1->data<<"\n";
        cout<<"|"<<"\n";
        temp1 = temp1->next_address;
    }
    cout<<"_";
    cout<<"\n";
}

struct Node* nodeStructureReversal(struct Node* head) {
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;
    //Traversal logic
    while(current != NULL) {
        next = current->next_address;
        current->next_address = prev;
        prev = current;
        current = next;
    }
    head = prev; //When the traversal reaches the ancient NULL on the far-right end, the head node is updated with the previous node address.
    return head;
}

int main()
{
    struct Node* head = NULL;
    int n, input;
    char rev_choice;
    cout<<"Enter the number of elements that you want to input: ";
    cin>>n;
    cout<<"\n";
    for(int i = 0; i < n; i++) {
        cout<<"Enter element "<<i+1<<" : ";
        cin>>input;
        head = insertNodeElement(head, input);
        printNodeElements(head);
    }
    cout<<"Would you like to see the reversal of the linked list? (Y/N): ";
    cin>>rev_choice;
    if(rev_choice == 'Y') {
        head = nodeStructureReversal(head);
        printNodeElements(head);
    }
    else {
        cout<<"No problem, Dr. Karthik!";
    }
    return 0;
}
