#include <bits/stdc++.h>
using namespace std;

bool isMatching(string a, string b){
    return (a == "(" && b == ")") ||
           (a == "{" && b == "}") ||
           (a == "[" && b == "]") ||
           (a == "<" && b == ">") ||
           (a == "<<" && b == ">>");
}

int main() {
    stack <string> str;
    string input;
    getline(cin,input);
    int match = 0;
    bool isClosingBracketFrontal = false;
    for (int i = 0 ; i < input.size() && !isClosingBracketFrontal ;i++){
        bool foundDouble = false;
        if (i < input.size() - 1){
            if (input[i] == '<' && input[i+1] == '<'){
                str.push("<<");
                i++;
                foundDouble = true;
            }
            if (input[i] == '>' && input[i+1] == '>'){
                if (!str.empty() && str.top() == "<<"){
                    str.pop();
                    match++;
                    i++;
                    foundDouble = true;
                }
                else{
                    if (!str.empty()){
                        str.pop();
                    }
                }
                
            }
        }
        if (input[i] == '(' || input[i] == '[' || input[i] ==  '{' || input[i] == '<'  && !foundDouble){
            str.push(string(1,input[i]));
        }
        if (input[i] == ')' || input[i] == ']' || input[i] ==  '}' || input[i] == '>' && !foundDouble){
            if (!str.empty() && isMatching(str.top(),string(1,input[i]))){
                str.pop();
                match++;
            }
            else{
                if (!str.empty()){
                    str.pop();
                }
                else{
                    isClosingBracketFrontal = true;
                }
            }
        }

       
    }
    if (str.empty() && !isClosingBracketFrontal){
        cout << match << " matched" << endl;
    }
    else{
        cout << "Not matched" << endl << match << " matched" << endl;
    }
}
