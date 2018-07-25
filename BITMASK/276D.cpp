//
// Created by bhagirathi on 6/25/2018.
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
int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);
    ll l,r;
    cin>>l>>r;

    ll diff=r-l;
    ll p=1;
    ll ans=0;
    int pos=0;
    while(diff>=p){
        ans+=p;
        p=p*2;
        pos++;
    }
    while(r>=p){
        if(((l>>pos)^(r>>pos))&(ll)1==(ll)1)
            ans+=p;
        p=p*2;
        pos++;

    }
    cout<<ans<<"\n";
    return 0;
}


