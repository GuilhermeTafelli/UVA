#include<bits/stdc++.h>
using namespace std;

int main(){

    int a;
    while(cin >> a, a != 0){
        
        int soma = 0, ans = 0, x;
        
        for(int i = 0;i<a;i++){
            cin >> x;
            
            soma+=x;
            
            ans = max(soma, ans);
            
            if(soma < 0)soma = 0;
        }
    
        if(ans > 0)cout << "The maximum winning streak is " << ans << "." << endl;
        else cout << "Losing streak." << endl;
    }
}
