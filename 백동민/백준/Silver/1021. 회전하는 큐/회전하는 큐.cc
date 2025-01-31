#include <bits/stdc++.h>
using namespace std;

deque<int> dq;

inline int pop(){
    int val = dq.front();
    dq.pop_front();

    return val;
}

inline void lMove(){
    int val = pop();
    dq.push_back(val);
}
inline void rMove(){
    int val = dq.back();
    dq.pop_back();
    dq.push_front(val);

}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n>>m;

    vector<int> vec(m);
    int num = 0;

    for(int i = 0; i < n; i++){
        dq.push_back(i+1);
    }

    for(int i = 0; i < m; i++){
        cin >> vec[i];
    }

    int cnt = 0;
    int idx = 0;
    while(idx < m){
        auto it = find(dq.begin(), dq.end(), vec[idx]);

        int pos = distance(dq.begin(), it);

        if(vec[idx] == dq.front()){
            pop();
            idx++;
        }
        
        else if (pos <= dq.size() / 2){
            //왼쪽
            for (int i = 0; i < pos; i++) {
                lMove();
            }
            cnt+=pos;
        }
        else{
            //오른쪽
            for(int i = 0; i < dq.size() - pos; i++){
                rMove();
            }
            cnt+=dq.size()-pos;
        }
    }

    cout << cnt << '\n';

    return 0;
}