//
// Created by bhagirathi on 5/13/2018.
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
#define MAX 1000005

const int mod = 1e9+7;
const int mod1 = 1e9+9;
int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);

    int n,m;
    cin>>n>>m;
    lli dorm[n];
    for (int i = 0; i <n ; ++i) {
        scanf("%lld",&dorm[i]);
    }
    lli pSum[n];
    pSum[0]=dorm[0];
    for (int i = 1; i <n ; ++i) {
        pSum[i]=pSum[i-1]+dorm[i];
        //cout<<pSum[i]<<" ";
    }
    //cout<<"\n";
    lli num;
    for (int i = 0; i <m ; ++i) {
        scanf("%lld",&num);
        int pos=lower_bound(pSum,pSum+n,num)-pSum;

        //cout<<pos<<"\n";

        if(pos==0){
            printf("%d %lld\n",(pos+1),num);
        }
        else{
            lli rem=num-pSum[pos-1];
            //cout<<pSum[pos-1]<<"\n";
            printf("%d %lld\n",(pos+1),rem);
        }
    }

    return 0;
}
