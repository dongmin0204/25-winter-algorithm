#include <bits/stdc++.h>
using namespace std;

int n, m;
int code[11];


void bt(int level){ //현재 레벨
    if(level == m){
        for(int i = 0; i < m; i++){
            cout << code[i] << ' ';
        }
        cout << "\n";
    }
    int start = 1; //시작지점
    if(level != 0){
        start = code[level-1] + 1; //증가하는 다음 수가 올 범위 (1다음은 2~ n까지) 
    }
    for(int i = start; i <= n; i++){
        code[level] = i; //이번 레벨에서 수 정함
        bt(level+1);
    }
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m; /*1~n까지 중복없이 m개 고르는 오름차순 수열*/
    bt(0);

    return 0;
}