//
// Created by bhagirathi on 6/5/2018.
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

vector<int> adj[MAX];
int parent[MAX];
bool seen[MAX];
int cnt;
void BFS(int x,int y){
    memset(seen,false, sizeof(seen));
    memset(parent,-1, sizeof(parent));
    queue<int> q;
    q.push(x);
    seen[x]=true;
    while(!q.empty()){
        int curr=q.front();
        //cout<<curr<<"\n";
        q.pop();
        if(curr==y)
            break;
        for (int i=0;i<adj[curr].size();i++) {
            int v=adj[curr][i];
            if(!seen[v]){
                seen[v]=true;
                parent[v]=curr;
                q.push(v);
            }
        }
    }
    memset(seen,false, sizeof(seen));
    int node=parent[y];
    while(parent[node]!=-1){
        seen[node]=true;
        node=parent[node];
    }

    /*for (int i = 1; i <10 ; ++i) {
        cout<<"node "<<i<<" : "<<seen[i]<<"\n";
    }*/

}
void DFS(int u){
    seen[u]=true;
    cnt++;
    for(auto v:adj[u]){
        if(!seen[v]){
            DFS(v);
        }
    }
}
int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);
    int n,x,y;
    cin>>n>>x>>y;
    int f,t;
    for (int i = 0; i <n-1 ; ++i) {
        cin>>f>>t;
        adj[f].push_back(t);
        adj[t].push_back(f);
    }
    BFS(x,y);
    cnt=0;
    seen[y]=true;
    DFS(x);
    seen[y]=false;
    int count1=cnt;
    cnt=0;
    seen[x]=true;
    DFS(y);
    int count2=cnt;
    ll ans=(ll)((ll)n*(ll)(n-1))-((ll)count1*(ll)count2);
    printf("%lld",ans);
    return 0;
}


