#include <bits/stdc++.h>
using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    unordered_map<string, string> log;
    string name, enter;

    int T;
    cin >> T;
    while(T--){
        cin >> name >> enter; //키 밸류
        if(enter == "enter"){
            log[name] = enter;
        }
        else{
            log.erase(name);
        }
    }

    vector<string> names;
    for(auto &p : log){
        names.push_back(p.first);
    }
    sort(names.begin(),names.end(),greater<string>());

    for(auto it : names){
        cout << it << '\n';
    }

    return 0;
}