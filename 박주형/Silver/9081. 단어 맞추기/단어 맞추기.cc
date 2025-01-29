#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string word;
        cin >> word;

        string original = word;

        if (next_permutation(word.begin(), word.end())) {
            cout << word << endl;
        } else {
            cout << original << endl;
        }
    }
    return 0;
}
