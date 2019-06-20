#include <iostream>
#include <cstdlib>
#include <stack>
#include <string>
#include "stdio.h"

using namespace std;

bool arePairs(char opening, char closing) {
    if(opening == '(' && closing == ')') {
        return true;
    }
    else if(opening == '{' && closing == '}') {
        return true;
    }
    else if(opening == '[' && closing == ']') {
        return true;
    }
    return false;
}

bool checkBalancedParentheses (string x) {
    stack<char> S;
    for(int i = 0; i < x.length(); i++) {
        if(x[i] == '(' || x[i] == '{' || x[i] == '[') {
            S.push(x[i]);
        }
        else if(x[i] == ')' || x[i] == '}' || x[i] == ']') {
            if(S.empty() || !arePairs(S.top(), x[i])) {
                return false;
            }
            else {
                S.pop();
            }
        }

    }
    return S.empty()?true:false;
}

int main() {
    cout<<"Checking for balanced parentheses using stacks"<<"\n";
    string sampleString;
    cout<<"Enter a string: ";
    cin>>sampleString;
    cout<<"\n";
    if(checkBalancedParentheses(sampleString)) {
        cout<<"Balanced!";
    }
    else {
        cout<<"Not balanced";
    }
    return 0;
}
