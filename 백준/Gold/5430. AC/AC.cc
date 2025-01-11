#include <bits/stdc++.h>
using namespace std;

deque<int> dq;

int mode = 1; //정방향 역방향이면 음수 ㄱㄱ

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string cmd;
    string buff;
    string num;

    int T,n;
    cin >> T;
    while(T--){
        mode = 1;
        dq.clear();
        cin >> cmd;
        cin >> n;
        cin >> buff;
        
        buff = buff.substr(1,buff.size()-2);
        stringstream sstream(buff);
        while(getline(sstream,num,',')){
            dq.push_back(stoi(num));
        }

        bool eFlag = false;

        for(auto it : cmd){
            if(it == 'R'){
                mode = -mode;
            }
            else{
                if(dq.empty()){
                    cout << "error\n";
                    eFlag = true;
                    break; // 현재 테스트 케이스 처리 중단
                }
                if(mode == 1){
                    dq.pop_front();
                }
                else{
                    dq.pop_back();
                }
            }
        }

        if (eFlag) {
            continue;
        }
        

        cout << "[";
        if (mode == 1) { // 정방향 출력
            for (int i = 0; i < (int)dq.size(); i++) {
                cout << dq[i];
                if (i < (int)dq.size() - 1) cout << ",";
            }
        } 
        else {  // 역방향 출력
            for (int i = dq.size() - 1; i >= 0; i--) {
                cout << dq[i];
                if (i > 0) cout << ",";
            }   
        }
        cout << "]\n";
    }

    return 0;
}