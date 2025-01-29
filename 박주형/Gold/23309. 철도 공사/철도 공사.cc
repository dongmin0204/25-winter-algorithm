#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    list<int> L;
    unordered_map<int, list<int>::iterator> pos; // 요소와 반복자 매핑
    
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        L.push_back(num);
        pos[num] = prev(L.end()); // 요소의 반복자 저장
    }
    
    for(int i = 0; i < M; i++) {
        auto cursor = L.begin();
        
        string str;
        cin >> str;
        
        if (str == "BN") {
            int num, NN;
            cin >> num >> NN;
            
            cursor = pos[num];
            if (cursor == prev(L.end())) {
                //cursor = L.end();
                cursor++;
                L.push_back(NN);
                pos[NN] = prev(L.end());
                cursor = L.begin();
                cout << *cursor << '\n';
            } else {
                cursor++;
                cursor = L.insert(cursor, NN);
                pos[NN] = cursor;
                cursor++;
                //if (cursor == L.end()) cursor = L.begin();
                cout << *cursor << '\n';
            }
        } 
        
        else if (str == "BP") {
            int num, NN;
            cin >> num >> NN;
            
                cursor = pos[num];
                if (cursor == L.begin()) {
                    cursor = prev(L.end());
                    
                    cout << *cursor << '\n';
                    cursor++;
                    cursor = L.insert(cursor, NN);
                    pos[NN] = cursor;
                } else {
                    cursor--;
                    cout << *cursor << '\n';
                    cursor++;
                    cursor = L.insert(cursor, NN);
                    pos[NN] = cursor;
                }
        } 
        
        else if (str == "CN") {
            int num;
            cin >> num;
            
                cursor = pos[num];
                if (cursor == prev(L.end())) {
                    cursor = L.begin();
                    cout << *cursor << '\n';
                    pos.erase(*cursor);
                    cursor = L.erase(cursor);
                } else {
                    cursor++;
                    cout << *cursor << '\n';
                    pos.erase(*cursor);
                    cursor = L.erase(cursor);
                }
        } 
        
        else if (str == "CP") {
            int num;
            cin >> num;
            
                cursor = pos[num];
                if (cursor == L.begin()) {
                    cursor = prev(L.end());
                    cout << *cursor << '\n';
                    pos.erase(*cursor);
                    cursor = L.erase(cursor);
                } else {
                    cursor--;
                    cout << *cursor << '\n';
                    pos.erase(*cursor);
                    cursor = L.erase(cursor);
                }
        }
    }
    
    //for(int a : L) cout << a << " ";

    return 0;
}
