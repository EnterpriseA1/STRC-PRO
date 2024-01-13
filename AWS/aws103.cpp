#include <bits/stdc++.h>

using namespace std;

int main(){
    string h;
    cin>>h;
    stringstream extract_string(h);
    string temp_h,temp_m;
    char x;
    int hour = 0,min = 0;
    extract_string >> hour >> x >> min;
    hour*=60;
    int input_time = hour+min;
    if (input_time >= 430 && input_time <= 570){
        cout<<"Y"<<'\n';
    }
    else{
        cout<<"N"<<'\n';
    }

}