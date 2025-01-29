#include <bits/stdc++.h>
using namespace std;

// 최대 노드 개수 정의
#define MAX_NODES 50

// 왼쪽 자식과 오른쪽 자식을 저장할 배열
int left_child[MAX_NODES];
int right_child[MAX_NODES];

// 각 노드의 부모의 배열
int parentArr[MAX_NODES];

// 삭제된 노드 표시 배열
bool deleted_nodes[MAX_NODES];

// 루트 노드를 저장
int root = -1;

// 삭제 재귀 함수
void delete_node(int node) {
    if (node == -1) return;
    
    // 해당 노드를 삭제 표시
    deleted_nodes[node] = true;
    
    // 자식 노드들도 재귀적으로 삭제
    delete_node(left_child[node]);
    delete_node(right_child[node]);
    
    // 부모 노드의 자식 포인터를 nullptr로 설정
    int parent = parentArr[node];
    if (parent != -1) {
        if (left_child[parent] == node) {
            left_child[parent] = -1;
        }
        else if (right_child[parent] == node) {
            right_child[parent] = -1;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    // 초기화
    for(int i=0; i<N; i++) {
        left_child[i] = -1;
        right_child[i] = -1;
        parentArr[i] = -1;
        deleted_nodes[i] = false;
    }
    
    // 부모 배열 입력
    for(int i=0; i<N; i++) {
        cin >> parentArr[i];
        if(parentArr[i] == -1){
            root = i;
        }
        else{
            // 부모 노드의 왼쪽 자식부터 채움
            if(left_child[parentArr[i]] == -1){
                left_child[parentArr[i]] = i;
            }
            else{ //오른쪽?
                right_child[parentArr[i]] = i;
            }
        }
    }
    
    int del;
    cin >> del;
    
    // 삭제할 노드가 루트인 경우 처리
    if(del == root){
        // 모든 노드가 삭제되므로 리프 노드 개수는 0
        cout << "0" << '\n';
        return 0;
    }
    
    // 삭제할 노드와 그 자손을 삭제
    delete_node(del);
    
    // 리프 노드 카운트
    int leaf_count = 0;
    for(int i=0; i<N; i++) {
        if(!deleted_nodes[i]){
            // 자식이 없는 경우 리프 노드
            bool is_leaf = true;
            if(left_child[i] != -1 && !deleted_nodes[left_child[i]]){
                is_leaf = false;
            }
            if(right_child[i] != -1 && !deleted_nodes[right_child[i]]){
                is_leaf = false;
            }
            if(is_leaf){
                leaf_count++;
            }
        }
    }
    
    cout << leaf_count << '\n';
}
