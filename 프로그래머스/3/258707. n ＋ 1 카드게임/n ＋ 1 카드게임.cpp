#include <bits/stdc++.h>
using namespace std;

int solution(int coin, vector<int> cards) {
    int answer = 0;
    int hands[1005];//hand[숫자] = 1(존재) 0(없음) -> 중복이 아니므로 가능
    fill(hands,hands+1005,0);
    //만약에 hand[i]&&hands[n-i] == true면 뽑기
    vector<int> hands_vec;
    
    int n = cards.size();
    
    for (int j = 0; j < n / 3;) {
        int temp = cards[j++];
        hands[temp] = 1;
        hands_vec.push_back(temp);
    }
    
    int draw[1005];//패를 뽑을 때 
    fill(draw,draw+1005,0);
    vector<int> draw_vec;
    
    int i = n/3;
    while (i < n) {
        // 이번 라운드에서 두 장 뒤집혀 '풀(pool)'에 올라온다고 생각
        int temp = cards[i++];
        draw[temp] = 1;
        draw_vec.push_back(temp);
        if (i < n) {
            temp = cards[i++];
            draw[temp] = 1;
            draw_vec.push_back(temp);
        } //일단 2개 뽑기 (1개 뽑은 경우도 있음)
        
        bool isActing = false;
        //0코인 우선 최대한의 라운드이므로, (가장 적은 코인을 쓰는 방법)
        //만약에 최소의 라운드면 2->1->0
        if(!isActing){
            for(int a : hands_vec ){
                if (!hands[a]) continue;
                int b = n + 1 - a;
                if(b != a){
                    if(b != a && hands[b]){ //손에 이미 2개 낼깨 있음
                        hands[a] = 0; hands[b] = 0; //뽑기
                        answer++; //round 끝
                        isActing = true;
                        break;//라운드 종료
                    }
                }
            }
        }
        if (isActing) continue; //라운드 종료

        if(coin <= 0) {
            // 코인 0이면 1코인 시도 불가
        } 
        else {
            for(int a : hands_vec ){
                if (!hands[a]) continue;
                int b = n+1 - a;
                if(b != a && draw[b]){ //손 1개 드로우 1개 (코인 1개)
                    hands[a] = 0; draw[b] = 0; //뽑기
                    coin--; //코인 1개
                    answer++; //round 끝
                    isActing = true;
                    break;//라운드 종료
                }
            }
        }
        if (isActing) continue; //라운드 종료

        //코인 2개 사용
        if (coin <= 1) {
            // 코인 1 이하이면 2코인 시도 불가
        } 
        else {
            for (int a : draw_vec) {
                if (!draw[a]) continue;
                int b = n+1 - a;
                if (b != a && draw[b]) {
                    draw[a] = 0; draw[b] = 0;//뽑기
                    coin -= 2; // 코인 2개
                    answer++; //round 끝
                    isActing = true;
                    break;
                }
            }
        }
        if (isActing) continue; //라운드 종료
        else break; //실패하면 게임 종료
    }
    
    return answer+1;
}