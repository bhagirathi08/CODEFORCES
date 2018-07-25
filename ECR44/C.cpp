//
// Created by bhagirathi on 6/8/2018.
//
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define f(i,a,b) for(int i = (a); i <= (b); i++)
#define fd(i,a,b) for(int i = (a); i >= (b); i--)
#define MAX 1000005
#define mod1 1e9+7
#define mod2 1e9+9

int min(int x,int y){
    if(x<y)
        return x;
    else
        return y;
}
int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);
    ll n,k,l;
    cin>>n>>k>>l;
    ll arr[n*k];
    ll num;
    for (int i = 0; i <n*k ; ++i) {
        cin>>num;
        arr[i]=num;
    }
    sort(arr,arr+n*k);
    int m=n*k;
    int rg=upper_bound(arr,arr+n*k,arr[0]+l)-arr;
    if(rg<n){
        cout<<"0";
    }
    else{
        int ind=0;
        ll ans=0;
        for (int i = 0; i <n ; ++i) {
            ans+=arr[ind++];
            for (int j = 0; j <k-1 ; ++j) {
                if(rg-ind>n-i-1)
                    ind++;
                else
                    break;
            }
        }
        printf("%lld",ans);
    }

    return 0;
}

