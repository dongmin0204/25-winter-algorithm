#include <bits/stdc++.h>
using namespace std;
#define INF 999999

// 유니온 파인드 Disjoint Set Union => 크루스칼에서 자주 활용 된다고 함
struct DSU {
    vector<int> parent; // parent[x]는 x의 부모 인덱스. 루트는 parent[root] == root
    vector<int> rank;   // 트리의 한계 높이임 트리가 한쪽으로 치우치지 않게 균형 유지
    

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i; // 각자 독립 집합
        }
    } 
    //n개의 원소가 각각 독립인 집합으로 시작, rank는 모두 0으로 시작(높이 0짜리 트리)
    

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // 경로 압축
    }
    // 루트까지 재귀로 올라간 뒤, 지나온 노드들의 parent를 루트로 곧장 연결 (경로 압축이라 함)
    // 이후 같은 원소에 대한 탐색이 매우 빨라짐(1의 시간복잡도)
    // 사실상 캐쉬랑 마찬가지

    bool unite(int a, int b) {
        a = find(a); 
        b = find(b); //각자의 루트
        
        if (a == b) return false;//이미 같은 집합이면, 합칠 일 없음(사이클 감지에 유용)

        if (rank[a] < rank[b]) {
            swap(a, b);
        } //a의 랭크가 항상 크거나 같게
        
        parent[b] = a;  //b 루트를 a 아래로 붙임
        
        if (rank[a] == rank[b]) {
            rank[a]++;
        } //랭크 같았으면 새 루트 높이 증가
        return true;                      //실제로 합쳐졌음을 의미
    }
    // 작은 랭크 트리를 큰 랭크 트리 밑으로 붙여 트리 높이 증가를 최소화.
    // 랭크가 같은 두 트리를 합칠 때만 새 루트의 랭크를 1 증가.
};

// n: 섬 개수, costs: [시작, 도착정점, 가주치]

// [[0,1,1]
//(출발, 도착, cost),...] 
//그래프 문제 
//가장 적은 비용으로 모두를 통행(길찾기) 
//현재 주어지는 건 간선 리스트 -> 프림 혹은 크루스칼 알고리즘

bool compareCost(const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2];//비용 기준으로 오름차순 정렬
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    //1: 간선 비용 기준 오름차순 정렬
    sort(costs.begin(), costs.end(), compareCost);

    DSU dsu(n);
    int edgesUsed = 0;

    //2. 간선을 하나씩 확인
    for (int i = 0; i < costs.size(); i++) {
        int u = costs[i][0];
        int v = costs[i][1];
        int w = costs[i][2];

        //사이클이 안 생기면 선택
        if (dsu.unite(u, v)) {
            answer += w;
            edgesUsed++;
            if (edgesUsed == n - 1) break; //최소 신장트리 완성
        }
    }

    return answer;
}