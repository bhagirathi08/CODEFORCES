//
// Created by bhagirathi on 5/9/2018.
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
#define MAX 200000+10

const int mod = 1e9+7;
const int mod1 = 1e9+9;
vector<int> adj[MAX];
int degree[MAX];
bool visited[MAX];
vector<int> comp;
int n,m;

void dfs(int u){
    visited[u]=true;
    comp.push_back(u);
    for (auto v:adj[u]) {
        if(!visited[v])
            dfs(v);
    }
}

int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);
    cin >> n >> m;
    int u,v;
    for (int i = 0; i <m ; ++i) {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++degree[u];
        ++degree[v];
    }

    int ans=0;
    for (int i = 1; i <=n ; ++i) {
        if(!visited[i]) {
            comp.clear();
            dfs(i);
            bool pos = true;
            for (auto v:comp) {
                if (degree[v] != 2) {
                    pos = false;
                    break;
                }
            }
            if (pos)
                ans++;
        }
    }
    cout<<ans;

    return 0;
}