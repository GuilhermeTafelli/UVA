#include<bits/stdc++.h>
using namespace std;

#define INF 0X3F3F3F3F
int main(){
    int a, b, x;
    cin >> a;
    for(int i = 0;i<a;i++){
        cin >> b;
        
        bool flag = true;
        int ini = -1, fim = -1, soma = 0, ans = 0, inif = -INF, fimf = -INF, u;
        
        for(int j = 0;j<b-1;j++){
        
            cin >> x;
            
            soma+=x;
            u = ans;
            ans = max(soma, ans);
            
            
            if(soma > 0 and flag ==  true){
                ini = j;
                flag = false;
            }
           
            if(soma > 0 and soma == ans){
                
                if(soma > u){
                    fimf = j;
                    inif = ini;
                }
                
                else if(j-ini > fimf-inif){
                    fimf = j;
                    inif = ini;
                }
            }
           
            if(soma < 0){
                soma = 0;
                flag = true;
            }
        }
        if(ans == 0)cout << "Route " << i+1 << " has no nice parts" << endl;
        else cout << "The nicest part of route " << i+1 << " is between stops " << inif+1 << " and " << fimf+2 << endl;
    }
}
