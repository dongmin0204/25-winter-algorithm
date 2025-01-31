#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
    char data;
    struct Node* left;
    struct Node* right;
    Node(char ch) : data(ch),left(nullptr),right(nullptr) {}
}node;

void preorder(node* node){
    if(node == nullptr) return; //재귀 종료
    cout << node->data; //탐색, 출력
    preorder(node->left); //왼쪽 이동
    preorder(node->right); //오른쪽 이동
}

void inorder(node* node){
    if(node == nullptr) return; //재귀 종료
    inorder(node->left); //왼쪽 이동
    cout << node->data; //탐색, 출력
    inorder(node->right); //오른쪽 이동
}

void postorder(node* node){
    if(node == nullptr) return; //재귀 종료
    postorder(node->left); //왼쪽 이동
    postorder(node->right); //오른쪽 이동
    cout << node->data; //탐색, 출력
    
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    node* nodes[26] = {nullptr}; //모든 (A~Z) 노드 주소 저장

    for(int i = 0; i < n; ++i){
        char parent, left, right;
        cin >> parent >> left >> right;
        
        //기존 노드 없으면 새로 생성
        if(nodes[parent - 'A'] == nullptr){
            nodes[parent - 'A'] = new node(parent);
        }
        node* current = nodes[parent - 'A'];
        
        //left
        if(left != '.'){
            if(nodes[left - 'A'] == nullptr){
                nodes[left - 'A'] = new node(left);
            }
            current->left = nodes[left - 'A'];
        }
        
        //right
        if(right != '.'){
            if(nodes[right - 'A'] == nullptr){
                nodes[right - 'A'] = new node(right);
            }
            current->right = nodes[right - 'A'];
        }
    }

    node* root = nodes[0]; //루트 == A노드

    preorder(root);
    cout << '\n';
    inorder(root);
    cout << '\n';
    postorder(root);
    cout << '\n';
}