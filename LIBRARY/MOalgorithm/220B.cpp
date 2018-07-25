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
int a[N], ans[N], answer = 0;
unordered_map<int,int> lookup;

bool cmp(node x, node y) {
    if(x.L/BLOCK != y.L/BLOCK) {
        // different blocks, so sort by block.
        return x.L/BLOCK < y.L/BLOCK;
    }
    // same block, so sort by R value
    return x.R < y.R;
}

void add(int pos){
    int key=a[pos];
    //cout<<"ADDING: "<<key<<"\n";
    int value=0;
    if(lookup.find(key)==lookup.end()) {
        lookup[key] = 1;
        value = 1;
    }
    else{
        //cout<<"key: "<<key<<" "<<lookup[key]<<"\n";
        if(key==lookup[key])
            answer--;
        lookup[key]=lookup[key]+1;
        value=lookup[key];
        //cout<<"key: "<<key<<" "<<lookup[key]<<"\n";
    }

    if(key==value)
        answer++;
}
void remove(int pos){
    int key=a[pos];
    //cout<<"REMOVE: "<<key<<"\n";
    int value=0;
    if(lookup.find(key)==lookup.end()) {
        lookup[key] = 0;
        value=0;
    }
    else
        value=lookup[key];
    if(key==value)
        answer--;
    lookup[key]=lookup[key]-1;
    if(key==lookup[key])
        answer++;
}

int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/Codechef/EASY/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/Codechef/EASY/output.txt", "w", stdout);
    int n,q;
    cin>>n>>q;
    for (int i = 0; i <n ; ++i) {
        cin>>a[i];
    }
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
        //cout<<L<<" "<<R<<"\n";
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

        /*cout<<"table: \n";
        for(auto it=lookup.begin();it!=lookup.end();it++){
            cout<<it->first<<" "<<it->second<<"\n";
        }*/

        ans[query[i].i] = answer;
    }

    for(int i=0; i<q; i++)
        printf("%d\n", ans[i]);


}
