//
// Created by bhagirathi on 4/16/2018.
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

    int n;
    cin>>n;
    int arr[n];
    lli sum=0;
    for (int i = 0; i <n ; ++i) {
        cin>>arr[i];
        sum+=arr[i];
    }
    lli tempSum=0;
    sum=(lli)ceil(sum/2.0);
    for (int j = 0; j <n ; ++j) {
        tempSum+=arr[j];
        if(tempSum>=sum){
            cout<<(j+1)<<"\n";
            break;
        }
    }
    return 0;
}

