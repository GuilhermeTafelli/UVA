#include<bits/stdc++.h>
using namespace std;
vector <int> v, vet, n, r;
int tamanho, b, maior = 1000000;

void rec(int soma, int i){
    soma+=v[i];
    vet.push_back(soma);
    n.push_back(v[i]);
    if(tamanho-soma  < maior and tamanho-soma >= 0){
        maior = tamanho-soma;
        r = n;
    }
    if(i == b-1){
        n.pop_back();
        return;
    }
    rec(soma, i+1);
    n.pop_back();
    rec(soma-v[i], i+1);
}

int main(){
    int a;
    while(cin >> tamanho >> b){
    maior = 10000000;
    v.clear();
    vet.clear();
    n.clear();
    r.clear();
    int i, x;
        for(i = 0;i<b;i++){
            cin >> x;
            v.push_back(x); 
        }
        rec(0, 0);

        for(i = 0;i<r.size();i++){
            cout << r[i] << " ";
        }
        cout << "sum:"<<tamanho-maior << endl;
    }
}
