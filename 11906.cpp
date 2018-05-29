#include<bits/stdc++.h>
using namespace std;

typedef pair <int , int > ii;
#define INF 0x3f3f3f3f

long long int x, y, vis[110][110], par = 0, impar = 0, vet[110][110], visit[110][110];
pair<int, int> mod[8];

bool conf(int i, int j){
	if(i < 0 or i >= x or j <0 or j >= y or vet[i][j] == 1)return false;
	return true;
}

void dfs(int i, int j, int cont){
	vis[i][j] = 1;
	for(int x = 0;x<8;x++){
		if(conf(i+mod[x].first, j+mod[x].second)){
			if(vis[i+mod[x].first][j+mod[x].second] == 0){
				dfs(i+mod[x].first, j+mod[x].second, 0);
			}
			cont++;
		}
	}
	//cout << i << " " << " " << j << " " << cont << endl;
	if(cont%2 == 0)par++;
	else impar++;
}

int main(){
	int a, b, h, v, o, p;
	cin >> a;
	for(int i = 0;i<a;i++){
		par = 0, impar = 0;
		cin >> x >> y >> h >> v;
		cin >> b;
		if(h != v)mod[0] = ii(v, h), mod[1] = ii(-v, h), mod[2] = ii(-v, -h), mod[3] = ii(v, -h), mod[4] = ii(h, v), mod[5] = ii(-h, v), mod[6] = ii(-h, -v), mod[7] = ii(h, -v);
		if(h == v)mod[0] = ii(v, h), mod[1] = ii(-v, h), mod[2] = ii(-v, -h), mod[3] = ii(v, -h), mod[4] = ii(INF, INF), mod[5] = ii(INF, INF), mod[6] = ii(INF, INF), mod[7] = ii(INF, INF);
		if(h == 0)mod[0] = ii(v, h), mod[1] = ii(-v, h), mod[2] = ii(h, v), mod[3] = ii(h, -v), mod[4] = ii(INF, INF), mod[5] = ii(INF, INF), mod[6] = ii(INF, INF), mod[7] = ii(INF, INF);
		if(v == 0)mod[0] = ii(v, h), mod[1] = ii(v, -h), mod[2] = ii(h, v), mod[3] = ii(-h, v), mod[4] = ii(INF, INF), mod[5] = ii(INF, INF), mod[6] = ii(INF, INF), mod[7] = ii(INF, INF);	
		memset(vet, 0, sizeof(vet));
		memset(vis, 0, sizeof(vis));
		//cout << "!" << endl;
		for(int j = 0;j<b;j++){
			cin >> o >> p;
			vet[o][p] = 1;
		}
		//cout << "!" << endl;
		dfs(0, 0, 0);	
		//cout << "!" << endl;
		cout << "Case " << i+1 << ": " << par << " " << impar << endl;
	}
}

