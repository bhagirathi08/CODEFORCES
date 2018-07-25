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

class SegmentTree{
private:
    vi st,A;
    int n;
    int left(int p){
        return p<<1;
    }
    int right(int p){
        return (p<<1) + 1;
    }
    void build(int p,int L,int R){
        if(L==R)
            st[p]=L;
        else{
            build(left(p),L,(L+R)/2);
            build(right(p),(L+R)/2+1,R);
            int p1=st[left(p)];
            int p2=st[right(p)];
            st[p]=(A[p1]<=A[p2])?p1:p2;
        }
    }
    int rmq(int p,int L,int R,int i,int j){
        //outside query range
        if(i>R || j<L)
            return -1;

        //total overlap
        if(L>=i && R<=j)
            return st[p];

        int p1=rmq(left(p),L,(L+R)/2,i,j);
        int p2=rmq(right(p),(L+R)/2 + 1,R,i,j);

        if(p1==-1)
            return p2;
        if(p2==-1)
            return p1;
        return (A[p1]<=A[p2])?p1:p2;
    }

public:
    SegmentTree(const vi &_A){
        A= _A;                  //copy contents to A private member
        n=(int)A.size();
        st.assign(4*n,0);
        build(1,0,n-1);
    }
    //overloading
    int rmq(int i,int j){
        return rmq(1,0,n-1,i,j);
    }
};

int main() {
    //freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    //freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);
    int arr[]={18,17,13,19,15,11,20};
    vi A(arr,arr+7);
    SegmentTree st(A);
    printf("RMQ(1,3)=%d\n",st.rmq(1,3));
    printf("RMQ(4,6)=%d\n",st.rmq(4,6));
    return 0;
}