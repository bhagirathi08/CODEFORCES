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

const int INF = (int)1e9 + 34;

int solve(string s,char a,char b){
    int n=s.length();
    if(a=='0' && b=='0'){
        vector<int> pos;
        for (int i =n-1 ; i >=0 ; --i) {
            if(s[i]=='0')
                pos.push_back(i);
        }
        if(pos.size()<2)
            return INF;
        int ans=(n-1)-pos[0]+(n-2)-pos[1];
        return ans;
    }
    int pa=-1,pb=-1;
    for (int i = n-1; i >=0 ; --i) {
        if(s[i]==a && pa==-1){
            pa=i;
        }
        if(s[i]==b && pb==-1){
            pb=i;
        }
    }
    if(pa==-1 || pb==-1)
        return INF;

    int ans=0;
    if(pb<pa){
        int temp=pa;
        pa=pb;
        pb=temp;
        ans++;
    }

    ans+=(n-1)-pb+(n-2)-pa;

    int count=0;
    int OK=false;
    for (int i = 0; i <n ; ++i) {
        if(i==pa || i==pb)
            continue;
        if(s[i]=='0' && !OK)
            count++;
        else
            OK=true;
    }
    if(!OK && count>0)
        return INF;
    return ans+count;

}

int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);
    string num;
    cin>>num;
    int ans=min(min(solve(num,'0','0'),solve(num,'2','5')),min(solve(num,'5','0'),solve(num,'7','5')));
    if(ans!=INF)
        cout<<ans<<"\n";
    else
        cout<<"-1\n";
    return 0;
}
