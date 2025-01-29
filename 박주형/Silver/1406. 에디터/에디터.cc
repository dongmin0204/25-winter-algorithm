#include <bits/stdc++.h>
using namespace std;

int main()
{
    string init;
    cin >> init;
    list<char> L;
    for(auto c : init) L.push_back(c);
    auto cursor = L.end();
    int q;
    cin >> q;
    while(q--){
        char op;
        cin >> op;
        if(op == 'P'){
            char C;
            cin >> C;
            L.insert(cursor, C);
        }
        else if(op == 'L'){
            if(cursor != L.begin()) cursor--;
        }
        else if(op == 'D'){
            if(cursor != L.end()) cursor++;
        }
        else if(op == 'B'){
            if(cursor != L.begin()){
                cursor--;
                cursor = L.erase(cursor);
            }
        }
    }
    for(auto c : L) cout << c;
    
    return 0;
}