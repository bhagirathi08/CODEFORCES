//
// Created by bhagirathi on 5/16/2018.
//
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define MAX 1000005
#define mod1 1e9+7
#define mod2 1e9+9

class UnionFind{
private:
    vi p,rank;
public:
    UnionFind(int N){
        rank.assign(N,0);
        p.assign(N,0);
        for (int i = 0; i <N ; ++i) {
            p[i]=i;
        }
    }
    int findSet(int i){
        return p[i]==i?i:(p[i]=findSet(p[i])); //path compression
    }
    bool isSameSet(int i,int j){
        return findSet(i)==findSet(j);
    }
    void unionSet(int i,int j){
        if(!isSameSet(i,j)){
            int x=findSet(i);
            int y=findSet(j);
            if(rank[x]>rank[y])
                p[y]=x;
            else{
                p[x]=y;
                if(rank[x]==rank[y])
                    rank[y]++;
            }
        }
    }
};

int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);

    return 0;
}
