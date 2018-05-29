#include<bits/stdc++.h>
using namespace std;

typedef pair <int, int > ii;
typedef pair <int, ii> pi;


vector <int> v, r;
vector <pi> grafo;

int a, b;

int pai(int x){
	return (v[x] == x) ? x : (v[x] = pai(v[x]));
}

void junta(int i, int j){
	int x = pai(i);
	int y = pai(j);
	
	v[max(x, y)] = min(x, y);
}

void kruskal(){
	
	for(int i = 0;i<a;i++){
		v[i] = i;
	}
	
	for(int i = 0;i<b;i++){
		int x = grafo[i].second.first;
		int y = grafo[i].second.second;
		int z = grafo[i].first;
		int k = pai(x);
		int j = pai(y);
		
		
		if(k == j){
			r.push_back(z);
			continue;
		}
		
		junta(x, y);
	}
}

int main(){
	
	int x, y, z;
	while(cin >> a >> b, a|b){
		
		v.clear();
		v.resize(a+1);
		grafo.clear();
		grafo.resize(b);
		r.clear();
		
		for(int i = 0;i<b;i++){
			cin >> x >> y >> z;
			grafo[i] = (make_pair(z, ii(x, y)));
		}
		
		sort(grafo.begin(), grafo.end());
		kruskal();
		sort(r.begin(), r.end());
		
		if(r.size() == 0)cout << "forest" << endl;
		else {
			for(int i = 0;i<r.size();i++){
				if(i != 0)cout << " " << r[i];
				else cout << r[i];		
			}
			cout << endl;
		}
	}
}
