#include<bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair<int, ii> pi;

vector <pi> grafo;
vector < vector<ii> > g;
vector <int> v, r;

int a, b, c, vis[110], maior = -1;

int dfs(int x, int y, int z){
	vis[x] = 1;
	if(x == y){
		sort(r.begin(), r.end());
		maior = r[r.size()-1];
		return maior;
	}
	for(int i = 0;i< g[x].size();i++){
		int w = g[x][i].second;
		int custo = g[x][i].first;
		r.push_back(custo);
		if(vis[w] == 0)dfs(w, y, custo);
		r.pop_back();
	}
	return maior;
}

int pai(int i){

	return (v[i] == i) ? i : (v[i] = pai(v[i]));

}

void junta(int i, int j, int z){

	int x = pai(i);
	int y = pai(j);

	if(x == y)return;
	v[max(x, y)] = min(x, y);
	//cout << i << " " << j <<" : " << x << " " << y << v[x] << " " << v[y] << endl;
	g[i].push_back(ii(z, j));
	g[j].push_back(ii(z, i));
}

void kruskal(){
	
	for(int i = 1;i<=a;i++){
		v[i] = i;
	}
	
	for(int i = 0;i<b;i++){
		int z = grafo[i].first;
		int y = grafo[i].second.second;
		int x = grafo[i].second.first;
		
		junta(x, y, z);
	}	
}


int main(){
	
	int x, y, z, cont = 0;
	
	while(cin >> a >> b  >> c, a|b|c){
	
		cont++;
		grafo.clear();
		g.clear();
		v.clear();
		r.clear();
		grafo.resize(b);
		g.resize(a+1);
		v.resize(a+1);	

	
		for(int i = 0;i<b;i++){
			cin >> x >> y >> z;
			grafo[i] = make_pair(z, ii(x, y));
		}
		
		sort(grafo.begin(), grafo.end());
		kruskal();

		if(cont != 1)cout << endl;
		cout << "Case #" << cont << endl;
		for(int i = 0;i<c;i++){
			cin >> x >> y;
			memset(vis, 0, sizeof(vis));
			maior = -1;
			int result = dfs(x, y, 0);
			if(result != -1)cout << result << endl;
			else cout << "no path" << endl;
		}		
	}
}
