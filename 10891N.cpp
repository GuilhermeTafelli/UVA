#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef pair <int, int> ii;
typedef pair <int, ii> pi;

vector <vector <int> > v;
vector <int> mod;
vector < vector < vector < pair < int, int > > > > grafo; 
int dist[6][101];

int djk(int x, int y, int ini){
	priority_queue <pair <int, ii>, vector<pair <int, ii> >, greater <pair <int, ii> > > q; 
	int r = INF;
	
	memset(dist, INF, sizeof(dist));
	dist[ini][x] = 0;
	q.push(make_pair(dist[ini][x], ii(ini, x)));
//	cout << "@" << endl;
	while(!q.empty()){
		pi topo = q.top();
		q.pop();
		int vertice = topo.second.second;
		int distancia = topo.first;
		int elevador = topo.second.first;
		
		//cout << vertice << " " << elevador << " " << distancia << " ------"<< endl;
		
		if(vertice == y)r = min(dist[elevador][vertice], r);
		for(int i = 0;i<grafo[elevador][vertice].size();i++){
			int destino  = grafo[elevador][vertice][i].first;
			int delevador = grafo[elevador][vertice][i].second;
			
	    	//cout << destino << " " << delevador << " " << vertice << " " << elevador << endl;;
			if(destino == vertice and dist[delevador][destino] > dist[elevador][vertice]+60){
				dist[delevador][destino] = dist[elevador][vertice]+60;
				q.push(make_pair(dist[delevador][destino], ii(delevador, destino)));
			//	cout << "e1" << endl;
			}
			else if(destino != vertice and dist[delevador][destino] > dist[elevador][vertice]+(abs(destino-vertice))*mod[delevador-1]){
				dist[delevador][destino] = dist[elevador][vertice]+(abs(destino-vertice))*mod[delevador-1];
				q.push(make_pair(dist[delevador][destino], ii(delevador, destino)));
			//	cout << "e2" << endl;
			}
		}
	}
	return r;
}


int main(){
	
	int a, b, x;
	string s, s1;
	
	while(cin >> a >> b){
		v.clear();
		grafo.clear();
		mod.clear();
		v.resize(a+1);
		grafo.resize(a+1);
		for(int i = 0;i<a;i++){
			cin >> x;
			mod.push_back(x);
		}
		//cout << "!" << endl;
		getchar();
		for(int i = 1;i<=a;i++){
			grafo[i].resize(101);
		}
		
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
					grafo[i+1][v[i][j]].push_back(ii(v[i][j+1], i+1));
					grafo[i+1][v[i][j+1]].push_back(ii(v[i][j], i+1));
				}
			}
		}
	//	cout << "!" << endl;
		for(int  i = 1; i <= 99;i++){
		
			for(int j = 1;j <= a;j++){
				if(!grafo[j][i].empty())
				for(int k = 1;k <= a ;k++){
					if(!grafo[k][i].empty() and k != j){
	//					cout << j << " " << k << " " << i << " ===" << endl;
						grafo[j][i].push_back(ii(i, k));
					}
				}
			}
		}
	//	cout << "!" << endl;
		int r = INF;
		for(int i = 1;i <= a;i++){
	//	cout << "*" << endl;	
			r = min(djk(0, b, i), r);
		}
		if(r != INF)cout << r << endl;
		else cout << "IMPOSSIBLE" << endl;
	}
}
