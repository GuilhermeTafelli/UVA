#include<bits/stdc++.h>
using namespace std;
vector <int> v;
bool rec(int s, int j){ 
    if(j == 4) return (s == 23) ? true : false;
    if (rec(s * v[j+1], j+1)) return true;
    if (rec(s + v[j+1], j+1)) return true;
    if (rec(s - v[j+1], j+1)) return true;
}

int main(){
    int a, b, c, d, e, i;
    while(cin >> a >> b >> c >> d >> e , a, b, c, d, e){
        v.push_back(a);
        v.push_back(b); 
        v.push_back(c);
        v.push_back(d);
        v.push_back(e);
        sort(v.begin(), v.end());
        bool x = false;
        do{
            x = rec(v[0], 0);
            if(x == true)
                break;
        } while(next_permutation(v.begin(), v.end()));
        
        if(x){
            cout << "Possible" << endl;
        }
        else cout << "Impossible" << endl;
        v.clear();
    }


} 
