//
// Created by bhagirathi on 5/6/2018.
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

    int n,k;
    cin>>n>>k;
    while(n>0 && k>0){
        int r=n%10;
        if((r+1)<=k){
            n=n/10;
            k=k-(r+1);
        }
        else{
            n=n-(k);
            break;
        }
        //cout<<n<<" "<<k<<"\n";
    }
    cout<<n;

    return 0;
}
