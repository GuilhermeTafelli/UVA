#include<bits/stdc++.h>
using namespace std;

typedef pair <long long int, long long int> ii;
typedef pair <double, ii> ip;

vector <ip> r;
vector <long long int> v;

long long int a, b;

int pai(int x){
	return (v[x] == x) ? x : (v[x] = pai(v[x]));
}

void juntar(int i, int j){

	int x = pai(i);
	int y = pai(j);
	
	v[max(x, y)] = min(x, y);
	return;
}

double kruskal(){
	double maior = 0;
	int k = 0;
	for(int i = 0;i<b;i++){
		v[i] = i;
	}
	//cout << r.size()<< endl;
	for(int i = 0;i<r.size();i++){
		int x = r[i].second.first;
		int y = r[i].second.second;
		double custo = r[i].first;
		//cout << x << " " << y << " " << custo << endl;
		if(pai(x) == pai(y))continue;
		juntar(x, y);
		if(k == b-a-1)maior = custo;
		k++;
	}
	return maior;
}


int main(){
	
	int n, x, y;
	cin >> n;
	
	while(n--){
	
		map <ii, long long int> m;
		vector <ii> pos; 	
		int vis[100000], k = 0, cont;
		memset(vis, 1, sizeof(vis));
		r.clear();
		v.clear();
		pos.resize(b+3);
		v.resize(b+3);
		
		cin >> a >> b;
		for(int i = 0;i<b;i++){
			cin >> x >> y;
			pos.push_back(ii(x, y));
			m[ii(x, y)] = i;
		}
		for(int i = 0;i<b;i++){
			for(int j = i+1;j<b;j++){
			long long double dist = sqrt(pow(pos[i].first-pos[j].first, 2)+pow(pos[i].second-pos[j].second, 2));
				r.push_back(make_pair(dist, ii(m[ii(pos[i].first, pos[i].second)], m[ii(pos[j].first, pos[j].second)])));
			}	
		}

		sort(r.begin(), r.end());
		//cout << "@" << endl;
		long double resp = kruskal();
		cout.precision(2);
		cout << fixed << resp << endl;
	}
}
