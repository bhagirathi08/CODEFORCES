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

    int n;
    cin>>n;
    string str;
    cin>>str;


    int xcnt=0;
    if(str[0]=='x')
        xcnt++;
    int ans=0;
    for (int i = 1; i <n ; ++i) {
        if(str[i]=='x'){
            xcnt++;
        }
        else{
            if(xcnt>=3)
                ans+=xcnt-2;
            xcnt=0;
        }
    }
    if(xcnt>=3)
        ans+=xcnt-2;
    cout<<ans;
    return 0;
}
