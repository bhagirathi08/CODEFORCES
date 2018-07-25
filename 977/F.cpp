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

    int n;
    cin>>n;

    int arr[n];
    for (int i = 0; i <n ; ++i) {
        cin>>arr[i];
    }

    map<int,int> dp;
    int ans=0;
    int last=0;
    for (int i = 0; i <n ; i++) {
        int x=arr[i];
        dp[x]=dp[x-1]+1;
        if(ans<dp[x]){
            ans=dp[x];
            last=x;
        }
    }

    vector<int> res;
    for (int j = n-1; j >=0 ; --j) {
        if (arr[j] == last) {
            res.push_back(j);
            --last;
        }
    }

    reverse(res.begin(),res.end());
    printf("%d\n", ans);
    for (auto it : res)
        printf("%d ", it + 1);
    puts("");
    return 0;
}
