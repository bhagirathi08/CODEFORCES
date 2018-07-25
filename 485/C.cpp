//
// Created by bhagirathi on 6/4/2018.
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

const int INF = 1000000005;
int DP[3005][5], S[3005], C[3005], N;

int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);
    cin >> N;
    f(i,1,N)
        cin >> S[i];
    f(i,1,N)
        cin >> C[i];
    /*f(i,1,N)
        f(j,0,3)
            DP[i][j] = INF;
    f(i,1,N)
        DP[i][1] = C[i];
    f(i,1,N)
        f(j,i+1,N)
            if(S[j] > S[i])
                DP[j][2] = min(DP[j][2], DP[i][1] + C[j]);
    f(i,1,N)
        f(j,i+1,N)
            if(S[j] > S[i])
                DP[j][3] = min(DP[j][3], DP[i][2] + C[j]);
    int ans = INF;
    f(i,1,N)
        ans = min(ans, DP[i][3]);
    if(ans < INF)
        cout << ans;
    else
        cout << -1;*/
    int ans=INF;
    for (int i =2 ; i <=N ; ++i) {
        int lcost=INF;
        for (int l = 1; l <i ; ++l) {
            if(S[l]<S[i])
                lcost=min(lcost,C[l]);
        }
        int rcost=INF;
        for (int r = i+1; r <=N ; ++r) {
            if(S[r]>S[i])
                rcost=min(rcost,C[r]);
        }
        if(rcost!=INF && lcost!=INF) {
            ans = min(ans, lcost + rcost + C[i]);
            //cout<<"at: "<<i<<" = "<<ans<<"\n";
        }
    }
    if(ans==INF)
        cout<<"-1";
    else
        cout<<ans;
    return 0;
}


