#include <bits/stdc++.h>
using namespace std;
int total = 0;

void sum(vector<int> v, int index, int T, int S, vector<int> v2) {
    if (index == v.size()) {
        if (T == S && v2.size() > 0) {
            total++;
            // for(int i : v2) cout << i << " ";
            // cout << '\n';
        }
        return;
    }
    v2.push_back(v[index]);
    sum(v, index+1, T+v[index], S, v2);
    v2.pop_back();
    sum(v, index+1, T, S, v2);

}

int main()
{
    int N, S;
    cin >> N >> S;
    vector<int> v;
    vector<int> v2;
    
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    sum(v, 0, 0, S, v2);
    
    cout << total;
    
    return 0;
}