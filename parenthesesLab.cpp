#include <bits/stdc++.h>

using namespace std;

bool isMatching(char a, char b){
    return (a == '(' && b == ')')||
           (a == '{' && b == '}')||
           (a == '[' && b == ']')||
           (a == '<' && b == '>');
}

int main(){
    string input;
    getline(cin, input);
    stack<char>s;
    int match,unmatch = 0;
    for (int i = 0 ; i < input.size() ; i++){
        if (input[i] == '(' || input[i] == '{' || input[i] == '[' || input[i] == '<'){
            s.push(input[i]);
        }
        else if (input[i] == ')' || input[i] == '}' || input[i] == ']' || input[i] == '>'){
            if (!s.empty() && isMatching(s.top(),input[i])){
                match++;
                s.pop();
            }
            else if (s.empty()){
                unmatch++;
            }
            else{
                s.pop();
                unmatch++;
            }
        }
    }
    cout << match << " matching pair"<<endl << unmatch + s.size() << " unmatched"<<endl;
}
