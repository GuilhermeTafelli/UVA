#include<bits/stdc++.h>
using namespace std;

long long int a, b, x, y, dp[215][50][50], cnt = 0;
vector<long long int> v;

long long int m(long long int i, long long int rest, long long int cont){

    
    if(cont == y and rest%x == 0)return dp[i][cont][rest] = 1;
    if(i == a or cont == y)return 0;
    if(dp[i][cont][rest] != -1)return dp[i][cont][rest];
     
    long long int k = m(i+1, rest, cont);
    long long int j = m(i+1, (rest+v[i])%x, cont+1);
    
    return dp[i][cont][rest] = j+k;
}

 int main(){
    while(cin >> a >> b, a|b){
        cnt++;
        v.clear();
        
        for(long long int i = 0;i<a;i++){
            cin >> x;
            v.push_back(x);
        }
        
        cout << "SET " << cnt << ":" << endl;
        for(long long int i =0;i<b;i++){
            cin >> x >> y;
            memset(dp, -1, sizeof dp);
            long long int r = m(0, 0, 0);
            cout << "QUERY "<< i+1 << ": "<<  r << endl;
        }
    }

}
