#include <bits/stdc++.h>
using namespace std;
const int N = 17;
int mxl[N] , mxr[N];
int strt = 0 ;
int n , m;

int solve(int i , bool left){
    if(i == strt){
        if(left)
            return mxr[i];
        else
            return (m+1 - mxl[i]);
    }
    if(left){
        return min(m+2+solve(i-1,0),solve(i-1,1) + ((mxr[i])*2) + 1);
    }
    else{
        return min(m+2+solve(i-1,1), solve(i-1,0) + (((m+1)-mxl[i])*2) + 1);
    }

}

int main(){
    //freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    strt = n-1;
    for(int i=0;i<n;i++){
        mxr[i] = 0;
        mxl[i] = m+1;
        for(int j=0;j<m+2;j++){
            char x;
            scanf(" %c",&x);
            if(x == '1')
            {
                strt = min(strt,i);
                mxr[i] = max(mxr[i],j);
                mxl[i] = min(mxl[i],j);
            }
        }
    }
    cout << solve(n-1,1) << endl;
    return 0 ;
}