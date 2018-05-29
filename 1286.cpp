#include<bits/stdc++.h>
using namespace std;

int b, dp[40][40], a;
vector <int> q, t;

int m(int i, int rest){
    
    //cout << i << " " << rest << endl;
    if(!rest or i == a)return dp[i][rest] = 0;
    
    if(dp[i][rest] >= 0)return dp[i][rest];
    
    int x = m(i+1, rest);
    
    if(rest >=q[i]){
    
        int y = t[i]+m(i+1, rest-q[i]);
        return dp[i][rest] = max(x, y);
    }
    
    return dp[i][rest] = x;

}


int main(){

    
    while(cin >> a, a!=0){
        cin >> b;
        int x, y;
        q.clear();
        t.clear();
        memset(dp, -1, sizeof dp);
        for(int i = 0;i<a;i++){
            cin >> x >> y;
            q.push_back(y);
            t.push_back(x);
        }
        int r = m(0, b);
        cout << r << " min." <<endl;
    }
}
