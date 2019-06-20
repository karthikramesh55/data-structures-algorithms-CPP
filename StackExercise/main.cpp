#include <iostream>
#include <cstdlib>

#define MAX_ARRAY_SIZE 105

using namespace std;

int a[MAX_ARRAY_SIZE];
int top = -1; //Indexing variable;

void push(int x) {
    if(top == MAX_ARRAY_SIZE - 1) {
        cout<<"Error: Stack overflow";
        return;
    }
    else {
        top = top+1; //top++
        a[top] = x;
    }

}

void pop() {
    if(top == -1) {
        cout<<"Error: Stack is empty";
        return;
    }
    else {
        top = top-1;
    }
}

int topOfStack() {
    return a[top];
}

void printStack() {
    cout<<"The stack is: ";
    for(int i = 0; i <= top; i++) {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}


int main() {
    cout<<"Array Implementation of Stack"<<"\n";
    push(2);
    printStack();
    push(4);
    printStack();
    push(6);
    printStack();
    pop();
    printStack();
    push(8);
    printStack();
    return 0;
}
