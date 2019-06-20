//#include <iostream>
//#include <stack> //STL for stack
//#include <string>
//#include <cstdlib>
//#include <cstring>
//#include "stdio.h"
//
//using namespace std;
//
//void reverseString(char *c_a, int n) { //*c_a can also be written as c_a[]
//    stack<char> S;
//    for(int i = 0; i < n; i++) {
//        S.push(c_a[i]);
//    }
//    for(int i = 0; i < n; i++) {
//        c_a[i] = S.top();
//        S.pop();
//    }
//}
//
//int main() {
//    char c_a[51];
//    cout<<"Enter the string: ";
//    gets(c_a);
//    //cout<<strlen(c_a);
//    reverseString(c_a, strlen(c_a));
//    cout<<"\n";
//    cout<<"Output string: "<<c_a<<"\n";
//    return 0;
//}

//  Stack - next_addressed list based implemention


#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <cstdlib>
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node* next_address;
};

struct Node* top = NULL;

void push_head(int x) {
  struct Node* temp = new Node();
  temp->data = x;
  temp->next_address = top;
  top = temp;
}

void push_tail(int x) {
  struct Node* temp = top;
  while (temp->next_address != NULL) {
    temp = temp->next_address;
  }
  temp->next_address = new Node; // returns a pointer to the new node
  temp->next_address->data = x;
  temp->next_address->next_address = NULL;
}

void pop_head() {
  struct Node* temp; //no node necessary
  if (top == NULL) {
        return;
  }
  temp = top;
  top = top->next_address;
  free(temp);
}

void pop_tail() {
  struct Node* temp = top;
  struct Node* prev = NULL;
  while (temp->next_address != NULL) {
    prev = temp;
    temp = temp->next_address;
  }
  free(temp);
  prev->next_address = NULL;
}

void print() {
  Node* temp = top;
  while (temp != NULL) {
    cout<<temp->data<<" ";
    temp = temp->next_address;
  }
  printf("\n");
}

void reverseStack() { // Time O(N), Space O(1)
  if (top == NULL) return;
  std::stack<struct Node*> S; //create a stack called S
  Node* temp = top;
  while (temp != NULL) {
    S.push(temp); //LIFO
    temp = temp->next_address;
  }
  temp = S.top(); //now temp is pointing at the last inserted element on the stack or the TOP
  top = temp; // head points at the same element
  S.pop(); //clear up the element from top of the stack
  while(!S.empty()) {
    temp->next_address = S.top(); //point temp to the previous element in the next_addressed list, or the element at the top
    S.pop(); // clear up that element from the stack
    temp = temp->next_address;
  }
  temp->next_address = NULL;
}

int main() {
  push_head(2);
  print(); // output 2
  push_head(6);
  print(); // output 6 2
  push_head(9);
  print(); // output 9 6 2
  pop_head();
  print(); // output 6 2
  push_tail(8);
  print(); // output 6 2 8
  pop_head();
  print(); // output 2 8
  pop_tail();
  push_tail(3);
  print(); // output 2 3
  push_tail(5);
  print(); // output 2 3 5
  pop_tail();
  print(); // output 2 3
  push_head(6);
  push_tail(19);
  push_tail(55);
  print(); // output 6 2 3 19 55
  reverseStack();
  print(); // output 55 19 3 2 6
  return 0;
}

