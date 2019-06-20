#include <iostream>
#include <cstdlib>
#include <stack>
#include <string>
#include "stdio.h"

using namespace std;

int performCalculation(char op, int operand1, int operand2) {
    //int result;
    if(op == '+') {
        return operand1 + operand2;
    }
    else if(op == '-') {
        return operand1 - operand2;
    }
    else if(op == '*') {
        return operand1 * operand2;
    }
    else if(op == '/') {
        return operand1 / operand2;
    }
    else {
        cout<<"Unexpected Error \n";
        return -1;
    }
}

bool isOperator(char op) {
    if(op == '+' || op == '-' || op == '*' || op == '/')
		return true;
    else {
        return false;
    }
}

bool isValidNumericDigit(char operandCheck) {
    if(operandCheck >= '0' && operandCheck <= '9') {
        return true;
    }
	return false;
}

int evaluatePrefix(string x) {
    stack<int> S;
    for(int i = x.length() - 1; i >= 0; i--) {
        if(x[i] == ' ' || x[i] == ',') {
            continue;
        }
        //Push the operand into the stack
        if(isValidNumericDigit(x[i])) {
            S.push(x[i] - '0');
        }
        else {
            //Operator found
            //Pop 2 elements from the stack
            int operand2 = S.top();
            S.pop();
            int operand1 = S.top();
            S.pop();
            int result = performCalculation(x[i], operand1, operand2);
            //Push the result back into the stack
            S.push(result);
        }
    }
    return S.top();
}


int evaluatePostfix(string x) {
    stack<int> S;
    for(int i = 0; i < x.length(); i++) {
        if(x[i] == ' ' || x[i] == ',') {
            continue;
        }
        else if(isOperator(x[i])) {
            //Pop 2 operands
            int operand2 = S.top();
            S.pop();
            int operand1 = S.top();
            S.pop();
            int result = performCalculation(x[i], operand1, operand2);
            //Perform the calculation and push the result back into the stack
            S.push(result);
        }
        else if(isValidNumericDigit(x[i])) {
            //Extract the numeric operand from the string
            //Keep incrementing as long as you get a numeric digit
            int operand = 0;
            while((i < x.length()) && (isValidNumericDigit(x[i]))) {
                // For a number with more than one digits, as we are scanning from left to right.
				// Every time , we get a digit towards right, we can multiply current total in operand by 10
				// and add the new digit.
				// The char in C++ evaluates to the decimal equivalent. This '0' is equal to 48.
				// lets say expression[i] = '2' which evaluates to 50
                //so (expression[i] - '0') in this case will be (50 - 48) = 2
                operand = (operand*10) + (x[i] - '0');
                i++;
            }
            // Finally, you will come out of while loop with i set to a non-numeric character or end of string
			// decrement i because it will be incremented in increment section of loop once again.
			// We do not want to skip the non-numeric character by incrementing i twice.
			i--;
			S.push(operand);
        }
    }
    // If expression is in correct format, Stack will finally have one element. This will be the output.
	return S.top();
}

int main() {
    cout<<"Evaluating postfix operations using stacks";
    string sampleStringPostfix, sampleStringPrefix;
    cout<<"\n";
    cout<<"Enter the postfix expression: ";
    getline(cin, sampleStringPostfix);
    cout<<"\n";
    int resultEvaluation = evaluatePostfix(sampleStringPostfix);
    cout<<"The evaluated postfix expression output is: "<<resultEvaluation;
    cout<<"\n";
    cout<<"Enter the prefix expression: ";
    getline(cin, sampleStringPrefix);
    cout<<"\n";
    int resultEvaluation2 = evaluatePrefix(sampleStringPrefix);
    cout<<"The evaluated prefix expression output is: "<<resultEvaluation2;
    cout<<"\n";
    return 0;
}
