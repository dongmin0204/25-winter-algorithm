#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    sort(nums.begin(), nums.end());
    int unique_cnt = unique(nums.begin(), nums.end()) - nums.begin();
    int cap = nums.size() / 2;
    
    answer = min(unique_cnt, cap);
    return answer;
}