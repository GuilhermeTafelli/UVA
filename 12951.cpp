
#include <bits/stdc++.h>
using namespace std;

long long int v[100010], dp[2][100000010], a, b;

long long int rec(int i, int p){
    if(i == a)return 0;
    if(dp[p][i] != -1)return dp[p][i];
    
    if(p == 1){
        return dp[p][i] = max(rec(i+1, 1), rec(i+1, 0)+v[i]);
    }
    else return dp[p][i] = max(rec(i+1, 1)-v[i]-b, rec(i+1, 0));
}

int main(){

    while(scanf("%d %d", &a, &b) != EOF){
        memset(dp, -1, sizeof dp);
        for(int i = 0;i<a;i++){
            scanf("%d", &v[i]);
        } 
    
     cout << rec(0, 0) << endl;
    }
}
