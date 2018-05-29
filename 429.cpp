#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int dist[10000];
vector < vector <int> > grafo;
int bfs(int x, int y){
	queue <int> q;	
	memset(dist, INF, sizeof(dist));
	dist[x] = 0;
	q.push(x);
	while(!q.empty()){
		int w = q.front();
		q.pop();
		for(int i = 0;i<grafo[w].size();i++){
			int z = grafo[w][i];
//			cout << z << endl;
			if(dist[z] > dist[w]+1){
				dist[z] = dist[w]+1;
				q.push(z);
			}
			if(z == y)return dist[z];
		}
	}	
}
bool veri(string x, string y, int t){
	int r = 0;
	if(x == y)return false;
	for(int i = 0;i<t;i++){
		if(x[i] != y[i])r++;
	}
	if(r == 1)return true;
	else return false;
}

int main(){
	int a;
	cin >> a;
	getchar();
	getchar();
	for(int i = 0;i<a;i++){
		int cont = 0;
		map <string, int> m;
		vector <vector <string> > v;
		vector <string> vet;
		v.resize(12);
		grafo.resize(210);
		grafo.clear();
		string x, y, s;
		while(cin >> s, s!= "*"){
			int t = s.size();
			v[t].push_back(s);
			vet.push_back(s);
			m[s] = cont;
			cont++;
		}
		for(int j = 0;j<cont;j++){
			int t = vet[j].size();
			for(int k = 0;k<v[t].size();k++){
				if(veri(vet[j], v[t][k], t)){
					grafo[m[vet[j]]].push_back(m[v[t][k]]);
//					cout << vet[j] << " " << v[t][k] << endl;
				}
			}
		}
		getchar();
		if(i != 0)cout << endl;
		while(getline(cin, x) and !x.empty()){
			string s1, s2;
			bool flag = true;
			for(int j = 0;j<x.size();j++){
				if(x[j] == ' ')flag = false;
				else if(flag)s1+=x[j];
				else s2+=x[j];			
			}
			int r = bfs(m[s1], m[s2]);	
			cout << s1 << " " << s2 << " " << r << endl;
		}
	}
}
