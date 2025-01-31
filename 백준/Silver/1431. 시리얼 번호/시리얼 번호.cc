#include <bits/stdc++.h>
using namespace std;

int sum_str(const string& s) { //조건 2를 위한 함수
    int sum = 0;
    for(auto c : s){
        if(isdigit(c)){
            sum += c - '0';
        }
    }
    return sum;
}

struct Cmp {
    bool operator()(const string& value, const string& other)  const{
        if(value.length() != other.length()){
            return value.length() < other.length(); //조건 1
        }
        else{
            int sum_value = sum_str(value);
            int sum_other = sum_str(other);
            if(sum_value != sum_other){ //조건 2
                return sum_value < sum_other;
            }
            else{
                return value < other; //조건 3 : 사전 순
            }
        }
    }
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> serial;
    int n;
    cin >> n;
    string input;

    for(int i = 0; i < n; i++){
        cin >> input;
        serial.push_back(input);
    }

    sort(serial.begin(),serial.end(),Cmp()); //비교하는 객체로 정렬 기준 구현

    for(const auto& it : serial){
        cout << it << '\n';
    }

    return 0;
}
