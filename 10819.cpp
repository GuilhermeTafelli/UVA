#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

long long int a, b, x, y, dp[110][10000][3];
vector <long long int> p, q;

long long int m(long long int i, long long int rest, int flag){
    
    if(i == b and rest<=a)return 0;
    else if(rest > a and i == b)return -INF;
    if(dp[i][rest] >= 0)return dp[i][rest][flag];    

    long long int k = m(i+1, rest, flag);
    
    long long int op = rest;
    if(rest+p[i] > 2000 and flag){
        op-=200;
        flag = 0;
    }
    if(op+p[i] <=a+200){
        long long int j = q[i]+m(i+1, op+p[i], flag);
        return dp[i][rest][flag] = max(k, j);
    }
    return dp[i][rest][flag] = k;
}





int main(){
    
    while(cin >> a >> b){
        
        p.clear();
        q.clear();
        memset(dp, -1, sizeof dp);
        
        for(long long int i = 0;i<b;i++){
            cin >> x >> y;
            p.push_back(x);
            q.push_back(y);
        }
        long long int r = m(0, 0, 1);
        cout << r << endl;
    }


}
