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
    map<int,int> table;
    int n,k;
    cin>>n>>k;
    int num;
    for (int i = 0; i <n ; ++i) {
        cin>>num;
        if(table.find(num)==table.end()){
            table[num]=i+1;
        }
    }
    if(table.size()>=k){
        cout<<"YES\n";
        for(auto it = table.cbegin(); it != table.cend() && k>0 ; ++it)
        {
            k--;
            cout<<it->second<<" ";
        }
    }
    else{
        cout<<"NO";
    }
    return 0;
}
