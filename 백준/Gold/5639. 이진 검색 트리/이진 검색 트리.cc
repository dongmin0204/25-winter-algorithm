#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
    struct Node* ll;
    struct Node* rl;
    int data;

    Node(int a) : ll(nullptr), rl(nullptr), data(a) {}
} node;

node* tree = nullptr;

void insert(int a) {
    node* newNode = new node(a);

    if (tree == nullptr) {
        tree = newNode;
        return;
    }

    node* cur = tree;
    while (true) {
        if (a < cur->data) {
            if (cur->ll == nullptr) {
                cur->ll = newNode;
                return;
            } else {
                cur = cur->ll;
            }
        } else {
            if (cur->rl == nullptr) {
                cur->rl = newNode;
                return;
            } else {
                cur = cur->rl;
            }
        }
    }
}
void postorder(node* root) {
    if (root == nullptr) return;
    postorder(root->ll);
    postorder(root->rl);
    cout << root->data << '\n';
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int input;
    while (cin >> input) {
        insert(input);
    }

    postorder(tree);

    return 0;
}
