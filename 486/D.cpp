//
// Created by bhagirathi on 5/16/2018.
//
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define MAX 1000005
#define mod1 1e9+7
#define mod2 1e9+9
int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);
    int n;
    cin>>n;
    ll arr[n];
    set<ll> store;
    int num;
    for (int i = 0; i <n ; ++i) {
        cin>>num;
        arr[i]=num;
        store.insert(num);
    }

    vector<ll> ans={arr[0]};
    for (int pow = 0; pow <31 ; ++pow) {
        ll other=(1<<pow);
        for (int i = 0; i <n ; ++i) {
            if(store.find(arr[i]+other)!=store.end() && (int)ans.size()<2)
                ans={arr[i],arr[i]+other};
            if(store.find(arr[i]+other)!=store.end() && store.find(arr[i]+other*2)!=store.end() && (int)ans.size()<3)
                ans={arr[i],arr[i]+other,arr[i]+other*2};
        }
    }

    cout<<ans.size()<<"\n";
    for (int j = 0; j <(int)ans.size() ; ++j) {
        cout<<ans[j]<<" ";
    }
    return 0;
}
