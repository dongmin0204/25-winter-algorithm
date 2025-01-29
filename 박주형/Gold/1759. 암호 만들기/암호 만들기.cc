#include <bits/stdc++.h>
using namespace std;

set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

bool containsVowel(const vector<char> vv) {
    for(char c : vv) {
        if (vowels.count(c)) {
            return true;
        }
    }
    return false;
}

bool leastTwoConsonants(const vector<char> vv) {
    int count = 0;
    for(char c : vv) {
        if( !vowels.count(c)) {
            count++;
        }
    }
    return count >= 2;
}

void calculate(int start, int L, vector<char> v, vector<char> vv) {
    if(vv.size() == L) {
        if(containsVowel(vv) && leastTwoConsonants(vv)) {
            for(char c : vv) {
                cout << c;
            }
            cout << '\n';
        }
        return;
    }
    for(int i = start + 1; i < v.size(); i++) {
        vv.push_back(v[i]);
        calculate(i, L, v, vv);
        vv.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int L, C;
    cin >> L >> C;
    
    vector<char> v;
    
    for (int i = 0; i < C; i++) {
        char ch; 
        cin >> ch;
        v.push_back(ch);
    }
    sort(v.begin(), v.end());
    
    vector<char> vv;
    calculate(-1, L, v, vv);
}