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

    int n;
    cin>>n;
    string str;
    cin>>str;
    map<string,int> store;
    int len=str.length();
    for (int i = 0; i <len-1 ; ++i) {
        string temp=str.substr(i,2);
        if(store.find(temp)==store.end()){
            store.emplace(temp,1);
        }
        else{
            store[temp]=store[temp]+1;
        }
    }

    int max=INT_MIN;
    string ans="";
    for (auto it=store.begin();it!=store.end();it++) {
        int freq=it->second;
        string w=it->first;
        if(freq>max){
            max=freq;
            ans=w;
        }
    }
    cout<<ans<<"\n";

    return 0;
}
