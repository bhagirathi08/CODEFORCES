//
// Created by bhagirathi on 6/6/2018.
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
int intrvl=0,maxIntrvl,maxIntrvlCount=0;
int lft[MAX],rht[MAX];
pair<int,int> arr[MAX];
bool OK;

void add(int u){
    int L=u,R=u;
    if(lft[u-1]!=0){
        L=lft[u-1];
        intrvl--;
    }
    if(rht[u+1]!=0){
        R=rht[u+1];
        intrvl--;
    }
    intrvl++;
    lft[R]=L;
    rht[L]=R;
    if(R-L+1>maxIntrvl){
        maxIntrvl=R-L+1;
        maxIntrvlCount=0;
    }
    if(maxIntrvl==R-L+1){
        maxIntrvlCount++;
    }
    if(intrvl==maxIntrvlCount){
        OK=true;
    } else
        OK=false;
}

int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);
    int n;
    cin>>n;
    for (int i = 1; i <=n ; ++i) {
        cin>>arr[i].first;
        arr[i].second=i;
    }
    sort(arr+1,arr+n+1);
    int ans=INT_MIN;
    int res;
    for (int i = 1; i <=n ; ++i) {
        add(arr[i].second);
        if(OK && intrvl>ans){
            ans=intrvl;
            res=arr[i].first+1;
        }
    }
    cout<<res;
    return 0;
}
