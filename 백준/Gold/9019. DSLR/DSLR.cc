#include <bits/stdc++.h>
using namespace std;


int d(int input) {
    return (input * 2) % 10000;
}
int s(int input) {
    if (input == 0) return 9999;
    else return input - 1;
}
int l(int input) { // 1234 -> 2340 + 1
    return (input % 1000) * 10 + (input / 1000);
}
int r(int input) { // 1234 -> 4000 + 123
    return (input / 10) + (input % 10) * 1000;
}


char op[4] = {'d','s','l','r'};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int a,b;
        cin >> a >> b;

        queue<pair<int,string>> q;
        vector<bool> visited(10000, false);
        string output = "";
        q.emplace(a, output);
        visited[a] = true;
        while(!q.empty()){
            int cur = q.front().first;
            if (d(cur) == b) {
                cout << q.front().second + "D" << '\n';
                break;
            } else if (s(cur) == b) {
                cout << q.front().second + "S" << '\n';
                break;
            } else if (l(cur) == b) {
                cout << q.front().second + "L" << '\n';
                break;
            } else if (r(cur) == b) {
                cout << q.front().second + "R" << '\n';
                break;
            }

            if (!visited[d(cur)]) {
                q.emplace(d(cur), q.front().second + "D");
                visited[d(cur)] = true;
            }
            if (!visited[s(cur)]) {
                q.emplace(s(cur), q.front().second + "S");
                visited[s(cur)] = true;
            }
            if (!visited[l(cur)]) {
                q.emplace(l(cur), q.front().second + "L");
                visited[l(cur)] = true;
            }
            if (!visited[r(cur)]) {
                q.emplace(r(cur), q.front().second + "R");
                visited[r(cur)] = true;
            }
            q.pop();

        }


        

    }

    return 0;
}