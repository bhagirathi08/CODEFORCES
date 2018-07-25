//
// Created by bhagirathi on 5/10/2018.
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
    char ans[4][n];
    for (int i = 0; i <4 ; ++i) {
        for (int j = 0; j <n ; ++j) {
            ans[i][j]='.';
        }
    }

    if(k<=2*(n-2)){
        cout<<"YES\n";
        int mid=(n-2)/2;
        if(k%2==1){
            ans[1][mid+1]='#';
            k--;
        }
        for (int i = 1; i <=mid; ++i) {
            if(k==0)
                break;
            ans[1][i]='#';
            k--;
            if(k==0)
                break;
            ans[1][n-1-i]='#';
            k--;
        }
        for (int i = 1; i <=mid; ++i) {
            if(k==0)
                break;
            ans[2][i]='#';
            k--;
            if(k==0)
                break;
            ans[2][n-1-i]='#';
            k--;
        }
        if(k==2){
            ans[1][mid+1]='#';
            ans[2][mid+1]='#';
        }
        for (int i = 0; i <4 ; ++i) {
            for (int j = 0; j <n ; ++j) {
                cout<<ans[i][j];
            }
            cout<<"\n";
        }
    }
    else{
        cout<<"NO";
    }
    return 0;
}

