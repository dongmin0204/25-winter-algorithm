#include <string>
#include <vector>

#include <iostream>

using namespace std;

// 체스판에 퀸을 배치할 수 있는지 확인하는 함수
bool isValid(const vector<int>& board, int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (board[i] == col ||           // 같은 열에 퀸이 있는지 확인
            board[i] - i == col - row || // 대각선 (\)에 퀸이 있는지 확인
            board[i] + i == col + row) { // 대각선 (/)에 퀸이 있는지 확인
            return false;
        }
    }
    return true;
}

// 재귀적으로 퀸을 배치하는 함수
void placeQueens(vector<int>& board, int row, vector<vector<int>>& solutions, int n) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }
    for (int col = 0; col < n; ++col) {
        if (isValid(board, row, col)) {
            board[row] = col;
            placeQueens(board, row + 1, solutions, n);
            board[row] = -1; // 백트래킹
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> solutions;
    vector<int> board(n, -1);
    placeQueens(board, 0, solutions, n);
    return solutions;
}

void printSolution(const vector<int>& solution) {
    int n = solution.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (solution[i] == j) {
                //cout << "Q ";
            } else {
                //cout << ". ";
            }
        }
        //ut << endl;
    }
    //ut << endl;
}

int solution(int n) {
    vector<vector<int>> solutions = solveNQueens(n);
    int answer = solutions.size();
    return answer;
}