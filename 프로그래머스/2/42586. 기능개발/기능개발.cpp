#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<int> tmp;
    
    int maxDay = 0;
    int count = 0;
    for(int t = 0; t < speeds.size(); t++){
        int i = progresses[t];
        int j = speeds[t];
        
        int res =  (100-i)%j == 0 ? (100-i)/j : (100-i)/j + 1;
        
        if(t == 0 || res > maxDay){
            // 새로운 그룹 시작
            if(t != 0){
                answer.push_back(count);
            }
            maxDay = res;
            count = 1;
        } 
        else {
            // 현재 그룹에 포함
            count++;
        }

    }
    answer.push_back(count);
    // 7  3 < 9
    // 5 < 10 1 1 < 20 1 
    
    return answer;
}