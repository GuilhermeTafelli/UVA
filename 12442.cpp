#include<bits/stdc++.h>
using namespace std;

vector <vector<int> > grafo;
int cont = 0, vis[50010], visit[50010];
void dfs(int n){
	vis[n] = 1;
	visit[n] = 1;
	cont++;
	for(int i = 0;i<grafo[n].size();i++){
		int w = grafo[n][i];
		if(visit[w] == 0)dfs(w);
	}
}
int main(){
	int a, b, x, y, r, maior;
	scanf("%d", &a);
	for(int i = 0;i<a;i++){
		maior = 0;
		r = -1;
		scanf("%d", &b);
		grafo.clear();
		grafo.resize(b+1);
		for(int j = 0;j<b;j++){
			scanf("%d %d", &x, &y);
			grafo[x].push_back(y);
		}
		memset(vis, 0, sizeof(vis));
		for(int j = 1;j<=b;j++){
			cont = 0;
			memset(visit, 0, sizeof(visit));
			if(vis[j] == 0)dfs(j);
			if(cont > maior){
				maior = cont;
				r = j;
			}
		}
		printf("Case %d: %d\n", i+1, r);
	}

}
