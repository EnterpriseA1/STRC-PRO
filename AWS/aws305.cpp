#include <bits/stdc++.h>

using namespace std;

int main(){
    int row,col;
    cin>>row>>col;
    vector<vector<int>> arr;
    for (int i = 0 ; i < row ; i++){
        vector<int>temp;
        for (int j = 0 ; j < col ; j++){
            int num;
            cin>>num;
            temp.push_back(num);
            if (j == col - 1){
                temp.push_back(0);
            }
        }
        if (i != row - 1){
            arr.push_back(temp);
        }
        else{
            arr.push_back(temp);
            vector<int>zero;
            for (int j = 0 ; j < col + 1 ; j++){
                zero.push_back(0);
            }
            arr.push_back(zero);
        }
    }
    int n_row = arr.size();
    int n_col = arr[0].size();
    for (int i = 0 ; i < row ; i++){
        for (int j = 0 ; j < col ; j++){
            arr[i][col] += arr[i][j];
            arr[row][j] += arr[i][j];
        }
        arr[row][col] += arr[i][col];
    }
    for (int i = 0 ; i < n_row ; i++){
        for (int j = 0 ; j < n_col ; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
}
