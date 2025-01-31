#include <bits/stdc++.h>
using namespace std;

// ------------------------------
// 노드(Node) 정의 (이중연결리스트)
// ------------------------------
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
};

// ------------------------------
// Deque 구조체 (이중연결리스트 사용)
// ------------------------------
struct Deque {
    Node* front; // 덱의 맨 앞
    Node* back;  // 덱의 맨 뒤
    int size;    // 원소의 개수

    Deque() : front(nullptr), back(nullptr), size(0) {}
};

// 덱이 비어있는지 확인
inline bool empty(Deque &dq) {
    return (dq.size == 0);
}

// 덱의 맨 앞의 값 (비어있으면 -1)
inline int frontVal(Deque &dq) {
    return empty(dq) ? -1 : dq.front->data;
}

// 덱의 맨 뒤의 값 (비어있으면 -1)
inline int backVal(Deque &dq) {
    return empty(dq) ? -1 : dq.back->data;
}

// 1. 덱의 앞에 삽입 (pushFront)
void pushFront(Deque &dq, int x) {
    Node* newNode = new Node(x);

    // 현재 덱이 비어있는 경우
    if (empty(dq)) {
        dq.front = newNode;
        dq.back = newNode;
    } else {
        newNode->next = dq.front;   // 새 노드의 next를 기존 front로
        dq.front->prev = newNode;   // 기존 front의 prev를 새 노드로
        dq.front = newNode;         // front를 새 노드로 갱신
    }
    dq.size++;
}

// 2. 덱의 뒤에 삽입 (pushBack)
void pushBack(Deque &dq, int x) {
    Node* newNode = new Node(x);

    // 현재 덱이 비어있는 경우
    if (empty(dq)) {
        dq.front = newNode;
        dq.back = newNode;
    } else {
        dq.back->next = newNode;    // 기존 back의 next를 새 노드로
        newNode->prev = dq.back;    // 새 노드의 prev를 기존 back으로
        dq.back = newNode;          // back을 새 노드로 갱신
    }
    dq.size++;
}

// 3. 덱의 맨 앞 노드를 제거 (popFront) 후 해당 값 리턴
int popFront(Deque &dq) {
    if (empty(dq)) {
        return -1;
    }
    int ret = dq.front->data;
    Node* temp = dq.front;

    // 노드가 하나만 있을 경우
    if (dq.front == dq.back) {
        dq.front = nullptr;
        dq.back = nullptr;
    }
    else {
        dq.front = dq.front->next; // front를 다음 노드로
        dq.front->prev = nullptr;  // 새로운 front의 prev는 null
    }

    delete temp;
    dq.size--;
    return ret;
}

// 4. 덱의 맨 뒤 노드를 제거 (popBack) 후 해당 값 리턴
int popBack(Deque &dq) {
    if (empty(dq)) {
        return -1;
    }
    int ret = dq.back->data;
    Node* temp = dq.back;

    // 노드가 하나만 있을 경우
    if (dq.front == dq.back) {
        dq.front = nullptr;
        dq.back = nullptr;
    }
    else {
        dq.back = dq.back->prev; // back을 이전 노드로
        dq.back->next = nullptr; // 새로운 back의 next는 null
    }

    delete temp;
    dq.size--;
    return ret;
}

// ------------------------------
// 메인 함수
// ------------------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;      // 명령 개수
    cin >> N;

    Deque dq;

    while(N--) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            // 1 X: 정수 X를 덱의 앞에 넣는다
            int x; cin >> x;
            pushFront(dq, x);

        } else if (cmd == 2) {
            // 2 X: 정수 X를 덱의 뒤에 넣는다
            int x; cin >> x;
            pushBack(dq, x);

        } else if (cmd == 3) {
            // 3: 덱이 비어있지 않다면 맨 앞의 정수를 빼고 출력, 없다면 -1
            cout << popFront(dq) << "\n";

        } else if (cmd == 4) {
            // 4: 덱이 비어있지 않다면 맨 뒤의 정수를 빼고 출력, 없다면 -1
            cout << popBack(dq) << "\n";

        } else if (cmd == 5) {
            // 5: 덱에 들어있는 정수의 개수 출력
            cout << dq.size << "\n";

        } else if (cmd == 6) {
            // 6: 덱이 비어있으면 1, 아니면 0
            cout << (empty(dq) ? 1 : 0) << "\n";

        } else if (cmd == 7) {
            // 7: 덱이 비어있지 않다면 맨 앞의 정수를 출력, 없다면 -1
            cout << frontVal(dq) << "\n";

        } else if (cmd == 8) {
            // 8: 덱이 비어있지 않다면 맨 뒤의 정수를 출력, 없다면 -1
            cout << backVal(dq) << "\n";
        }
    }

    return 0;
}
