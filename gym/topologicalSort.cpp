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
#define MAX 101

const int mod = 1e9+7;
const int mod1 = 1e9+9;
int n,order[MAX],in_degree[MAX];
vector<int> adj[MAX];

void topological_order(){
    int head=0,tail=0;
    for (int i = 0; i <n ; ++i) {
        if(!in_degree[i])
            order[tail++]=i;
    }
    while(head<tail){
        int v=order[head++];
        for (int i = 0; i <adj[v].size() ; ++i) {
            int w=adj[v][i];
            if(!(--in_degree[w]))
                order[tail++]=w;
        }
    }
}

int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);
    cin>>n;
    vector<lli> num(n);
    for (int i = 0; i <n ; ++i) {
        cin>>num[i];
        for (int j = 0; j <i ; ++j) {
            if(num[ i ] == 2 * num[ j ] || (num[ j ] % 3 == 0 && num[ i ] == num[ j ] / 3)){
                adj[ j ].push_back(i);
                in_degree[ i ]++;
            }
            else if(num[ j ] == 2 * num[ i ] || (num[ i ] % 3 == 0 && num[ j ] == num[ i ] / 3)){
                adj[ i ].push_back(j);
                in_degree[ j ]++;
            }
        }
    }

    topological_order();
    for(int i = 0 ; i < n ; i++)
        cout << num[ order[ i ] ] << ' ';
    cout << endl;
    return 0;
}