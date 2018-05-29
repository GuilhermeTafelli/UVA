#include <bits/stdc++.h>
using namespace std;


#define INF 0x3f3f3f3f
typedef pair <long long int, long long int> ii;

vector <vector <ii> > grafo;
long long int dist[20010];

bool djk(long long int x, long long int y){
	
	priority_queue <ii, vector <ii>, greater <ii> > q;
	memset(dist, INF, sizeof(dist));
	dist[x] = 0;
	q.push(ii(dist[x], x));
	
	while(!q.empty()){
		ii topo = q.top();
		q.pop();
		long long int vertice = topo.second;
		long long int distancia = topo.first;
		if(distancia > dist[vertice])continue;
		if(vertice == y)return true;
		for(long long int i = 0;i<grafo[vertice].size();i++){
			long long int destino = grafo[vertice][i].first;
			long long int custo = grafo[vertice][i].second;
			if(dist[destino] > dist[vertice]+custo){
				dist[destino] = dist[vertice]+custo;
				q.push(ii(dist[destino], destino));
			}
		}
	}
	return false;
}

int main(){
	
	long long int n, a, b, c, d, x, y, z;
	cin >> n;
	
	for(long long int i = 0;i<n;i++){
		cin >> a >> b >> c >> d;
		grafo.clear();
		grafo.resize(a);
		for(long long int j = 0;j<b;j++){
			cin >> x >> y >> z;
			grafo[x].push_back(ii(y, z));
			grafo[y].push_back(ii(x, z));
		}

		cout << "Case #" <<i+1 << ": "; 
		if(djk(c, d))cout << dist[d] << endl;
		else cout << "unreachable" << endl;
	}

}
