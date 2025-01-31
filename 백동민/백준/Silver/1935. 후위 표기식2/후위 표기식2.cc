#include <bits/stdc++.h>
using namespace std;


int main(void){

    int n;
    string cmd;
    stack<double> s;
    double op[27];

    cin >> n;
    cin >> cmd;

    for(int i = 0; i < n; i++){
        cin >> op[i];
    }

    for(int i = 0; i < cmd.size(); i++){
        if(cmd[i] <= 'Z' && cmd[i]>='A'){
            s.push(op[cmd[i]-'A']);
        }
        else{
            double op1 = s.top();
            s.pop();
            double op2 = s.top();
            s.pop();

            switch(cmd[i]){
                case '*':
                    s.push(op1*op2);
                    break;

                case '/':
                    s.push(op2/op1);
                    break;
            
                case '+':
                    s.push(op1+op2);
                    break;

                case '-':
                    s.push(op2-op1);
                    break;
                default:
                    cout << "error";
                    return 0;
                    break;
            }
        }
    }

    cout << fixed << setprecision(2) << s.top() << '\n'; //고정 << 2번째 자리까지 

    return 0;
}