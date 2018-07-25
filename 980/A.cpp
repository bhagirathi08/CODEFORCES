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

    string neck;
    cin>>neck;
    int len=neck.length();
    int pearls=0;
    for (int i = 0; i <len ; ++i) {
        if(neck[i]=='o')
            pearls++;
    }

    if(pearls==0)
        cout<<"YES";
    else{
        if((len-pearls)%pearls==0)
            cout<<"YES";
        else
            cout<<"NO";
    }

    return 0;
}

