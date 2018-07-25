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

    int n,w;
    cin>>n>>w;
    int arr[n];
    for (int i = 0; i <n ; ++i) {
        cin>>arr[i];
    }

    lli pSum[n];
    pSum[0]=arr[0];
    lli ans1=arr[0];
    lli ans2=arr[0];
    for (int i = 1; i <n ; ++i) {
        pSum[i]=pSum[i-1]+(lli)arr[i];
        ans1=max(ans1,pSum[i]);
        ans2=min(ans2,pSum[i]);
    }

    lli ans=0;
    if(ans1>=0){
        ans=w-ans1+1;
    }
    else{
        ans=w+1;
    }
    if(ans2<0){
        ans2=-ans2;
        ans=ans-(ans2);
    }
    if(ans>=0)
        cout<<ans;
    else
        cout<<"0";
}
