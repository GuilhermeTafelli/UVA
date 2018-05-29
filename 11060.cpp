#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > grafo;
vector <int> v;
vector <string> r;
int grau[1000];
int a, c = 0;

void bfs(){
	priority_queue <int, vector <int>, greater <int> > q;
	for (int i = 0; i < a; i += 1){
		if (grau[i] == 0)q.push(i);
	}
	
	while(!q.empty()){
		int vertice = q.top();
		q.pop();
		v.push_back(vertice);
		for(int i = 0;i<grafo[vertice].size();i++){
			int destino = grafo[vertice][i];
			grau[destino]--;
			if(grau[destino] == 0)q.push(destino);
		} 
	}
}



int main(){
	
	while(cin >> a){
		c++;
		getchar();
		
		r.clear();
		v.clear();
		grafo.clear();
		grafo.resize(a+1);
		memset(grau, 0, sizeof(grau));
		
		int cont = 0, b;
		string s, s1, s2;
		map <string, int> m;
		
		for(int i = 0;i < a; i++){
			getline(cin, s);
			if(m.count(s) == 0){
				m[s] = cont;
				cont++;
			}
			r.push_back(s);
		}
		cin >> b;
		for(int i = 0;i < b; i++){
			cin >> s1 >> s2;
			grafo[m[s1]].push_back(m[s2]);
			grau[m[s2]]++;
		}
	
		bfs();
		cout << "Case #" << c << ": Dilbert should drink beverages in this order:";
		for(int i = 0;i<v.size();i++){
			cout << " " << r[v[i]]; 
		}
		cout << "." << endl;
		cout << endl;
	}
}
