#include<bits/stdc++.h>
using namespace std;

int nivel[5010], dp[5010][31], pai[5010], r;
vector <vector <int> > grafo; 


int dfs(int a){
    dp[a][0] = pai[a];
    
    for(int j = 1;j<26;j++){
        dp[a][j] = dp[dp[a][j-1]][j-1];
    }
    
    for(int i = 0;i<grafo[a].size();i++){
        int w = grafo[a][i];
        if(pai[a] != w){
            pai[w] = a;
            nivel[w] = nivel[a]+1;
            dfs(w);
        }
    }
}

void lca(int x, int y){
    if(nivel[x] > nivel[y])swap(x, y);
    int k = y;
    
    r+= (nivel[y]-nivel[x]);
    for(int j = 24;j>=0;j--){
        if(nivel[y]-nivel[x] >= (1 << j)){
            y = dp[y][j];
            //cout << "!" << endl;
        }
    }
    
    if(x != y)r+=2;
    
    
    for(int j = 24;j>=0;j--){
        if(dp[y][j] != dp[x][j]){
            y = dp[y][j];
            x = dp[x][j];
            r+=(1 << j)*2;
        }
    }
    
    int t = r/2;
 //   cout << t << endl;
    for(int j = 24;j>=0;j--){
        if(t >= (1 << j)){
            k = dp[k][j];
            t -=(1 << j);
        }
    }
    
    if(r%2 == 1)cout << "The fleas jump forever between " << min(k, pai[k]) << " and "<< max(k, pai[k]) << "." << endl;
    else cout << "The fleas meet at " << k << "." << endl;
}

int main(){
    int a, v = 0;
    while(cin >> a, a){
        //cout << a << endl;
        int x, y;
        grafo.clear();
        grafo.resize(a+2);
        r = 0;
        for(int i = 0;i<a-1;i++){
            cin >> x >> y;
          //  cout << x << " " << y << endl;
            grafo[x].push_back(y);
            grafo[y].push_back(x);
        }
        
        pai[1] = 0;
        nivel[1] = 0;
        dfs(1);
        
        cin >> a;
        //cout << a << "-" << endl;
        for(int i = 0;i<a;i++){
            r = 0;
            cin >> x >> y;
            //cout << x << " " << y << endl;
            v++;
            lca(x, y);
            //if(v == 828)cout << "-----------------------------" << endl;
        }
    }
}
