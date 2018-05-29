#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef pair <int, int> ii;
typedef pair <int, ii> pi;

vector <vector <vector  <ii>  > > grafo;
int dist[3][1000010]; 
int a, b, c, d, e, x, y, z;

int djk(int k, int p){
	
	int m = -1;
	priority_queue <ii, vector<ii>, greater <ii> > q;
		
	q.push(make_pair(0, k));
	dist[p][k] = 0;
	
	while(!q.empty()){
		
		ii topo = q.top();
		int distancia = topo.first;
		int vertice = topo.second;
		
		//cout << vertice << " " << distancia << endl;
		
		q.pop();
		
		for(int i =0;i<grafo[p][vertice].size();i++){
		    int w = grafo[p][vertice][i].first;
		    int custo = grafo[p][vertice][i].second;
		
		    if(distancia+custo < dist[p][w]){
		        //cout << "enter" << endl;
		        dist[p][w] = distancia+custo;
		        q.push(make_pair(dist[p][w], w));
		        //cout << dist[p][w] << " -!"<< endl;
		    }		
		}
	}
}

int main(){
	int n, r = 0;
	cin >> n;
	for(int i = 0;i<n;i++){
		
		r = -1;
		cin >> a >> b >> c >> d >> e;
		
		grafo.clear();
		grafo.resize(3);
		grafo[0].resize(a+1);
		grafo[1].resize(a+1);
		
		for(int j = 0;j<b;j++){
			cin >> x >> y >> z;
			grafo[0][x].push_back(make_pair(y, z));
			grafo[1][y].push_back(make_pair(x, z));
		}
		 
//		cout << "!" << endl;
	    memset(dist[0], INF, sizeof(dist[0]));
	    djk(c, 0);
	    memset(dist[1], INF, sizeof(dist[1]));
	 //   cout << "!" << endl;
	    djk(d, 1);
		
		
		for(int j = 1;j<=a;j++){
	//	    cout << i << ": " << endl;
            for(int k = 0;k<grafo[0][j].size();k++){
                //cout << dist[0][grafo[0][j][k].first] << " " << grafo[0][j][k].second << " " << dist[1][grafo[0][j][k].first] << endl;  
                if(dist[0][j]+grafo[0][j][k].second+dist[1][grafo[0][j][k].first] <=e and dist[0][j] != INF and dist[1][grafo[0][j][k].first] != INF)r = max(r, grafo[0][j][k].second);
            }
		}
		cout << r << endl;
	}
}
