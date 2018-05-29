 
#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef pair<int, int> ii;

vector <vector <ii> > grafo;
int dist[1000], c;s

bool djk(int x, int y){

	priority_queue < ii, vector < ii >, greater < ii > > q;
	memset(dist, INF, sizeof(dist));
	dist[x] = 0;
	q.push(ii(0, x));

	while(!q.empty()){
		ii topo = q.top();
		q.pop();
		int vertice  = topo.second;
		int distancia = topo.first;
		if(vertice == y and dist[vertice] > c)return false;
		else if(vertice == y)return true;		
		if(distancia > dist[vertice])continue;
		
		for(int i = 0;i<grafo[vertice].size();i++){
			int destino = grafo[vertice][i].first;
			int custo = grafo[vertice][i].second;
			if(dist[destino] > dist[vertice]+custo){
				dist[destino] = dist[vertice]+custo;
				q.push(ii(dist[destino], destino));
			}
		}
	}
	return false;
}

int main(){
	int a, b, d, x, y, z, n;
	cin >> n;
	while(n--){
		getchar();
		int r = 0;
		cin >> a >> b >> c >> d;
		grafo.clear();
		grafo.resize(a+1);
		for(int i =0;i<d;i++){
			cin >> x >> y >> z;
			grafo[x].push_back(ii(y, z));
		}
		for(int i = 1;i<=a;i++){
			if(djk(i, b))r++;			
		}
		cout << r << endl; 
		if(n != 0)cout << endl;
	}
}
