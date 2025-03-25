#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000;

//행렬
struct Matrix {
    long long m[2][2];
};

// 2x2 행렬 곱셈
Matrix matMul(const Matrix &A, const Matrix &B) {
    Matrix R;
    R.m[0][0] = (A.m[0][0] * B.m[0][0] + A.m[0][1] * B.m[1][0]) % MOD;
    R.m[0][1] = (A.m[0][0] * B.m[0][1] + A.m[0][1] * B.m[1][1]) % MOD;
    R.m[1][0] = (A.m[1][0] * B.m[0][0] + A.m[1][1] * B.m[1][0]) % MOD;
    R.m[1][1] = (A.m[1][0] * B.m[0][1] + A.m[1][1] * B.m[1][1]) % MOD;
    return R;
}

// 2x2 행렬 
Matrix matPow(Matrix base, long long exp) {
    // 단위 행렬
    Matrix result;
    result.m[0][0] = 1; result.m[0][1] = 0;
    result.m[1][0] = 0; result.m[1][1] = 1;
    
    while (exp > 0) {
        if (exp & 1) {
            result = matMul(result, base);
        }
        base = matMul(base, base);
        exp >>= 1;
    }
    return result;
}

// 피보나치
long long fib(long long n) {
    // B = [[1, 1], [1, 0]]
    Matrix B;
    B.m[0][0] = 1; B.m[0][1] = 1;
    B.m[1][0] = 1; B.m[1][1] = 0;

    if (n == 0) {
        return 0;
    }
    // B의 n승
    Matrix M = matPow(B, n);
    // M[0][1] = F(n)
    return M.m[0][1] % MOD; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;
    cout << fib(n) << "\n";
    return 0;
}
