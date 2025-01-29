/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<string> vtr;
    
    cin >> n;
    while(n--){
        string str1;
        string str2;
        
        cin >> str1;
        
        reverse(str1.begin(), str1.end());
        
        stack<char> stk;
        for(auto c : str1) stk.push(c);
        
        list<char> L;
        
        //for(auto c : str1) L.push_back(c);
        auto cursor = L.begin();
        
        while(!stk.empty()){
            
            //cout << str1[n] << '\n';
            if(stk.top() == '<'){
                if(cursor != L.begin()){
                    cursor--;
                    //cout << "출력" << '\n';
                } 
                
            }
            else if(stk.top() == '>'){
                if(cursor != L.end()) cursor++;
            }
            else if(stk.top() == '-'){
                if(cursor != L.begin()){
                    cursor--;
                    cursor = L.erase(cursor);   
                }
            }
            else {
                
                    L.insert(cursor, stk.top());
                    //cursor++;
                
            }
            stk.pop();
        }
        
        for (auto c : L) {
            str2.push_back(c);
        }
        
        vtr.push_back(str2);
        
    }
    for(auto s : vtr) cout << s << '\n';
    
}