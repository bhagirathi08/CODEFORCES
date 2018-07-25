//
// Created by bhagirathi on 5/11/2018.
//
#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define pi pair<li, li>
#define pii pair<pi,int>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define MAX 1000005

const int mod = 1e9+7;
const int mod1 = 1e9+9;

const int LOG=20;
vector<int> adj[MAX];
int level[MAX];
bool visited[MAX];
int parent[MAX][LOG];

void dfs(int u){
    visited[u]=true;
    for (int v = 0; v <adj[u].size() ; ++v) {
        if(!visited[adj[u][v]]){
            parent[adj[u][v]][0]=u;
            level[adj[u][v]]=level[u]+1;
            dfs(adj[u][v]);
        }
    }
}
void prepreocess(int n){
    for (int j = 1; j <LOG ; ++j) {
        for (int i = 0; i<n ; ++i) {
            if(parent[i][j-1]!=-1)
                parent[i][j]=parent[parent[i][j-1]][j-1];
        }
    }
}
int lca(int u,int v)
{
    if(level[u] < level[v]) {
        int temp = u;
        u = v;
        v = temp;
    }

    int diff=level[u] - level[v];
    //lifting u up by diff in O(log n) time
    for(int i=0;i<=LOG;i++)
        if((diff>>i) & 1)
            u = parent[u][i];
    if(u != v)
    {
        for(int i=LOG-1;i>=0;i--)
        {
            if(parent[u][i] != parent[v][i])
            {
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        u = parent[u][0];
    }
    return u;
}
int query(int a,int b,int c)
{
    int x=lca(a,b);
    int y=lca(b,c);
    int z=lca(c,a);

    if(x == y)
        return z;
    if(y == z)
        return x;
    return y;
}
int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);
    int n;
    cin>>n;
    int from,to;
    for (int i = 0; i <n-1 ; ++i) {
        cin>>from>>to;
        from--;
        to--;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    level[0]=0;
    memset(visited,false,sizeof(visited));
    memset(parent,-1, sizeof(parent));
    dfs(0);
    prepreocess(n);

    /*for (int i = 0; i <n ; ++i) {
        for (int j = 0; j <5 ; ++j) {
            cout<<parent[i][j]<<" ";
        }
        cout<<"\n";
    }*/

    int q;
    cin>>q;
    while(q--){
        int r,u,v;
        cin>>r>>u>>v;
        r--;
        u--;
        v--;
        cout<<query(r,u,v)+1<<"\n";
    }
    return 0;
}

