#include <bits/stdc++.h>
using namespace std;

typedef struct Stack{
    struct Node* top = nullptr; //single linked 연결 리스트의 head(top부분)
    int size = 0; //스택의 사이즈, ++ / -- 와 empty만 확인
}Stack;

typedef struct Node{
    int data;
    struct Node* next;
    Node(int n) : data(n), next(nullptr){};//구조체 생성자
}Node;


//peek은 top노드의 data return

inline int empty(Stack& s) { return s.top == nullptr ? 1 : 0; }
inline int peek(Stack& s) { 
    if(empty(s)) {
        return -1;
    }
    else {
        return s.top->data;
    }
}


//push는 top에 삽입 하는 구조 
void push(int x, Stack& s){
    Node* newNode = new Node(x); //새로운 노드 생성

    //not empty 시
    if(!empty(s)) newNode->next = s.top;
    s.top = newNode;


    s.size++;
}


//pop은 top노드를 delete하고 새로운 top 가르켜야함.
void pop(Stack& s){

    if(empty(s)){
        return;
    }

    Node* temp = s.top;
    s.top = s.top->next;

    delete temp;

    s.size--;
}




int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, cmd, input;
    Stack s;
    cin >> n;
    while(n--){
        cin >> cmd;
        switch(cmd){
            case 1:

                cin >> input;
                push(input,s);
                break;

            case 2:
                cout << peek(s) << '\n';
                pop(s);
                break;
            case 3:
                cout << s.size << '\n';
                break;
            case 4:
                cout << empty(s) << '\n';
                break;
            case 5:
                cout << peek(s) << '\n';
                break;
        }
    }
    return 0;
}