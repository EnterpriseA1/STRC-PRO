#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>f_num;
    for (int i = 0 ; i < n;i++){
        int value;
        cin>>value;
        f_num.push_back(value);
    }
    cout<<"a) ";
    for (int i = 0; i < 4;i++){
        cout<<f_num[i]<<" ";
    }
    cout<<"\nb) ";
    for (int i = 0 ; i < n;i++){
        if (f_num[i] > f_num[2]){
            cout<<f_num[i]<<" ";
        }
    }
    cout<<"\nc) ";
    for (int i = 0 ; i < n;i++){
        if (f_num[i] > f_num[2]){
            cout<<i<<" ";
        }
    }
    cout<<"\n";
    cout<<"d) ";
    f_num.push_back(f_num[2] + f_num[3]);
    for (int i = 0 ; i < n + 1;i++){
        cout<<f_num[i]<<" ";
    }
    cout<<"\ne) ";
    f_num[3] = (f_num[2] < f_num[4]) ?  f_num[4] - f_num[2] : f_num[2] - f_num[4];
    for (int i = 0 ; i < n + 1;i++){
        cout<<f_num[i]<<" ";
    }
    cout<<"\n";
    int x = (f_num[1] > f_num[5]) ? 2 : 6;
    cout<<"f) " <<x<<"\n";
    int temp = f_num[1];
    f_num[1] = f_num[f_num.size() - 1];
    f_num[f_num.size() - 1] = temp;
    cout<<"g) ";
    for (int i = 0 ; i < n + 1;i++){
        cout<<f_num[i]<<" ";
    }
    cout<<'\n';
    cout<<"h) new=[";
    vector<int> even;
    for (int i = 0 ; i < n+1;i++){
        if (f_num[i] % 2 == 0){
            even.push_back(f_num[i]);
        }
    }
    for (int i = 0 ; i < even.size();i++){
        cout<<even[i];
        if (i != even.size()-1){
            cout<<" ";
        }
    }
    cout<<"]";

    
}