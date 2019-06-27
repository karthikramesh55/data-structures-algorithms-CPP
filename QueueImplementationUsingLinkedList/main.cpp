/*#include <iostream>
#include <cstdlib>
#include "stdio.h"

using namespace std;

//Implementation of queues using linked list (FIFO structure with operations involving O(1) or constant time complexity)

struct Node {
    int data;
    Node* next_address;
};

struct Node* fore = NULL;
struct Node* rear = NULL;

int frontOfQueue() {
    if(fore == NULL) {
        cout<<"The queue is empty";
        cout<<"\n";
        return 0;
    }
    else {
        return fore->data;
    }
}

void enqueue(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = x;
    temp->next_address = NULL;
    if(fore == NULL && rear == NULL) {
        fore = rear = temp;
        return;
    }
    else {
        rear->next_address = temp;
        rear = temp;
    }
}

void dequeue() {
    struct Node* temp = fore;
    if(fore == NULL) {
        return;
    }
    else if(fore == rear) {
        fore = rear = NULL;
    }
    else {
        fore = fore->next_address;
    }
    free(temp); //Releasing the dynamic allocation to implement the dequeuing functionality
}

void printQueue() {
    struct Node* temp = fore;
    cout<<"The queue is given by: "<<"\n";
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next_address;
    }
    cout<<"\n";
}

int main() {
    enqueue(2);
    printQueue();
    enqueue(4);
    printQueue();
    enqueue(6);
    printQueue();
    dequeue();
    printQueue();
    return 0;
}
*/

#include <iostream>
#include <cstdlib>
#include "stdio.h"

using namespace std;

struct Node {
    int data;
    Node* next_address;
};

struct Node* fore = NULL;
struct Node* rear = NULL;

int frontOfQueue() {
    if(fore == NULL) {
        cout<<"The queue is empty!";
        return 0;
    }
    else {
        return fore->data;
    }
}

void enqueue(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = x;
    temp->next_address = NULL;
    if(fore == NULL && rear == NULL) {
        fore = rear = temp;
        return;
    }
    else {
        rear->next_address = temp;
        rear = temp;
    }
}

void dequeue() {
    struct Node* temp = fore;
    if(fore == NULL || rear == NULL) {
        cout<<"The queue is empty";
        return;
    }
    else if(fore == rear) {
        fore = rear = NULL;
    }
    else {
        fore = fore->next_address;
    }
    free(temp); //delete(temp) alternatively!
}

void printQueue() {
    struct Node* temp = fore;
    cout<<"The queue structure is: "<<"\n";
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next_address;
    }
    cout<<"\n";
}


int main() {
    enqueue(2);
    printQueue();
    enqueue(4);
    printQueue();
    enqueue(5);
    printQueue();
    dequeue();
    printQueue();
    dequeue();
    printQueue();
    return 0;
}


