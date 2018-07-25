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
    int arr[n];
    for (int i = 0; i <n ; ++i) {
        cin>>arr[i];
    }
    sort(arr,arr+n);

    if(k==0){
        if(arr[0]==1){
            cout<<"-1\n";
        }
        else{
            cout<<"1\n";
        }
    }
    else{
        k=k-1;
        if(k==n-1){
            cout<<arr[n-1]<<"\n";
        }
        else{
            if(arr[k]==arr[k+1])
                cout<<"-1\n";
            else
                cout<<arr[k]<<"\n";
        }
    }

    return 0;
}
