#include <bits/stdc++.h>
using namespace std;
int BIG_NUM = 0;

int sum(vector<int> T, vector<int> P, int i, int N, int total){
    if(i >= N) {
        return total;
    }
    
    int A = sum(T, P, i+1, N, total);
    
    int B = 0;
    if(i + T[i] <= N) {
        B += sum(T, P, i+T[i], N, total + P[i]);
    }
    
    return max(A, B);
};

int main()
{
    int N;
    cin >> N;
    
    vector<int> T;
    vector<int> P;
    for(int i = 0; i < N; i++) {
        int t, p;
        cin >> t >> p;
        T.push_back(t);
        P.push_back(p);
    }
    
    // for(int i = 0; i < N; i++) {
    //     int total = 0;
    //     total = sum(T, P, i, N, total);
    //     if(total > BIG_NUM) {
    //         BIG_NUM = total;
    //     }
    // }
    BIG_NUM = sum(T, P, 0, N, 0);
    cout << BIG_NUM;
    return 0;
}