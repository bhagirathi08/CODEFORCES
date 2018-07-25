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

    bool present[1001];
    memset(present,false, sizeof(present));
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i <n ; ++i) {
        cin>>arr[i];
    }

    vector<int> ans;
    for (int i = n-1; i >=0 ; i--) {
        if(present[arr[i]]==false){
            ans.push_back(arr[i]);
            present[arr[i]]=true;
        }
    }

    cout<<ans.size()<<"\n";
    for (int j = ans.size()-1; j >=0 ; --j) {
        cout<<ans[j]<<" ";
    }
    return 0;
}
