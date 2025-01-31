#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* rl; // 오른쪽
    Node* ll; // 왼쪽
    char data;

    Node(char ch) : rl(nullptr), ll(nullptr), data(ch) {}
};

struct Curser {
    Node* left;  // 현재 커서 왼쪽 
    Node* right; // 현재 커서 오른쪽
};

Node* head;
Curser cur; // 커서

void initialize(string s) {
    head = nullptr;
    cur.left = nullptr;
    cur.right = nullptr;

    Node* tail = nullptr;
    for (auto ch : s) {

        Node* temp = new Node(ch);

        if (!head) { // 노드 생성
            head = temp;
            tail = temp;
        } 
        else { 
            tail->rl = temp;
            temp->ll = tail;
            tail = temp;
        }
    }

    cur.left = tail;  
    cur.right = nullptr; 
    //curser 위치 맨끝
}

void append(char ch) {
    Node* temp = new Node(ch);

    if (!cur.right && !cur.left) { // 시작
        head = temp;
        cur.left = temp;
        return;
    } 
    else if (!cur.right) { // 끝
        cur.left->rl = temp;
        temp->ll = cur.left;
        cur.left = temp;
    } 
    else { // 중간
        temp->rl = cur.right;
        temp->ll = cur.left;

        if (cur.left) 
            cur.left->rl = temp;
        else 
            head = temp; // 맨 앞에 삽입
        
        cur.right->ll = temp;
        cur.left = temp;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int n;

    cin >> str;
    initialize(str); // 리스트 초기화

    cin >> n;
    while (n--) {
        char cmd;
        cin >> cmd;
        switch (cmd) {
            case 'L': // 커서를 왼쪽
                if (cur.left) { //cur가 nullptr X
                    cur.right = cur.left; // c a < - cur -> b,  c a <- <-cur b
                    cur.left = cur.left->ll; // c<- cur -> a 
                }
                break;
            case 'D': // 커서를 오른쪽
                if (cur.right) {
                    cur.left = cur.right;
                    cur.right = cur.right->rl;
                }
                break;
            case 'P': { // append
                char data;
                cin >> data;
                append(data);
                break;
            }
            case 'B': { // del
                    if (!cur.left) break; // 커서 왼쪽에 노드가 없는 경우
                    Node* temp = cur.left;
                    if (temp == head) { //head
                        head = temp->rl; // head 다음 노드
                        if (head) head->ll = nullptr;
                        cur.left = nullptr; 
                    } 
                    else { // 중간 
                        temp->ll->rl = temp->rl; 
                        if (temp->rl) temp->rl->ll = temp->ll; 
                        cur.left = temp->ll; 
                    }

                    free(temp); // 삭제된 노드 메모리 해제
                break;
            }
        }
    }

    // print
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        temp = temp->rl;
    }
    cout << '\n';

    return 0;
}
