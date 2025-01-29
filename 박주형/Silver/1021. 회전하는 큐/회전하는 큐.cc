#include <bits/stdc++.h>
using namespace std;

int findIndex(deque<int> DQ, int value) {
    for(size_t i = 0; i < DQ.size(); i++) {
        if (DQ[i] == value) {
            return i;
        }
    }
    return -1;
}

int main()
{
    int N, M;
    cin >> N >> M;
    
    deque<int> DQ;
    for(int i = 1; i <= N; i++) {
        DQ.push_back(i);
    }
    
    
    int total = 0;
    
    for(int i = 0; i < M; i++) {
        int num;
        cin >> num;
        
        int midel;
        if(DQ.size() % 2 == 0) {
            midel = DQ.size()/2 - 1;
        } else {
            midel = DQ.size()/2;
        }
        
        // cout << DQ.size() << " " << midel << '\n';
        
        if(DQ.front() == num) {
            DQ.pop_front();
            
            continue;
        }
        int index = findIndex(DQ, num);
        
        if(index <= midel) {
            while(num != DQ.front()){
                int temp;
                temp = DQ.front();
                DQ.pop_front();
                DQ.push_back(temp);
                
                total++;
            }
            DQ.pop_front();
        } else {
            while(num != DQ.front()) {
                int temp;
                temp = DQ.back();
                DQ.pop_back();
                DQ.push_front(temp);
                
                total++;
            }
            DQ.pop_front();
        }
    }
    cout << total;

    return 0;
}