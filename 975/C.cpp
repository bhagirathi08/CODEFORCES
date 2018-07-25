#include <bits/stdc++.h>
using namespace std;
long long  a[200001],k[200001],sum,mkan,n,q;
int main()
{
    cin >> n >> q;
    for(int i=0;i<n;++i){
        cin >> a[i];
        if(i)a[i]+=a[i-1];
    }
    for(int i=0;i<q;++i)
        cin >> k[i];
    for(int i=0;i<q;++i){
        sum+=k[i];
        mkan=upper_bound(a,a+n,sum)-a;
        if(mkan==n){sum=0;cout<<n<<endl;continue;}
        cout<<n-mkan<<endl;
    }
}