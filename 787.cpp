#include<bits/stdc++.h>

using namespace std;

int main()
{

    while(1)
    {
        int mx[200];

        int i=0,n;

        while((cin>>n)&&(n!=-999999))
        {
            mx[i++]=n;
        }

        long sum=1,mxV=-999999;

        for(int j=0;j<i;j++)
        {
            sum=1;
            for(int k=j;k<i;k++)
            {
                sum=sum*mx[k];
            }
            if(mxV<sum)mxV=sum;
        }
        printf("%ld\n",mxV);


    }
    return 0;
}

/*#include<bits/stdc++.h>
using namespace std;

int main(){

    unsigned long long int i, x, y;
    while(cin >> x){

        vector <unsigned long long int> v;
        unsigned long long int s = 1, maior = -100000000;
        
        v.push_back(x);
        while(cin >> y, y!= -999999){
            v.push_back(y);
        }
        
        for(int i = 0;i<v.size();i++){
            s = 1;
            for(int j = i;j<v.size();j++){
                s*=v[j];
                if(s > maior)maior = s;
            }
        }
        cout << maior << endl;    
    }

}
*/
