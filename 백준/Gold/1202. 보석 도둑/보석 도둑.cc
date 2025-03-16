#include <bits/stdc++.h>
using namespace std;

int n,k;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);


    
    cin >> n >> k;
    pair<int,int> jewel[300004]; // {무게,가격}
    multiset<int> bag; //가방
   

    for(int i = 0; i < n; i++){
        int weight, price; 
        cin >> weight >> price;
        jewel[i] = (make_pair(price,weight));
    }
    sort(jewel,jewel+n);

    for(int i = 0; i < k; i++){
        int size;
        cin >> size;
        bag.insert(size);
    }

    long long int ans = 0;
    

    //출력은 보석 최대 가져 갈 수 있는 가격
    for(int i = n-1; i >= 0; i--){
        int p = jewel[i].first;
        int w = jewel[i].second;//first = price, second = weight
        auto it = bag.lower_bound(w); //가방중 무게 가능한 곳 low_bound탐색
        if(it == bag.end()) continue; // 가능한 가방없음
        ans += p; //가격 없뎃
        bag.erase(it);
    }
    cout << ans;

    return 0;
}