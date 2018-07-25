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
    int arr[n],ans[n];
    for (int i = 0; i <n ; ++i) {
        cin>>arr[i];
    }

    int colors[256];
    for (int j = 0; j <256 ; ++j) {
        colors[j]=-1;
    }

    for (int i = 0; i <n ; ++i) {

        if(colors[arr[i]]>=0){
            ans[i]=colors[arr[i]];
            /*for (int l = 0; l <15 ; ++l) {
                cout<<colors[l]<<" ";
            }
            cout<<"\n";*/
            continue;
        }
        int end=arr[i];
        int start=arr[i]-k+1;
        if(start<0)
            start=0;
        bool first=true;
        int clr;
        for (int j = start; j <=end ; ++j) {
            if(colors[j]==-1 || ((j-colors[j]+1)+arr[i]-j)<=k){
                if(first){
                    colors[j]=j;
                    clr=j;
                    first=false;
                }
                else{
                    colors[j]=clr;
                }
            }
            ans[i]=clr;
        }
        /*for (int l = 0; l <15 ; ++l) {
            cout<<colors[l]<<" ";
        }
        cout<<"\n";*/
    }



    for (int l = 0; l <n ; ++l) {
        cout<<ans[l]<<" ";
    }

    return 0;
}

