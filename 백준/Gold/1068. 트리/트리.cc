#include <bits/stdc++.h>
using namespace std;
vector<int> adj[52];
int visited[52];
int leafNode = 0;

void removeNode(int node) {
    visited[node] = 1;
    // cout << node << '\n';
    for(int i : adj[node]) {
        if(visited[i] == 1) continue;
        removeNode(i);
    }
    adj[node].clear();
    return;
}

void searchNode(int node) {
    // if(node == 0) {
    //     for(int i : adj[node]){
    //         if(visited[i] == 0) {
    //             leafNode = 0;
    //             break;
    //         } else {
    //             leafNode = 1;
    //         }
    //     }
    // }
    for(int i : adj[node]) {
        if(visited[i] == 0) {
            return;
        }
    }
    leafNode++;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if( num == -1 ) {
            continue;
        }
        adj[num].push_back(i);
    }
    int RN;
    cin >> RN;
    removeNode(RN);
    
    for(int i = 0; i < N; i++) {
        if(visited[i] == 0) {
            // cout << i << '\n';
            searchNode(i);
        }
        
    }

    cout << leafNode;
    return 0;
}