#include<bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int , int> > ip;
typedef pair<int, int> ii;

vector <char> v;
vector <vector<int> > grafo;

int n, vela[30];



int main(){

    char s, x, a, b;
    int cont = 0;
    map <char, int> m;
    
    grafo.resize(30);
    
    while(cin >> s, s != '#'){
        
        
        
        cout << s << " -----" << endl;
        if(m.count(s) == 0)m[s] = cont++;
        cin >> a;
        while(cin >> x, x!= ';'){
   
            if(x == '.'){
                cin >> a >>  b >> n;
                cout << "!" << endl;
            
                bfs(m[a], m[b]);
                grafo.clear();
                break;
            }
   
   
            if(m.count(x) == 0){
                v.push_back(x);
                m[x] = cont;
                cont++;
            }
            cout << x << " " << m[x] << " " << m[s] << endl;
            grafo[m[s]].push_back(m[x]);    
 
        }
    }
}
