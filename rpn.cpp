#include <bits/stdc++.h>
using namespace std;

int precedence(string x) {
    const string op[4][2] = {
        {"+", "-"},
        {"*", "/"},
        {"^", ""},
        {"(", ")"}
    };
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            if (x == op[i][j]) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    string input;
    getline(cin, input);
    vector<string> tokens;
    stack<string> rpnForm;
    stack<int> numStack;
    string numMerge = "";

    for (int i = 0; i < input.size(); i++) {
        if (isdigit(input[i])) {
            numMerge += input[i];
        } else {
            if (!numMerge.empty()) {
                tokens.push_back(numMerge);
                numMerge = "";
            }
            
            if (!isspace(input[i])) { 
                string currentOp = string(1, input[i]);

                if (rpnForm.empty() || currentOp == "(") {
                    rpnForm.push(currentOp);
                } 
                else if (currentOp == ")") {
                    while (!rpnForm.empty() && rpnForm.top() != "(") {
                        tokens.push_back(rpnForm.top());
                        rpnForm.pop();
                    }
                    rpnForm.pop();
                } 
                else {
                    int precedenceInput = precedence(currentOp);
                    while (!rpnForm.empty() && precedenceInput <= precedence(rpnForm.top()) && rpnForm.top() != "(") {
                        tokens.push_back(rpnForm.top());
                        rpnForm.pop();
                    }
                    rpnForm.push(currentOp);
                }
            }
        }
}

    if (!numMerge.empty()) {
        tokens.push_back(numMerge);
    }
    while (!rpnForm.empty()) {
        tokens.push_back(rpnForm.top());
        rpnForm.pop();
    }
    cout << "RPN : " << "";
    for (auto i : tokens) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < tokens.size(); i++) {
        int firstValue = 0, secondValue = 0;
        if (tokens[i] == "+") {
            firstValue = numStack.top();
            numStack.pop();
            secondValue = numStack.top();
            numStack.pop();
            numStack.push(secondValue + firstValue);
        }
        else if (tokens[i] == "-") {
            firstValue = numStack.top();
            numStack.pop();
            secondValue = numStack.top();
            numStack.pop();
            numStack.push(secondValue - firstValue);
        }
        else if (tokens[i] == "*") {
            firstValue = numStack.top();
            numStack.pop();
            secondValue = numStack.top();
            numStack.pop();
            numStack.push(secondValue * firstValue);
        }
        else if (tokens[i] == "/") {
            firstValue = numStack.top();
            numStack.pop();
            secondValue = numStack.top();
            numStack.pop();
            numStack.push(secondValue / firstValue);
        }
        else{
            numStack.push(stoi(tokens[i]));
        }
    }
    cout << "Result : " <<numStack.top() << endl;
    return 0;
}
