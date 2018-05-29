#include <bits/stdc++.h>
using namespace std;

typedef pair < double , pair < long long int, int > > pi;
typedef pair <long long int, long long int> ii;
priority_queue <pi, vector <pi>, greater <pi> >  q;
vector < int > v;

double contf = 0, contr = 0;
int conte, cont, a, b;
	

int pai(int x){
	return (v[x] == x) ? x : (v[x] = pai(v[x]));
}

void juntar(int i, int j){
	
	int x = pai(i);
	int y = pai(j);
	v[max(x, y)] = min(x, y);

}


void kruskal(){
	
	for(int i = 0;i<a;i++){
		v[i] = i;	
	}
//	cout << "*" << endl;
	
	while(!q.empty()){
		pi topo = q.top();
		q.pop();
		
		int x = topo.second.first;
		int y = topo.second.second;
		double custo = topo.first;
		
     //	cout << x << " " << y << " " << custo << endl;
		
		int i = pai(x); 
		int j = pai(y);
		if(i == j)continue;
	//	cout << "!" << endl;
		juntar(x, y);
		
		if(custo > b){
			conte++;
			contf +=custo;
		}
		else contr+= custo;
	}
	return;
}



int main(){

	int n, x, y;
	cin >> n;

	for(int i = 0;i<n;i++){
	
	cin >> a >> b;
		cont = 0, contf = 0, contr = 0, conte = 0;
		vector <pair<long long int, int > > pos;
		v.clear();
		v.resize(a+1);

		map <pair <long long int, long long int>, int > m; 
			

		
		for(int j = 0;j<a;j++){
			cin >> x >> y;
			pos.push_back(ii(x, y));
			m[ii(x, y)] = j;
		}
		
		for(int j = 0;j<a;j++){
			for(int k = j+1;k<a;k++){
				//cout << j << " " << k << endl;
				double dist = sqrt(pow(abs(pos[j].first - pos[k].first), 2) + pow(abs(pos[j].second - pos[k].second), 2));
				//cout << pos[j].first << " " << pos[j].second << " " << pos[k].first << " " << pos[k].second << " " << dist << endl;
				q.push(make_pair(dist, ii(m[ii(pos[j].first, pos[j].second)], m[ii(pos[k].first, pos[k].second)])));	
			}
		}
		//cout << "!" << endl;
		kruskal();
		cout << "Case #" << i+1 << ": " << conte+1 << " " << round(contr) << " " << round(contf) << endl;
	}

}
