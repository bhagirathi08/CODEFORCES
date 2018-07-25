//
// Created by bhagirathi on 6/11/2018.
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
int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);
    int n,p;
    cin>>n>>p;
    string str;
    cin>>str;
    bool pos=false;
    string ans=str;
    int len=str.length();
    for (int i = 0; i <len-p ; ++i) {
        if(str[i]=='1'){
            if(str[i+p]=='.'){
                ans[i+p]='0';
                pos=true;
                break;
            }
            if(str[i+p]=='0'){
                pos=true;
                break;
            }
        }
        if(str[i]=='0'){
            if(str[i+p]=='.'){
                ans[i+p]='1';
                pos=true;
                break;
            }
            if(str[i+p]=='1'){
                pos=true;
                break;
            }
        }
        if(str[i]=='.'){
           if(str[i+p]=='1'){
               ans[i]='0';
               pos=true;
               break;
           }
            if(str[i+p]=='0'){
                ans[i]='1';
                pos=true;
                break;
            }
            if(str[i+p]=='.'){
               ans[i]='0';
               ans[i+p]='1';
               pos=true;
               break;
           }
        }
    }
    if(pos){
        for (int i = 0; i <len ; ++i) {
            if(ans[i]=='.')
                ans[i]='0';
        }
        cout<<ans;
    }
    else{
        cout<<"No";
    }

    return 0;
}

