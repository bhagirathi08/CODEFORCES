//
// Created by bhagirathi on 6/7/2018.
//
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define f(i,a,b) for(int i = (a); i <= (b); i++)
#define fd(i,a,b) for(int i = (a); i >= (b); i--)
#define MAX 1000005
#define mod1 1e9+7
#define mod2 1e9+9

int min(int a,int b){
    if(a<b)
        return a;
    else
        return b;
}

int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);
    set<ll> squares;
    ll Max=2000000000;
    for (ll i = 1; i <=Max ; ++i) {
        ll sqr=i*i;
        if(sqr>Max)
            break;
        squares.insert(sqr);
    }
    string num;
    cin>>num;
    reverse(num.begin(),num.end());
    int ans=INT_MAX;
    for (int i = 0; i <1024 ; ++i) {
        int count=0;
        ll cur=0;
        bool ok=true;
        //cout<<"i= "<<i<<"\n";
        for (int j = num.length()-1; j >=0 ; --j) {
            if((1<<j) & i){
                if(cur==0 && num[j]=='0'){
                    ok=false;
                    //cout<<"done"<<"\n";
                    break;
                }
                cur=cur*10+(num[j]-'0');
                count++;
            }
        }
        if(ok && squares.find(cur)!=squares.end()){
           ans=min(ans,num.length()-count);
        }
        //cout<<cur<<"\n";
    }
    if(ans!=INT_MAX)
        cout<<ans<<"\n";
    else
        cout<<"-1"<<"\n";
    return 0;
}

