#include <bits/stdc++.h>
using namespace std;

deque<int> parsing(string& numbers) {
    
    deque<int> result;
    
    numbers += ",";
    
    string delimiter = ",";
    
    int cur_pos = 0;
    int pos;
    while((pos = numbers.find(delimiter, cur_pos)) != string::npos) {
        int len = pos - cur_pos;
        result.push_back(stoi(numbers.substr(cur_pos, len)));
        cur_pos = pos+1;
    }
    return result;
}

void printNumbers(deque<int> DQ, bool reversed) {
    cout << "[";
    if (reversed) {
        for (auto it = DQ.rbegin(); it != DQ.rend(); ++it) {
            cout << *it;
            if(it + 1 != DQ.rend()) {
                cout << ",";
            }
        }
    } else {
        for (auto it = DQ.begin(); it != DQ.end(); ++it) {
            cout << *it;
            if(it + 1 != DQ.end()) {
                cout << ",";
            }
        }
    }
    cout << "]" << '\n';
}

int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        int length;
        cin >> length;
        string numbers;
        cin >> numbers;
        
        // if(numbers == "[]") {
        //     cout << "error" << '\n';
        //     continue;
        // }
        
        int sLength = numbers.length();
        
        deque<int> DQ;
        if(numbers == "[]") {
            numbers = "";
        } else {
            numbers = numbers.substr(1, sLength-1);
            DQ = parsing(numbers);
        }
        
        bool reversed = false;
        
        int t = 1;
        
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == 'R') {
                reversed = !reversed;
            }else if(s[j] == 'D') {
                if(!DQ.empty()) {
                    if(reversed) {
                        DQ.pop_back();
                    }else {
                        DQ.pop_front();
                    }
                    
                }else{
                    t = 0;
                    cout << "error" << '\n';
                    break;
                }
            }
        }
        
        if(t) printNumbers(DQ, reversed);
    }

    return 0;
}