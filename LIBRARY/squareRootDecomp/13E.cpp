//
// Created by bhagirathi on 5/2/2018.
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

int value[N],jumpTo[N],jumps[N];
int n,m;
void precompute(){
    for (int i = n-1; i >=0 ; i--) {
        int currBucket=i/BLOCK;
        int nextBucket=(i+value[i])/BLOCK;

        //check if it goes out of row
        if((i+value[i])>=n){
            //cout<<"going out\n";
            jumpTo[i]=i+value[i];
            jumps[i]=0;
        }
        else if(currBucket<nextBucket){
            jumpTo[i]=i+value[i];
            jumps[i]=1;
        }
        else if(currBucket==nextBucket){
            jumpTo[i]=jumpTo[i+value[i]];
            jumps[i]=jumps[i+value[i]]+1;
        }
    }
}
void query(int index){
    int ans=0;
    int lastIndex=-1;
    while(index<n){
        if(jumpTo[index]>=n){
            lastIndex=index;
            index=index+value[index];
            ans++;
        }
        else{
            ans+=jumps[index];
            lastIndex=index;
            index=jumpTo[index];
        }
    }
    cout<<(lastIndex+1)<<" "<<ans<<"\n";
}

void modify(int index,int val){
    int bucket=index/BLOCK;
    value[index]=val;
    int i=index;
    while(i>=bucket*BLOCK){
        int currBucket=i/BLOCK;
        int nextBucket=(i+value[i])/BLOCK;

        //check if it goes out of row
        if((i+value[i])>=n){
            //cout<<"going out\n";
            jumpTo[i]=i+value[i];
            jumps[i]=0;
        }
        else if(currBucket<nextBucket){
            jumpTo[i]=i+value[i];
            jumps[i]=1;
        }
        else if(currBucket==nextBucket){
            jumpTo[i]=jumpTo[i+value[i]];
            jumps[i]=jumps[i+value[i]]+1;
        }
        i--;
    }
}

void printTable(){
    for (int j = 0; j <8 ; ++j) {
        cout<<value[j]<<" ";
    }
    cout<<"\n";
    for (int j = 0; j <8 ; ++j) {
        cout<<jumpTo[j]<<" ";
    }
    cout<<"\n";
    for (int j = 0; j <8 ; ++j) {
        cout<<jumps[j]<<" ";
    }
    cout<<"\n";
}

int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/Codechef/EASY/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/Codechef/EASY/output.txt", "w", stdout);
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i = 0; i <n ; ++i) {
        cin>>value[i];
    }
    precompute();
    int type,ind,val;
    for (int j = 0; j <m ; ++j) {
        cin>>type;
        if(type==1){
            cin>>ind;
            query(ind-1);
        }
        else{
            cin>>ind>>val;
            modify(ind-1,val);
        }
    }
    return 0;
}
