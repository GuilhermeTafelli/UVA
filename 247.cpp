#include<bits/stdc++.h>
using namespace std;

vector <int> num, visited, low, s;
vector <vector <int> > r, grafo;
int cont = 0, contr = 0, contssc = 0, contt = 0, contn = 0;

void tarjan(int x){
	low[x] = num[x] = contssc++;
	visited[x] = 1;
	s.push_back(x);
	
	for(int i = 0;i<grafo[x].size();i++){
		int y = grafo[x][i];
		if(num[y] == -1){
			tarjan(y);
		}
		if(visited[y]){
			low[x] = min(low[x], low[y]);
		}
	}
	if(low[x] == num[x]){
		contn = 0;
		while(1){
			contn++;
			int z = s.back();
			s.pop_back();
			visited[z] = 0;
			r[contt].push_back(z);
			if(x == z){
				if(contn > 1)contr++;
				break;
			}
		}
		contt++;
	}
	
}


int main(){
	int a, b, w = 0;
	string x, y;
	while(cin >> a >> b, a|b){
		
		if(w != 0)cout << endl;
		w++;
		
		map <string, int> m;
		map <int, string> p;
		
		low.clear();
		num.clear();
		visited.clear();
		grafo.clear();
		r.clear();
		low.resize(a+2);
		num.resize(a+2);
		visited.resize(a+2);
		r.resize(a+2);
		grafo.resize(a+2);
		
		
		for(int i = 0;i<b;i++){
			cin >> x >> y;
			if(m.count(x) == 0){
				m[x] = cont;
				p[cont] = x;
				cont++;		
			}
			if(m.count(y) == 0){
				m[y] = cont;
				p[cont] = y;
				cont++;		
			}
			grafo[m[x]].push_back(m[y]);
			
		}
		
		low.assign(a, 0);
		num.assign(a, -1);
		visited.assign(a, 0);
		cont = 0, contr = 0, contssc = 0, contt = 0, contn = 0;
			
		for(int i = 0;i<a;i++){
			if(num[i] == -1){
				tarjan(i);		
			}
		}
		cout << "Calling circles for data set "<< w << ":" << endl;
		for(int i = contt-1;i>= 0;i--){
			for(int j = r[i].size()-1;j >= 0;j--){
				if(j != r[i].size()-1)cout << ", " << p[r[i][j]];
				else cout << p[r[i][j]];
			}
			cout << endl;			
		}
	}
}
