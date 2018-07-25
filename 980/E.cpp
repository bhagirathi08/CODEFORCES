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

const int LOG = 22;
vector<int> adj[MAX];
int parent[MAX][LOG];
int depth[MAX];
bool visit[MAX];
bool included[MAX];
void dfs(int u){
    visit[u]=true;
    for (int i = 0; i <adj[u].size() ; ++i) {
        int v=adj[u][i];
        if(!visit[v]){
            depth[v]=depth[u]+1;
            parent[v][0]=u;
            dfs(v);
        }
    }
}
void preprocess(int n){
    for (int j = 1; j <LOG ; ++j) {
        for (int i = 0; i <n ; ++i) {
            if(parent[i][j-1]!=-1)
                parent[i][j]=parent[parent[i][j-1]][j-1];
        }
    }
}
int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);
    int n,k;
    cin>>n>>k;
    if (k==n-1)
    {
        for (int i=1; i<=k; i++)
        {
            cout << i << ' ';
        }
        return 0;
    }
    int from,to;
    for (int i = 0; i <n-1 ; ++i) {
        cin>>from>>to;
        from--;
        to--;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
        memset(parent, -1, sizeof(parent));
        memset(visit, false, sizeof(visit));
        depth[n-1]=0;
        dfs(n - 1);
        preprocess(n);
        /*for (int i = 0; i <n ; ++i) {
            for (int j = 0; j < 5; ++j) {
                cout << parent[i][j] << " ";
            }
            cout << "\n";
        }*/
        memset(included, false, sizeof(included));
        k=n-k;
        k = k - 1;
        included[n - 1] = true;
        for (int i = n - 2; i >= 0; i--) {
            //cout<<"district: "<<i<<"\n";
            //check if you can take ith district
            int dist = i;
            int notincl = 1;
            if(included[dist])
                continue;
            for (int j = LOG; j >= 0; j--) {
                if (parent[dist][j] != -1 && !included[parent[dist][j]]) {
                    dist = parent[dist][j];
                }
                if((abs(depth[dist]-depth[i])+1)>k)
                    continue;
            }
            notincl+=abs(depth[dist]-depth[i]);
            //cout<<"not incl: "<<notincl<<"\n";
            if (k >= notincl) {
                dist = i;
                while (!included[dist]){
                    //cout<<"dist= "<<dist<<"\n";
                    included[dist] = true;
                    dist = parent[dist][0];
                }
                k -= notincl;
            }
            //cout<<"k= "<<k<<"\n";
            if(k==0)
                break;
        }
        for (int l = 0; l < n; ++l) {
            if (!included[l])
                cout << (l + 1) << " ";
        }
    return 0;
}

