#include <bits/stdc++.h>

using namespace std;

int main(){
    string n;
    cin>>n;
    for (int i = 0 ; i < n.size(); i++){
        
        switch (n[i])
            {
            case '1': cout<<"One";break;
            case '2': cout<<"Two";break;
            case '3': cout<<"Three";break;
            case '4': cout<<"Four";break;
            case '5': cout<<"Five";break;
            case '6': cout<<"Six";break;
            case '7': cout<<"Seven";break;
            case '8': cout<<"Eight";break;
            case '9': cout<<"Nine";break;
            case '0': cout<<"Zero";break;

            default:
                break;
            }
            if (i != n.size() - 1){
                cout<<" ";
            }
        }
}