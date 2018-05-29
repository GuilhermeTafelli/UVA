#include<bits/stdc++.h>
using namespace std;

int vis[100010], cont = 0;
vector< vector <int> > grafo;

void dfs(int x){
	cont++;
	vis[x] = 1;
	for(int i = 0;i < grafo[x].size();i++){
		int y = grafo[x][i];
		if(vis[y] == 0)dfs(y);
	}
}


int main(){
	int a, x, y, c, b, r = -1;
	cin >> a;
	for(int j = 0;j<a;j++){
		r = -1;
		cin >> b >> c;
		
		grafo.resize(b+2);
		grafo.clear();
		
		for(int i = 0;i<c;i++){
			cin >> x >> y;
			grafo[x].push_back(y);
		}
		memset(vis, 0, sizeof(vis));
		for(int i = 1;i<=b;i++){
			if(vis[i] == 0){
				cont = 0;
				dfs(i);
				cout << cont << endl;
				r = r+cont;
			}
		}
		cout << b-r+1 << endl;
	}
}
