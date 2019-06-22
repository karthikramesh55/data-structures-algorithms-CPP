#include <iostream>
#include <cstdlib>
#include <stack>
#include "stdio.h"

using namespace std;

bool isOperator(char opCheck) {
    if(opCheck == '+' || opCheck == '-' || opCheck == '*' || opCheck == '/' || opCheck == '^') {
        return true;
    }
    else {
        return false;
    }
}

bool isOperand(char opndCheck) {
    if((opndCheck >= 'a' && opndCheck <= 'z') || (opndCheck >= 'A' && opndCheck <= 'Z')) {
        return true;
    }
    else {
        return false;
    }
}

int getOperatorWeight(char op) {
    if(op == '^') {
        return 3;
    }
    else if(op == '*' || op == '/') {
        return 2;
    }
    else if(op == '+' || op == '-') {
        return 1;
    }
    else {
        return -1;
    }
}

string infixToPostfix(string expression) {
    stack<char> S;
    string postfix_string;
    for(int i = 0; i < expression.length(); i++) {
        if(expression[i] == ' ' || expression[i] == ',') {
            continue;
        }
        else if(expression[i] == '(') {
            S.push(expression[i]);
        }
        else if(expression[i] == ')') {
            while(!S.empty() && S.top() == '(') {
                postfix_string = postfix_string + S.top();
                S.pop();
            }
            S.pop();
        }
        else if(isOperand(expression[i])) {
            postfix_string = postfix_string + expression[i];
        }
        else if(isOperator(expression[i])) {
            while(!S.empty() && (getOperatorWeight(S.top()) >= getOperatorWeight(expression[i]))) {
                char C = S.top();
                S.pop();
                postfix_string = postfix_string + C;
            }
            S.push(expression[i]);
        }
    }
    //Popping the remaining elements from the stack
    while(!S.empty()) {
        char C = S.top();
        S.pop();
        postfix_string = postfix_string + C;
    }
    return postfix_string;
}


int main() {
    cout<<"Infix to Postfix Expression Evaluation";
    string infixExpressionInput = "a + b * ( c ^ d - e ) ^ ( f + g * h ) - i";
    string postfixOutput = infixToPostfix(infixExpressionInput);
    cout<<"The evaluated postfix output is: "<<"\n";
    cout<<postfixOutput;
    cout<<"\n";
    return 0;
}
