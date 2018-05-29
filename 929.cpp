#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef pair <int, int> ii;
typedef pair <int, ii> pi;

vector <vector <int> > v;
ii mod[] = {ii(-1, 0), ii(1, 0), ii(0, -1), ii(0, 1)};
int dist[1000][1000], b, c;

bool veri(int i, int j){
	if(i < 0 or i >= b or j <0 or j >=c)return false;
	return true;
}

int djk(int iini, int jini, int idest, int jdest){
	priority_queue<pair <int, ii>, vector<pair <int, ii> >, greater<pair <int, ii> > > q;
	memset(dist, INF, sizeof(dist));
	dist[iini][jini] = v[iini][jini];
	q.push(make_pair(v[iini][jini], ii(iini, jini)));	
	while(!q.empty()){
		pi topo = q.top();
		q. pop();
		int x = topo.second.first;
		int y = topo.second.second;
		if(x == idest and y == jdest)return dist[x][y];
		if(topo.first > dist[x][y])continue;
		for(int i = 0;i<4;i++){
			if(veri(x+mod[i].first, y+mod[i].second)){
				int px = x+mod[i].first;
				int py = y+mod[i].second;
				if(dist[px][py] > dist[x][y]+v[px][py]){
					dist[px][py] =	dist[x][y]+v[px][py];
					q.push(make_pair(dist[px][py], ii(px, py)));					
				}
				
			}
		}
	
	}

}

int main(){
	int a, n;
	cin >> a;
	for(int j = 0;j<a;j++){
		cin >> b >> c;
		v.clear();
		v.resize(b);	
		for(int i = 0;i<b;i++){
			for(int k = 0;k<c;k++){
				cin >> n;
				v[i].push_back(n);
			}
		}
		int x = b-1, y = c-1;
		int r = djk(0, 0, b-1, c-1);
		cout << r << endl;
	}
}
