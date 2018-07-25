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

int store[105][100005];
vector<int> objects[105];
vector<int> adj[100005];

void bfs(int ind){
    //cout<<"ind: "<<ind<<"\n";
    queue<int> q;
    for (int i = 0; i <objects[ind].size() ; ++i) {
        store[ind][objects[ind][i]]=0;
        //printf("store[%d][objects[%d][%d]]=0\n",ind,ind,i);
        q.push(objects[ind][i]);
    }

    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto frnd:adj[curr]){
            if(store[ind][frnd]==-1){
                store[ind][frnd]=store[ind][curr]+1;
                //printf("store[%d][%d]=%d\n",ind,frnd,store[ind][curr]+1);
                q.push(frnd);
            }
        }
    }
}

int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);
    int n,m,k,s;
    cin>>n>>m>>k>>s;
    int type;
    for (int i = 1; i <=n ; ++i) {
        cin>>type;
        objects[type].push_back(i);
    }

    int f,t;
    for (int i = 0; i <m ; ++i) {
        cin>>f>>t;
        adj[f].push_back(t);
        adj[t].push_back(f);
    }
    memset(store,-1, sizeof(store));
    for (int i = 1; i <=k ; ++i) {
        bfs(i);
    }
    /*for (int i = 1; i <=k ; ++i) {
        for (int j = 1; j <=n ; ++j) {
            cout<<store[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    for (int i = 1; i <=n ; ++i) {
        vector<int> res;
        for (int j = 1; j <=k ; ++j) {
            res.push_back(store[j][i]);
        }
        sort(res.begin(),res.end());
        cout << accumulate(res.begin(), res.begin() + s, 0) << ' ';
    }
    return 0;
}
