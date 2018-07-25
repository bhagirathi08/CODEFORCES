//
// Created by bhagirathi on 6/24/2018.
//

/*
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=154&page=show_problem&problem=945
 */

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

    while(true){
        int n,e;
        cin>>n;
        cin>>e;
        if(n==0)
            break;
        vector<int> adj[n];
        int f,t;
        for (int i = 0; i <e ; ++i) {
            cin>>f>>t;
            adj[f].push_back(t);
            adj[t].push_back(f);
        }

        queue<int> q;
        int color[n];
        memset(color,-1, sizeof(color));
        q.push(0);
        color[0]=0; //0 stands for white, 1 for black

        bool pos=true;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for (int i = 0; i <adj[u].size() ; ++i) {
                int v=adj[u][i];
                if(color[v]==-1){
                    color[v]=1-color[u];
                    q.push(v);
                }
                else if(color[v]==color[u]){
                    pos=false;
                    break;
                }
            }
        }
        if(pos)
            cout<<"BICOLORABLE.\n";
        else
            cout<<"NOT BICOLORABLE.\n";
    }
    return 0;
}
