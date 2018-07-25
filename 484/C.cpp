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
int stree[MAX];
bool seen[MAX];
int ans=0;

void DFS(int u){
    //if it is a leaf
    seen[u]=true;
    int sum=1;
    for (auto v:adj[u]) {
        if(!seen[v]){
            DFS(v);
            sum=sum+stree[v];
        }
    }
    stree[u]=sum;
    if(sum%2==0)
        ans++;
}

int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);
    int n;
    cin>>n;
    int f,t;
    memset(stree,0, sizeof(stree));
    memset(seen,false, sizeof(seen));
    for (int i = 0; i <n-1 ; ++i) {
        cin>>f>>t;
        adj[f].push_back(t);
        adj[t].push_back(f);
    }
    if(n%2==1)
        cout<<"-1";
    else{
        DFS(1);
        /*for (int i = 1; i <=10 ; ++i) {
            cout<<stree[i]<<" ";
        }
        cout<<"\n";*/
        if(stree[1]%2==0)
            ans--;
        cout<<ans;
    }
    return 0;
}
