#include<bits/stdc++.h>
using namespace std;

int a, b, c, dp[1000];

int source(int i, int v){
    
    cout << v << " " << i << endl;
    if(v > c)return i;
    

}

int main(){
    
    while(cin >> a >> b >> c){
        memset(dp, -1, sizeof dp);
        int r = source(0, 0);
        cout << r << endl;
    }

}


/* (i, v){i+1, v-a;
         {i+1, v-b;
         i = posiçao vetor[c];
         
*/
