#include <bits/stdc++.h> 
using namespace std;

typedef pair < int , pair < int, int > > pi;
typedef pair <int, int> ii;
priority_queue <pi, vector <pi>, greater <pi> >  q;
vector < int > v;
int a;

int pai(int x){
	return (v[x] == x) ? x : (v[x] = pai(v[x]));
	
}
void juntar(int i, int j){
	int x = pai(i);
	int y = pai(j);
 	
	v[max(x, y)] = min(x, y);
	return;
}

int kruskal(){
	int cont = 0;
	
	for(int i = 0;i<a;i++){
		v[i] = i;
	}
	
	while(!q.empty()){
		pi topo = q.top();
		q.pop();
		int x = topo.second.first;
		int y = topo.second.second;
		int custo = topo.first;
		
		if(pai(x) == pai(y))continue;

		juntar(x, y);
		cont+= custo;
	}
	return cont;
}


int main(){
	
	int b, x, y, z;

	while(cin >> a >> b, a|b){
		
		int r1 = 0;
		v.clear();
		v.resize(a);
		
		for(int i = 0;i<b;i++){
			cin >> x >> y >> z;
			q.push(make_pair(z, ii(x, y)));
			r1+= z;
		}
		int r = kruskal();
		cout << r1-r << endl;
	}

}
