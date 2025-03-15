#include <bits/stdc++.h>
using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;

    while(T--){
        int k;
        cin >> k;
        multiset<int> bst;
        for(int i = 0; i < k; i++ ){
            char cmd;
            cin >> cmd;

            if(cmd == 'I'){
                int data;
                cin >> data;
                bst.insert(data);
            }
            else{ //cmd == 'D'
                int data;
                cin >> data;
                if(bst.empty()){
                    continue; //비어있으면 명령 무시
                }

                if(data == 1){ //1-> 최대 삭제
                    bst.erase(prev(bst.end()));
                    //set은 이진탐색트리로 정렬되어 있음 -> 오름차순의 마지막 값 반환
                }
                else{ // -1 -> 최소 삭제
                    bst.erase(bst.begin()); //뒤집으면 내림차순의 마지막 값 반환
                }
            }
        }
        if(bst.empty()){
            cout << "EMPTY\n";
        }
        else{  
            cout << *prev(bst.end()) << " " << *bst.begin() << '\n';
        }

    }

    return 0;
}