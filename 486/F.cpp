//
// Created by bhagirathi on 6/3/2018.
//
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define MAX 1000005
#define mod1 1e9+7
#define mod2 1e9+9
#define INF 1000000000
int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);
    int a,n,m;
    cin >>a>>n>>m;
    bool rain[a+5];
    memset(rain,false,sizeof(rain));
    int l,r;
    for (int i = 0; i <n ; ++i) {
        cin>>l>>r;
        for (int j = l; j <r ; ++j) {
            rain[j]=true;
        }
    }

    vector<int> umb(a+5);
    umb.assign(a+5,-1);
    int p,w;
    for (int k = 0; k <m ; ++k) {
        cin>>p>>w;
        if(umb[p]==-1 || umb[p]>w)
            umb[p]=w;
    }


    ll dp[a+5][a+5];
    memset(dp,INF, sizeof(dp));
    dp[0][0]=0;
    for (int i = 0; i <a ; ++i) {
        for (int j = 0; j <=m ; ++j) {
            if(dp[i][j]==INF)
                continue;
            if(!rain[i]){
                dp[i+1][m]=min(dp[i+1][m],dp[i][j]);
            }
            if(j<m){
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + umb[j]);
            }
        }
    }

    return 0;
}

