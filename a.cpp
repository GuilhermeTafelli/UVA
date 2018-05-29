#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef pair <int, int> ii;
typedef pair <int, ii> pi;

vector <vector <ii> > grafo;
int dist[1000][1000]; 
int a, b, c, d, e, x, y, z;

int djk(int k, int j){
	
	int m = -1;
	priority_queue <pi, vector<pi>, greater <pi> > q;
		
	q.push(make_pair(0, ii(k, -1)));
	memset(dist, INF, sizeof(dist));
	
	while(!q.empty()){
		
		pi topo = q.top();
		q.pop();
		int x = topo.second.first;
		int maior = topo.second.second;
		int distancia = topo.first;
		
		//cout << x << " " << maior << " ---"<< endl;
		
		if(x == j and maior > m){
			m = maior;
			continue;	
		}
		for(int i = 0;i<grafo[x].size();i++){
		
			int y = grafo[x][i].first;
			int custo = grafo[x][i].second;
			
		//	cout << y << endl;
			
			int aux;
			
			if(maior > custo)aux = maior;
			else aux = custo;
			
			if(distancia+custo <= e and dist[y][aux] > distancia+custo){
				dist[y][aux] = distancia+custo;
				q.push(make_pair(dist[y][aux], ii(y, aux)));
			}
		}
	}
	return m;
}



int main(){
	int n, r = -1;
	cin >> n;
	for(int i = 0;i<n;i++){
		
		r = -1;
		cin >> a >> b >> c >> d >> e;
		
		grafo.clear();
		grafo.resize(a+1);
		
		for(int j = 0;j<b;j++){
			cin >> x >> y >> z;
			grafo[x].push_back(ii(y, z));
		}
	//	cout << "!" << endl;
		for(int j = 1;j<=a;j++){
			r = max(djk(j, d), r);
		}
		cout << r << endl;
	}
}
