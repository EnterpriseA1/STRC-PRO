#include <bits/stdc++.h>
using namespace std;

bool isMatching(char a, char b){
    return (a == '(' && b == ')') ||
           (a == '{' && b == '}') ||
           (a == '[' && b == ']') ||
           (a == '<' && b == '>');
}

int main() {
    stack <string> str;
    string input;
    getline(cin,input);
    int match = 0;
    bool isClosingBracketFrontal = false;
    for (int i = 0 ; i < input.size() - 1 && !isClosingBracketFrontal ;i++){
        if (input[i] == '<' && input[i+1] == '<'){
            str.push("<<");
            i++;
        }
        else if (input[i] == '>' && input[i+1] == '>'){
            if (!str.empty() && str.top() == "<<"){
                str.pop();
                match++;
                i++;
            }
            else{
                if (!str.empty()){
                    str.pop();
                }
            }
            
        }
        else if (input[i] == '(' || input[i] == '[' || input[i] ==  '{' || input[i] == '<' ){
            str.push(string(1,input[i]));
        }
        else if (input[i] == ')' || input[i] == ']' || input[i] ==  '}' || input[i] == '>' ){
            if (!str.empty() && isMatching(str.top()[0],input[i])){
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
