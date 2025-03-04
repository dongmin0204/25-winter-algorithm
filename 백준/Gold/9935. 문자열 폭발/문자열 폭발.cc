#include <bits/stdc++.h>
using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input,bomb;
    cin >> input;
    cin >> bomb;

    int input_size = input.size();
    int bomb_size = bomb.size();

    stack<char> s;
    
	string ans;
	ans.reserve(1000000);
	
    for(int i=0;i < input_size; i++)
	{
        s.push(input[i]);
		for(int j=0;j<bomb_size; j++)
		{
				
				if(s.size() >= bomb_size && j==bomb_size-1)
				{
					string temp;
                    for(int k = 0; k < bomb_size; k++){
                        temp.push_back(s.top());
                        s.pop();
                    }
					reverse(temp.begin(),temp.end());
	
					// 뒤집은 문자열과 폭발문 문자열 같은지 판단
					if(temp.compare(bomb) != 0){
						//다시 넣고
						for(int l = 0; l < temp.length(); l++) {
							s.push(temp[l]);
						}
					}
				}
		}
	}

    // 스택에 남은 원소들을 ans에 넣음
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    reverse(ans.begin(),ans.end()); //뒤집기
    if(ans.empty()) {
		cout << "FRULA"; 
	}
    else{
		cout << ans;
	} 

    return 0;
}