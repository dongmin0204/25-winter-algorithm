#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    //최소가 거리여야 해서, 거리 순으로 정렬
    // 순서대로 지나가면서 정렬한다.
    //
    /*
        answer = 0
        i = n-1
        while i >=0
            i가 max(deliver[i],pickup[i])
            이번 왕복의 거리 = (i+1)*2
            answer += distance

            deliver_capacity = cap - deliver
            pickup_capacity = cap - pickup

        i 줄임
    */
    //

    long long answer = 0;
    long long needDeliver = 0; // i 이후(포함)에서 앞으로 배달해야 할 전체 상자 수
    long long needPickup  = 0; // i 이후(포함)에서 앞으로 수거해야 할 전체 상자 수

    // 가장 먼 집부터 역순으로 처리
    for (int i = n - 1; i >= 0; --i) {
        needDeliver += deliveries[i];
        needPickup  += pickups[i];

        while (needDeliver > 0 || needPickup > 0) {
            needDeliver -= cap;
            needPickup  -= cap;
            answer += (long long)(i+1)*2;  // 왕복 거리
        }
    }


    return answer;
}