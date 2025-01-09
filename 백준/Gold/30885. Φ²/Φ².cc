#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    long N;
    cin >> N;
    
    list<long> L;
    list<long> pos;
    
    for(long i = 1; i <= N; i++){
        long num;
        cin >> num;
        L.push_back(num);
        pos.push_back(i);
    }
    
    //cout << L.size() << " " << pos.size() << '\n';
    
    auto cursor = L.begin();
    auto pc = pos.begin();
    
    while(L.size() != 1){
        //cout << "야" << '\n';
        
        if(cursor == L.begin()){
            //cout << "가" << '\n';
            auto cursor2 = next(cursor);
            auto pc2 = next(pc);
            if(*cursor >= *cursor2){
                *cursor += *cursor2;
                L.erase(cursor2);
                pos.erase(pc2);
            }
            cursor++;
            pc++;
        } else if(cursor == prev(L.end())){
            //cout << "나" << '\n';
            auto cursor2 = prev(cursor);
            auto pc2 = prev(pc);
            if(*cursor >= *cursor2){
                *cursor += *cursor2;
                L.erase(cursor2);
                pos.erase(pc2);
            }
            cursor = L.begin();
            pc = pos.begin();
        } else {
            //cout << "다" << '\n';
            long num = *cursor;
            
            auto cursor2 = prev(cursor);
            auto pc2 = prev(pc);
            if(num >= *cursor2){
                *cursor += *cursor2;
                L.erase(cursor2);
                pos.erase(pc2);
            }
            auto cursor3 = next(cursor);
            auto pc3 = next(pc);
            if(num >= *cursor3){
                *cursor += *cursor3;
                L.erase(cursor3);
                pos.erase(pc3);
                if(cursor == prev(L.end())){
                    cursor = L.begin();
                    pc = pos.begin();
                }
                else{
                    cursor++;
                    pc++;
                }
            }
            else {
                cursor++;
                pc++;
            }
        }
        // for(auto n : L) cout << n << " ";
        // cout << '\n';
    }
    
    cout << L.front() << '\n';
    cout << pos.front() << '\n';
    
    return 0;
}