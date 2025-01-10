#include <bits/stdc++.h>
using namespace std;

// Node 구조체
struct Node {
    char value;
    Node* next;
    Node* prev;
    Node(char v) : value(v), next(nullptr), prev(nullptr) {}
};

// 연결 리스트 클래스
class LinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    // 생성자
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // 리스트 초기화
    void push_back(char value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            head->next = head->prev = head;
        } else {
            newNode->prev = tail;
            newNode->next = head;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode;
        }
        size++;
    }

    // 왼쪽 회전
    void rotate_left() {
        if (size > 1) {
            head = head->next;
            tail = tail->next;
        }
        //cout << "head: " << head->value << " " << tail->value << '\n';
    }

    // 오른쪽 회전
    void rotate_right() {
        if (size > 1) {
            head = head->prev;
            tail = tail->prev;
        }
        //cout << "head: " << head->value << " " << tail->value << '\n';
    }

    // 출력
    void print() {
        Node* current = head;
        for (int i = 0; i < size; i++) {
            cout << current->value;
            current = current->next;
        }
        cout << '\n';
    }

    // 특정 구간 교환
    void swap_range(Node* start1, Node* end1, Node* start2, Node* end2) {
        Node* before1 = start1->prev;
        Node* after1 = end1->next;
        Node* before2 = start2->prev;
        Node* after2 = end2->next;
    
        before1->next = start2;
        start2->prev = before1;
        end2->next = after1;
        after1->prev = end2;
    
        before2->next = start1;
        start1->prev = before2;
        end1->next = after2;
        after2->prev = end1;
        //cout << 
    }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, R, Q;
    cin >> N >> R >> Q;

    LinkedList L1, L2;

    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        L1.push_back(c);
    }
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        L2.push_back(c);
    }

    Node* cursor1 = L1.head;
    Node* cursor2 = L2.head;
    Node* endCursor1 = cursor1;
    Node* endCursor2 = cursor2;
    
    for (int i = 1; i < R; i++) {
        endCursor1 = endCursor1->next;
        endCursor2 = endCursor2->next;
    }
    
    while (Q--) {
        char CH;
        cin >> CH;

        if (CH == 'S') {
            if(N != R){
                L1.swap_range(cursor1, endCursor1, cursor2, endCursor2);
            }
            
            
            Node* tempCursor = cursor1;
            cursor1 = cursor2;
            cursor2 = tempCursor;
            
            Node* tempEndCursor = endCursor1;
            endCursor1 = endCursor2;
            endCursor2 = tempEndCursor;
            
            Node* tempHead = L1.head;
            L1.head = L2.head;
            L2.head = tempHead;
            
            if(N == R){
                Node* tempTail = L1.tail;
                L1.tail = L2.tail;
                L2.tail = tempTail;
            }
            
            // cout << "L1: " << *L1.head << " " << *L1.tail << '\n'; 
            // cout << "L2: " << *L2.head << " " << *L2.tail << '\n'; 
        } else if (CH == 'L') {
            int num;
            cin >> num;
            if (num == 1) {
                cursor1 = cursor1->next;
                endCursor1 = endCursor1->next;
                L1.rotate_left();
            } else {
                cursor2 = cursor2->next;
                endCursor2 = endCursor2->next;
                L2.rotate_left();
            }
        } else if (CH == 'R') {
            int num;
            cin >> num;
            if (num == 1) {
                cursor1 = cursor1->prev;
                endCursor1 = endCursor1->prev;
                L1.rotate_right();
            } else {
                cursor2 = cursor2->prev;
                endCursor2 = endCursor2->prev;
                L2.rotate_right();
            }
        } else if (CH == 'I') {
            R++;
            endCursor1 = endCursor1->next;
            endCursor2 = endCursor2->next;
        } else if (CH == 'D') {
            R--;
            endCursor1 = endCursor1->prev;
            endCursor2 = endCursor2->prev;
        }
    }

    L1.print();
    L2.print();

    return 0;
}
