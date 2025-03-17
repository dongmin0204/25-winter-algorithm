#include <bits/stdc++.h>
using namespace std;

// 문제 번호, 난이도

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int size;
    cin >> size;

    multiset<int> listBylevel[103];
    int prLevel[100003];//k: 문제, v : 난이도

    for(int i = 0; i < size; i++){
        int P,L;
        cin >> P >> L;
        listBylevel[L].insert(P);
        prLevel[P] = L;
    }

    int c;
    cin >> c;
    while(c--){
        string cmd;
        cin >> cmd;
        if(cmd == "recommend"){
            int input;
            cin >> input;
            if (input == 1) {
                for (int i = 100; 0 <= i; i--) {
                  if (listBylevel[i].empty()) continue;
                  cout << *(prev(listBylevel[i].end())) << '\n'; //prev은 지금 난이도 순으로 정렬된 값중에 가장 번호 큰 거 출력
                  break;
                }
            } 
            else {
                for (int i = 0; i < 101; i++) {
                  if (listBylevel[i].empty()) continue;
                  cout << *listBylevel[i].begin() << '\n';// 정렬된 값중에 가장 번호 작은 거 출력
                  break;
                }
            }
        }
        else if(cmd == "solved"){
            int target;
            cin >> target;
            listBylevel[prLevel[target]].erase(target); //문제 번호 -> 난이도 -> 난이도 중 target지우기

        }
        else if (cmd == "add"){
            int P,L;
            cin >> P >> L;
            listBylevel[L].insert(P);
            prLevel[P] = L;
        }
    }
    
    

    return 0;
}