//
// Created by bhagirathi on 4/23/2018.
//
#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define pi pair<int, int>
#define pii pair<pi,int>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define MAX 100005

const int mod = 1e9+7;
const int mod1 = 1e9+9;

#define N 311111
#define BLOCK 555
#define A 1111111

struct node{
    int L,R,i;
}query[N];
//members
int cnt[A], a[N], ans[N], answer = 0;

bool cmp(node x, node y) {
    if(x.L/BLOCK != y.L/BLOCK) {
        // different blocks, so sort by block.
        return x.L/BLOCK < y.L/BLOCK;
    }
    // same block, so sort by R value
    return x.R < y.R;
}

void add(int pos){
    cnt[a[pos]]++;
    if(cnt[a[pos]]==1)
        answer++;
}
void remove(int pos){
    cnt[a[pos]]--;
    if(cnt[a[pos]]==0)
        answer--;
}

int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/Codechef/EASY/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/Codechef/EASY/output.txt", "w", stdout);
    int n;
    cin>>n;
    for (int i = 0; i <n ; ++i) {
        cin>>a[i];
    }
    int q;
    cin>>q;
    for (int j = 0; j <q ; ++j) {
        cin>>query[j].L;
        cin>>query[j].R;
        query[j].L--;
        query[j].R--;
        query[j].i=j;
    }
    sort(query,query+q,cmp);

    int currentL = 0, currentR = 0;
    for(int i=0; i<q; i++) {
        int L = query[i].L, R = query[i].R;
        while(currentL < L) {
            remove(currentL);
            currentL++;
        }
        while(currentL > L) {
            add(currentL-1);
            currentL--;
        }
        while(currentR <= R) {
            add(currentR);
            currentR++;
        }
        while(currentR > R+1) {
            remove(currentR-1);
            currentR--;
        }
        ans[query[i].i] = answer;
    }

    for(int i=0; i<q; i++)
        printf("%d\n", ans[i]);


}
