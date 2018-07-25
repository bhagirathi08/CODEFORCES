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
    string str;
    cin>>str;
    int len=str.length();
    bool pos=false;
    for (int i = 1; i <len-1 ; ++i) {
        if(str[i]=='A'){
            if(str[i-1]=='B' && str[i+1]=='C'){
                pos=true;
                break;
            }
            if(str[i-1]=='C' && str[i+1]=='B'){
                pos=true;
                break;
            }
        }
        if(str[i]=='B'){
            if(str[i-1]=='A' && str[i+1]=='C'){
                pos=true;
                break;
            }
            if(str[i-1]=='C' && str[i+1]=='A'){
                pos=true;
                break;
            }
        }
        if(str[i]=='C'){
            if(str[i-1]=='A' && str[i+1]=='B'){
                pos=true;
                break;
            }
            if(str[i-1]=='B' && str[i+1]=='A'){
                pos=true;
                break;
            }
        }
    }
    if(pos)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
