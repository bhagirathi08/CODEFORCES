//
// Created by bhagirathi on 6/24/2018.
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

int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);
    while(true){
        int n;
        cin>>n;
        if(n==0)
            break;

        for (int i = 0; i <1000 ; ++i) {
            adj[i].clear();
        }

        while(true){
            int u;
            cin>>u;
            if(u==0)
                break;
            vector<int> numbers;
            string inp;
            getline(cin,inp,' ');
            for (int i = 0; i <numbers.size() ; ++i) {
                adj[u].push_back(numbers[i]);
                adj[numbers[i]].push_back(u);
            }
        }
    }
    return 0;
}


