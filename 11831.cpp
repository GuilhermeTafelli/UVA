#include<bits/stdc++.h>
using namespace std;
int main();

int a, b, c;
typedef pair<int, int> ii;
pair<int, int> ini, cord;
int cont;
char v[10000][10000];
void caminho(int i, int j){
	if(i < 0 or i >= a or j <0 or j >= b or v[i][j] == '#'){
		return;
	}
	if(v[i][j] == '*'){
		cont++;
		ini = make_pair(i, j);
		v[i][j] = '.';
	}
	else ini = make_pair(i, j);
	return;
}


int main(){
	while(cin >> a >> b >> c, a|b|c){
		cont = 0;
		getchar();
		for(int i = 0;i<a;i++){
			for(int j = 0;j<b;j++){
				cin >> v[i][j];
				if(isalpha(v[i][j])){
					ini = make_pair(i, j);
					if(v[i][j] == 'N')cord = make_pair(-1, 0);
					if(v[i][j] == 'S')cord = make_pair(1, 0);
					if(v[i][j] == 'L')cord = make_pair(0, 1);
					if(v[i][j] == 'O')cord = make_pair(0, -1);
					v[i][j] = '.';
				}	
			}
			getchar();
		}
		string x;
		getline(cin, x);
		for(int i = 0;i<c;i++){			
			if(x[i] == 'F')caminho(ini.first+cord.first, ini.second + cord.second);
			if(x[i] == 'E'){
				if(cord == ii(-1, 0))cord = make_pair(0, -1);
				else if(cord == ii(0, -1))cord = make_pair(1, 0);
				else if(cord == ii(1, 0))cord = make_pair(0, 1);
				else if(cord == ii(0, 1))cord = make_pair(-1, 0);
			}
			if(x[i] == 'D'){
				if(cord == ii(-1, 0))cord = make_pair(0, 1);
				else if(cord == ii(0, 1))cord = make_pair(1, 0);
				else if(cord == ii(1, 0))cord = make_pair(0, -1);
				else if(cord == ii(0, -1))cord = make_pair(-1, 0);
			}
		}
		cout << cont << endl;
	}
}



