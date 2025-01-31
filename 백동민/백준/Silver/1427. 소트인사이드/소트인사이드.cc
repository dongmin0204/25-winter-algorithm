#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;
    for(int i = 0; i < input.size()-1; i++){
        for(int j = i+1; j < input.size(); j++){
            if(input[i] < input[j]){
                swap(input[i],input[j]);
            }
        }
    }
    cout << input << '\n';
    return 0;
}