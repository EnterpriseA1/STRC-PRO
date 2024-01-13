#include <bits/stdc++.h>

using namespace std;
int main(){
    int n;
    string ans,chc;
    cin>>ans>>n;
    for (int i = 0;i < n;i++){
        cin>>chc;
        int score = 0;
        for (int j = 0 ;j < 20;j++){
            if (ans[j] == chc[j]){
                if (j < 15){
                    score++;
                }
                else if (j < 18){
                    score+=2;
                }
                else{
                    score+=3;
                }
            }
        }
        cout<<"std "<<i+1<<" => "<<score<<'\n';
    }


}