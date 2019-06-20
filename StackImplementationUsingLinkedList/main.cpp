#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node* next_address;
};

struct Node* top = NULL; //Initialization of the stack as an empty structure

void pushElement(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next_address = top;
    top = temp;
}

void popElement() {
    struct Node* temp1;
    if(top == NULL) {
        return;
    }
    else {
        temp1 = top;
        top = top->next_address;
        delete temp1; //free(temp1)
    }
}

void printStack() {
    cout<<"The stack is: ";
    struct Node* temp2 = top;
    while(temp2 != NULL) {
        cout<<temp2->data<<" ";
        temp2 = temp2->next_address;
    }
    cout<<"\n";
}



int main() {
    pushElement(2);
    printStack();
    pushElement(4);
    printStack();
    pushElement(6);
    printStack();
    popElement();
    printStack();
    pushElement(8);
    printStack();
    return 0;
}

