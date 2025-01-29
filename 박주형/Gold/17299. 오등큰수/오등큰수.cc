#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    int count;
    int index;
};

int main()
{
    int N;
    cin >> N;

    stack<Node> stk;
    unordered_map<int, int> freq; 
    vector<int> v;
    vector<int> vv(N, -1);
    
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        freq[num]++;
        v.push_back(num);
    }

    for (int i = 0; i < N; i++) {
        
        stack<Node> stk2;
        while (!stk.empty() && stk.top().count < freq[v[i]]) {
            // if(stk.top().value != v[i]){
                vv[stk.top().index] = v[i];
            // }
            // else{
            //     Node addNode = stk.top();
            //     stk2.push(addNode);
            // }
            
            stk.pop();
        }
        
        Node newNode = {v[i], freq[v[i]], i};
        stk.push(newNode);
        
        // while(!stk2.empty()){
        //     Node addNode = stk2.top();
        //     addNode.count = freq[v[i]];
        //     stk.push(addNode);
        //     stk2.pop();
        // }
        // cout << newNode.value << '\n';
        
    }

    for (int i = 0; i < N; i++) {
        cout << vv[i] << " ";
    }

    return 0;
}
