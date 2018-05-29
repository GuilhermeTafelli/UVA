#include<bits/stdc++.h>
using namespace std;

string expo(string base, int e){
    
    if(e == 1)return base;
    string ans = expo(base, e >> 1);
    ans += ans;
    if(e&1)ans += base;
    return ans;
    
}


int main(){
    string s;
    while(cin >> s, s != "."){
        int t = s.size();
        int i = 0;
        
        string r, aux = "";

        for(i = 0;i<t;i++){
            aux += s[i];
            if(t%(i+1) == 0) {
                r = expo(aux, t/(i+1));    
                if(s == r) break;
            }
        }
        
        cout << t/(i+1) << endl;
    }   
}
