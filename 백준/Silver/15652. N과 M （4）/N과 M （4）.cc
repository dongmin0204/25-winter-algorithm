#include <bits/stdc++.h>
using namespace std;

int n, m;
int code[11];


void bt(int level, int start){ //현재 레벨, 시작
    if(level == m){
        for(int i = 0; i < m; i++){
            cout << code[i] << ' ';
        }
        cout << "\n";
        return;
    }

    for(int i = start; i <= n; i++){
        code[level] = i; //이번 레벨에서 수 정함
        bt(level+1, i);
    }
}


int main(void){

    cin >> n >> m; /*1~n까지 중복있게 m개 고르는 비내림차순 수열*/
    bt(0,1);

    return 0;
}