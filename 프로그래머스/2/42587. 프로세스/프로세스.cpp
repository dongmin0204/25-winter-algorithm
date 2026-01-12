#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(vector<int> priorities, int location) {
    
    int answer = 0;
    queue<pair<int,int>> q;
    priority_queue<int> pq;
    
    int k = 0;
    for(int p : priorities){
        pq.push(p);
        q.push(make_pair(k++,p)); //index, priority
        
    }
    
    
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (cur.second == pq.top()) {   // print
            pq.pop();
            answer++;

            if (cur.first == location) {
                return answer;
            }
        } 
        else {                        // rotate
            q.push(cur);
        }
    }
    
    return answer;
}