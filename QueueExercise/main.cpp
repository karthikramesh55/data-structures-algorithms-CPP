#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX_SIZE 100

class Queue { /*Circular Array Implementation*/

private:
    int testArray[MAX_SIZE];
    int frontIndex, rearIndex;

public:
    Queue() { //Constructor - setting front and rear of the queue as -1
        frontIndex = -1;
        rearIndex = -1;
    }
    bool isEmpty() {
        return frontIndex == -1 && rearIndex == -1;
    }

    bool isFull() {
        return (rearIndex+1)%(MAX_SIZE) == frontIndex ? true : false;
    }

    int frontElement() {
        if(isEmpty()) {
            cout<<"Error: Queue is empty! No elements yet";
            return -1;
        }
        else {
            return testArray[frontIndex];
        }
    }

    void enqueue(int x) {
        cout<<"Enqueue request!";
        if(isEmpty()) {
            frontIndex = rearIndex = 0;
        }
        if(isFull()) {
            cout<<"The queue is full";
            return;
        }
        else {
            rearIndex = (rearIndex+1)%(MAX_SIZE);
        }
        testArray[rearIndex] = x;
    }

    void dequeue() {
        cout<<"Dequeue request!";
        if(isEmpty()) {
            cout<<"Error: Queue is empty!";
            return;
        }
        else if(frontIndex == rearIndex) {
            rearIndex = frontIndex = -1;
        }
        else {
            frontIndex = (frontIndex+1)%(MAX_SIZE);
        }
    }

    void printQueue() {
        int numElementsQueue = (rearIndex - frontIndex + MAX_SIZE)%(MAX_SIZE) + 1; //Calculating the total number of elements in the queue
        cout<<"The resultant queue is: \n";
        for(int i = 0; i < numElementsQueue; i++) {
            int index = (frontIndex + i)%MAX_SIZE; //The index of the element during traversal (circular fashion) from the front
            cout<<testArray[index]<<" ";
        }
        cout<<"\n";
    }

};

int main() {
    Queue Q;
    Q.enqueue(1);  Q.printQueue();
    Q.enqueue(2);  Q.printQueue();
    Q.enqueue(3);  Q.printQueue();
    Q.dequeue();   Q.printQueue();
    Q.enqueue(8);  Q.printQueue();
    return 0;
}
