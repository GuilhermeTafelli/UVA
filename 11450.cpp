#include<bits/stdc++.h>
using namespace std;

vector <vector <int> > v;
int c, b, dp[210][25];

int rec(int m, int x){

	if(m < 0)return -1000000000;
	if(x == c)return b-m;
	
	if(dp[m][x] != -1)return dp[m][x];
	int ans = -1;
	
	for(int i = 0;i<v[x].size();i++){
		ans = max(ans, rec(m-v[x][i], x+1));
	}
	return dp[m][x] = ans;

}


int main(){
	int a, x, y;
	cin >> a;
	
	while(a--){
			
		cin >> b >> c;
		
		v.clear();
		v.resize(c+1);
		
		for(int i = 0;i<c;i++){
			cin >> x;
			for(int j = 0;j < x;j++){
				cin >> y;
				v[i].push_back(y);
			}
		}
		memset(dp, -1, sizeof(dp));
		int r = rec(b, 0);
		if(r < 0)cout << "no solution" << endl;
		else cout << r << endl;
	}
}
