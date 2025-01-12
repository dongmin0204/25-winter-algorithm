#include <iostream>
using namespace std;

int main() {
    int E, S, M;
    cin >> E >> S >> M;

    E--;
    S--;
    M--;

    int year = E; 

    while (true) {
        if (year % 28 == S && year % 19 == M) {
            cout << year + 1 << "\n"; 
            break;
        }
        year += 15;
    }

    return 0;
}