#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef pair <int, int> ii;
typedef pair <int, ii> pi;
vector <vector <int> > v;
vector <int> mod;
vector <vector < pair < int, ii > > > grafo; 
int dist[100][100];

int djk(int x, int y, int ini){
	priority_queue <pair <int, ii>, vector<pair <int, ii> >, greater <pair <int, ii> > > q; 
	memset(dist, INF, sizeof(dist));
	dist[ini][x] = 0;
	q.push(make_pair(dist[ini][x], ii(ini, x)));
	
	while(!q.empty()){
		pi topo = q.top();
		q.pop();
		int vertice = topo.second.second;
		int distancia = topo.first;
		int elevador = topo.second.first;
		//cout << vertice << " " << distancia << " " << elevador << "-----------------------------"<< endl;
		if(vertice == y)return dist[elevador][vertice];
		for(int i = 0;i<grafo[vertice].size();i++){
			int destino  = grafo[vertice][i].first;
			int custo = grafo[vertice][i].second.second;
			int delevador = grafo[vertice][i].second.first;
			//cout << destino << " " << custo << " " << delevador << endl;		
			if(delevador != elevador and dist[delevador][vertice] > dist[elevador][vertice]+60){
				dist[delevador][vertice] = dist[elevador][vertice]+60;
				if(dist[delevador][destino] > dist[delevador][vertice]+(abs(destino-vertice))*mod[delevador-1]){
					dist[delevador][destino] = dist[delevador][vertice]+(abs(destino-vertice))*mod[delevador-1];
			
					q.push(make_pair(dist[delevador][destino], ii(delevador, destino)));
					//cout << "e1" << endl;
				}
			}
			else if(delevador == elevador and dist[delevador][destino] > dist[elevador][vertice]+(abs(destino-vertice))*mod[delevador-1]){
					dist[delevador][destino] = dist[elevador][vertice]+(abs(destino-vertice))*mod[delevador-1];
					q.push(make_pair(dist[delevador][destino], ii(delevador, destino)));
					//cout << "e2" << endl;
			}
		}
	}
	return -1;
}




int main(){
	
	int a, b, x;
	string s, s1;
	
	while(cin >> a >> b){
		for(int i = 0;i<a;i++){
			cin >> x;
			mod.push_back(x);
		}
		//cout << "!" << endl;
		getchar();
		v.clear();
		grafo.clear();
		v.resize(a);
		grafo.resize(100);
		for(int i = 0;i<a;i++){
			getline(cin, s);
			int t = s.size();
			//cout << "!" << endl;
			for(int j = 0;j<t;j++){
				if(isdigit(s[j])){
					//cout << s[j] << " num" << endl;
					s1+=s[j];
				}
				if(isdigit(s[j]) and j == t-1){
					int n = atoi(s1.data());
					v[i].push_back(n);				
					s1.clear();
					//cout << n << " !" << endl;
				}
				else if(!isdigit(s[j])){
					int n = atoi(s1.data());
					v[i].push_back(n);
					s1.clear();
					//cout << n <<" *"<<endl;
				}
			}
			for(int j = 0;j<v[i].size();j++){
				if(j < v[i].size()-1){
					grafo[v[i][j]].push_back(make_pair(v[i][j+1], ii(i+1, 0)));
					grafo[v[i][j+1]].push_back(make_pair(v[i][j], ii(i+1, 0)));
				}
			}
		}
		int r = INF;
		for(int i = 0;i<grafo[0].size();i++){	
			int e = grafo[0][i].second.first;
			r = min(djk(0, b, e), r);
		}
		cout << r << endl;
		
	}
}
