#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> clothes(n + 1, 1);
    int answer = 0;

    for (int l : lost) {
        clothes[l]--;
    }
    for (int r : reserve) {
        clothes[r]++;
    }
    
    for (int i = 1; i <= n; i++) {
        if (clothes[i] == 0) { //lost
            if (i > 1 && clothes[i - 1] == 2) {
                clothes[i - 1]--;
                clothes[i]++;
            } 
            else if (i < n && clothes[i + 1] == 2) {
                clothes[i + 1]--;
                clothes[i]++;
            }
        }
    }
        
    for(int i = 1; i < n+1; i++){
        if(clothes[i] >= 1){
            answer++;
        }
    }
    
    return answer;
}