#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
int v[1010], p[1010], a, b, c, x, dp[1010][33];

int rec(int i, int s){
    if(i == b and s >= 0)return 0;
    if(s < 0)return -INF;
    if(dp[i][s] != -1)return dp[i][s];
    
    return dp[i][s] = max(rec(i+1, s-p[i])+v[i], rec(i+1, s));
}

int main(){
    int r = 0;
    cin >> a;
    while(a--){
    
        memset(dp, -1, sizeof dp);
        r = 0;
    
        cin >> b;
        for(int i = 0;i<b;i++){
            cin >> v[i] >> p[i];
        }
        cin >> c;
        for(int i = 0;i<c;i++){
            cin >> x;
            r+=rec(0, x);      
        }
        cout << r << endl;   
    }
}
