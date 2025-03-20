#include <bits/stdc++.h>
using namespace std;

long long int a,b,c;

long long int fun(long long int a, long long int b, long long int c){
    if(b==1){
        return a%c;
    }
    else{
        long long int temp = fun(a,b/2,c);
        if(b%2==0){
            return temp%c * temp%c;
        }
        else{
            return temp%c * temp%c * a%c;
        }
    }
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    cin >> a >> b >> c;
    cout << fun(a,b,c);

    return 0;
}