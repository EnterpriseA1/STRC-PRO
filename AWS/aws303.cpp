#include <bits/stdc++.h>

using namespace std;
int main(){
    int n,m;
    string ans,chc;
    cin>>n>>ans>>m;
    for (int i = 0;i < m;i++){
        cin>>chc;
        int score = 0;
        for (int j = 0 ;j < n;j++){
            if (ans[j] == chc[j]){
                score++;
            }
        }
        cout<<"std "<<i+1<<" => "<<score<<'\n';
    }
}