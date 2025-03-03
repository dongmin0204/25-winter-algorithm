#include <bits/stdc++.h>
using namespace std;

//행렬
typedef struct Matrix {
    long long m[5][5];
}matrix;

matrix input;
matrix temp;
matrix ans;//답지

long long int n,b; //n: 정방 행렬 사이즈, b: 제곱



// 행렬 곱셈
void Matrix_multi(matrix& x, matrix& y) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.m[i][j] = 0; // 행렬 초기화
            for (int k = 0; k < n; k++) { //행렬 곱셈
                temp.m[i][j] += (x.m[i][k] * y.m[k][j]);
            }

            temp.m[i][j] %= 1000; //1000으로 나누기
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x.m[i][j] = temp.m[i][j];
        }
    } //값 복사
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> b;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> input.m[i][j];
            if(i!=j){
                ans.m[i][j] = 0;
            }
        }
        ans.m[i][i] = 1; //단위행렬로 초기화
    }

    while (b > 0) { //5 >> 2 >> 1
        if (b % 2) { //홀수면 미리 곱함
            Matrix_multi(ans, input);
        }
        Matrix_multi(input, input); //행렬 제곱
        b /= 2;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ans.m[i][j] << ' ';
        }
        cout << '\n';
    }

    
    return 0;
}
