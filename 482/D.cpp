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
const int MAX = 1E5 + 5;
#define mod1 1e9+7
#define mod2 1e9+9


struct node{
    int mi;
    node* bit[2];
    node(){
        mi=MAX;
        bit[0]=bit[1]= nullptr;
    }
}*tries[MAX];
vector<int> di[MAX];
int q, t, u, k, x, s;
bool chk[MAX];

void init()
{
    for (int i = 1; i < MAX; i++)
    {
        for (int j = i; j < MAX; j += i)
            di[j].push_back(i);
        tries[i] = new node();
    }
}

void add(int k,int u){
    node* cur=tries[k];
    cur->mi=min(cur->mi,u);
    for (int i = 18; i >=0 ; --i) {
        if(cur->bit[u>>i & 1]== nullptr)
            cur->bit[u>>i & 1]=new node();
        cur=cur->bit[u>>i & 1];
        cur->mi=min(cur->mi,u);
    }
}
int query(int x,int k,int s){
    node* cur=tries[k];
    if(x%k!=0 || cur->mi+x>s)
        return -1;
    int ret=0;
    for (int i = 18; i >=0 ; --i) {
        int b=x>>i & 1;
        if(cur->bit[b^1]!= nullptr && cur->bit[b^1]->mi+x<=s){
            ret+=((b^1)<<i);
            cur=cur->bit[b^1];
        }
        else{
            if(cur->bit[b]->mi+x<=s) {
                ret += (b << i);
                cur = cur->bit[b];
            } else
                return -1;
        }
    }
    return ret;
}


int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);
    init();
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d", &u);
            if(!chk[u]){
                chk[u]=true;
                for(int k:di[u]){
                    add(k,u);
                }
            }
        }
        else
        {
            scanf("%d%d%d", &x, &k, &s);
            printf("%d\n", query(x, k, s));
        }
    }
    return 0;
}


