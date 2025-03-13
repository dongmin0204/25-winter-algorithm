#include <bits/stdc++.h>
using namespace std;

set<int> a;
set<int> b;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int s1,s2;
    cin >> s1 >> s2;
    int input;

    for(int i = 0; i < s1; i++){
        cin >> input;
        a.emplace(input);
    }//이진탐색트리에 삽입

    for(int i = 0; i < s2; i++){
        cin >> input;
        b.emplace(input);
    }

    int cnt = 0; //차집합 구하기

    //a-b
    for(auto &x : a){
        if(b.find(x) == b.end()) {
            cnt++;
        }
    }

    //b-a
    for(auto &x : b){
        if(a.find(x) == a.end()) {
            cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}