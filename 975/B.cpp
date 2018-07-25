//
// Created by bhagirathi on 5/7/2018.
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
#define MAX 100005

const int mod = 1e9+7;
const int mod1 = 1e9+9;

int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);

    int n=14;
    int board[n];
    for (int i = 0; i <n ; ++i) {
        cin>>board[i];
    }

    lli ans=0;
    for (int i = 0; i <14 ; ++i) {
        lli currAns=0;
        if(board[i]>0){
            //cout<<"i= "<<i<<"\n";
            int add=board[i]/n;
            int j=(i+1)%14;
            int remain=board[i]-(add*n);

            lli curr=add;
            //cout<<curr<<"\n";

            if(curr%2==0)
                currAns=curr;
            while(j!=i){
                curr=board[j]+add;
                if(remain>0) {
                    remain--;
                    curr++;
                }
                //cout<<"curr= "<<curr<<"\n";
                if(curr%2==0)
                    currAns+=curr;
                j=(j+1)%14;
            }
        }
        ans=max(ans,currAns);
    }
    cout<<ans;

    return 0;
}
