//
// Created by bhagirathi on 4/16/2018.
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


    int n,pro,ath;
    cin>>n>>pro>>ath;
    string seats;
    cin>>seats;

    int a=pro,b=ath;

    char last=seats[0];
    if(seats[0]=='.'){
        if(a>b) {
            a--;
            last='A';
        }
        else {
            b--;
            last='B';
        }
    }

    int len=seats.length();
    for (int i = 1; i <len ; ++i) {
        //cout<<"a= "<<a<<" b= "<<b<<"\n";
        if(seats[i]=='.'){
            if(last=='*'){
                if(a>b && a>0) {
                    a--;
                    last='A';
                }
                else if(b>=a && b>0){
                    b--;
                    last='B';
                } else
                    last='*';
            }
            else{
                if(last=='A' && b>0){
                    b--;
                    last='B';
                }
                else if(last=='B' && a>0){
                    a--;
                    last='A';
                } else
                    last='*';
            }
        }
        else
            last='*';
    }
    lli sum1=(lli)pro+(lli)ath;
    lli sum2=(lli)a+(lli)b;
    lli ans=sum1-sum2;
    printf("%lld",ans);
    return 0;
}
