#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>num;
    for (int i=0 ; i<n ; i++){
        int num_;
        cin>>num_;
        num.push_back(num_);
    }
    for (int i=n-1;i>=0;i--){
        cout<<num[i]<<" ";
    }
}