#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > grafo;
vector <int> v;

int vis[1100];


void dfs(int x){
	vis[x] = 1;
	for(int i = 0;i< grafo[x].size();i++){
		int y = grafo[x][i];
		if(vis[y] == 0) dfs(y);
	}
	v.push_back(x);
	
}

int main(){
	int a, b, cont = 0, x, y;
	
	while(cin >> a >> b, a|b){
		
		cont = 0;
		memset(vis, 0, sizeof(vis));
		grafo.resize(a+1);
		grafo.clear();
		v.clear();
		
		for(int i = 0;i<b;i++){
			cin >> x >> y;
			grafo[x].push_back(y);
		}
		for(int i = 1;i<=a;i++){
			if(vis[i] == 0)dfs(i);
		}		
				
		for(int i = v.size()-1;i>= 0;i--){
			if(cont == 0){
				cout << v[i];
				cont = 1;	
			}
			else cout << " " << v[i];
		}
		cout << endl;
		
	}

}
