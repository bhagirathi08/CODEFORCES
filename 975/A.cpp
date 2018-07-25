//
// Created by bhagirathi on 5/7/2018.
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
    string words[n];
    for (int i = 0; i <n ; ++i) {
        cin>>words[i];
    }

    set<string> store;
    for (int i = 0; i <n ; ++i) {
        sort(words[i].begin(),words[i].end());
        int len=words[i].length();
        string curr=""+words[i][0];
        for (int j = 1; j <len ; ++j) {
            if(words[i][j]!=words[i][j-1])
                curr=curr+words[i][j];
        }
        if(store.find(curr)==store.end())
            store.emplace(curr);
    }
    cout<<store.size();
    return 0;
}
