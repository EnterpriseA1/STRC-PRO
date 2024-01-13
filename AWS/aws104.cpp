#include <bits/stdc++.h>

using namespace std;

int main(){

    int y;
    double grade;
    char app;
    cin>>y>>grade>>app;
    if (grade >= 3.000){
        cout <<"approved\n";
    }
    else{
        if (y >= 2 && grade >= 2.500 && app =='Y'){
            cout<<"approved";
        }
        else{
            cout<<"not approved\n";
            if (grade < 2.500){
                cout<<"grade < 2.50"<<'\n';
            }
            else if (y < 2){
                cout << "year < 2" << '\n';
            }
            else{
                cout<<"no help"<<'\n';
            }
        }
    }
}