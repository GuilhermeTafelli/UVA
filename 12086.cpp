#include <bits/stdc++.h>
using namespace std;

#define INF 200010

vector <long long int> v, vet;
int a;

void update(int pos, int x){
	for(int i = pos;i<INF;i+= (i & -i)){
		v[i]+= x;
	}
}

long long int soma(int x){
	
	long long int cont = 0;
	for(;x;x -=(x & -x)){
		cont +=v[x];
	}
	//cout << cont << endl;
	return cont;
}

int main(){
	int x, y, casos = 0;
	string s;
	while(cin >> a, a){
		
		casos++;
		
		if(casos != 1)cout << endl;
		
		v.clear();
		v.assign(INF, 0);
		vet.clear();
		
		for(int i = 1;i<=a;i++){
			cin >> x;
			vet.push_back(x);
			update(i, x);
		}
		cout << "Case " << casos << ":"<< endl;
		while(cin >> s, s != "END"){
			cin >> x >> y;
			if(s == "M"){
				long long int r = soma(y)- soma(x-1);
				cout << r << endl;	
			}
			else {
				long int d = vet[x-1];
				vet[x-1] = y;
				update(x, y-d);
			}
		}
			
	}
}
