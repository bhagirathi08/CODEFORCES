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

int n,m,k;
int a[18][18],v[18];
ll dp[1<<18][18];

long long solve(int mask ,int pre){
    if(__builtin_popcount(mask) == m)
        return 0 ;
    long long &ret = dp[mask][pre] ;
    if(ret != -1)
        return ret ;
    ret = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(mask&(1<<i))
            continue ;
        ret = max(ret , solve(mask | (1<<i) , i) + v[i] + a[pre][i] ) ;
    }
    return ret ;
}

int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);
    scanf("%d%d%d",&n,&m,&k) ;
    memset(dp,-1,sizeof(dp)) ;
    for(int i = 0 ; i < n ; i++)scanf("%d",&v[i]) ;
    for(int i = 0 ; i < k ; i++){
        int x , y , z ;
        scanf("%d%d%d",&x,&y,&z) ;
        x-- ;
        y-- ;
        a[x][y] = z ;
    }

    ll ans=0;
    for (int i = 0; i <n ; ++i) {
        ans = max(ans,solve(1<<i,i)+v[i]) ;
    }
    cout<<ans<<"\n";
    return 0;
}