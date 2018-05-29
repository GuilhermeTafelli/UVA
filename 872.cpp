#include<bits/stdc++.h>
using namespace std;

vector < vector <int> > grafo;
vector <int> v1, v2, p;
vector <char> r;
map <char, int> m;

int tx, ty, cont = 0, vis[1000];
string s;

void rec(int cont, int x, int y){
	cout << cont << " " << x << " " << y << endl;
	if(x >= v1.size()/2)return;
	if(cont == tx){
		cout << s << endl;
		return;
	}
	s[cont] = r[v1[x]];
	rec(cont+1, x+1, y);
	
	for(int i = y;i<v2.size();i++){
		s[cont] = r[v2[i]];
		rec(cont+1, x-1, y+1);
	}
}
void dfs(int x){
	vis[x] = 1;
	for(int i = 0;i<grafo[x].size();i++){
		int y = grafo[x][i];
		if(vis[y] == 0)dfs(y);
	}
	v1.push_back(x);
}

int main(){
	int a, s1, s2, sinal;
	string x, y;
	
	cin >> a;
	getchar();
	getchar();
	
	while(a--){
		
		getline(cin, x);
		getline(cin, y);
		
		ty = y.size();
		tx = x.size();
		cout << tx << endl;
		cout << ty << endl;
		grafo.clear();
		grafo.resize((tx/2)+1);
		p.resize((tx/2)+1);
		p.assign(a, 0);
		
		int contador = 0;
		
		for(int i = 0;i<tx;i++){
			if(isalpha(x[i])){
				m[x[i]] = contador;
				contador++;
				r.push_back(x[i]);
			}
		}
		m['<'] = -1;
		for(int i = 0;i<ty;i++){
			if(i%4 == 0)s1 == m[y[i]];
			if(i%4 == 2)s2 = m[y[i]];
			if(i%4 == 3 or i == ty-1){
				if(m[y[i]] == -1){
					grafo[s1].push_back(s2);
					p[s2]++;
				}
			}
		}
		for(int i = 0;i<cont;i++){
			if(vis[i] == 0 and (grafo[i]).size() > 0 or p[i] > 0)dfs(i);
			else 
			
		}
		rec(0, 0, 0);		
	}
}
