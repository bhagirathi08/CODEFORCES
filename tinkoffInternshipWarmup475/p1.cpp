//
// Created by bhagirathi on 4/17/2018.
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
    lli num;
    scanf("%lld",&num);
    /*set<lli> store;
    store.emplace(1);
    lli start=(lli)ceil(num/2.0);
    for(lli i=start;i>0;i--){
        lli temp=num/i;
        if(store.find(temp)==store.end())
            store.emplace(temp);
    }*/
    lli ans=num/2 + 1;
    printf("%lld",ans);
    return 0;
}
