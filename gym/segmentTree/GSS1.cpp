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
    struct node{
        ll sum,msum,p,s;
    };
    vi A;
    vector<struct node> tree;
    int n;
    int left(int p){
        return ((p<<1) ) ;
    }
    int right(int p){
        return ((p<<1) + 1);
    }
    node merge(node l,node r){
        struct node newNode;
        newNode.sum=l.sum+r.sum;
        newNode.msum=max(max(l.msum,r.msum),l.s+r.p);
        newNode.p=max(l.p,l.sum+r.p);
        newNode.s=max(r.s,r.sum+l.s);
        return newNode;
    }
    void build(int p,int L,int R){
        if(L==R) {
            tree[p].sum=A[L];
            tree[p].msum=A[L];
            tree[p].p=A[L];
            tree[p].s=A[L];
            return;
        }
        else{
            build(left(p),L,(L+R)/2);
            build(right(p),(L+R)/2+1,R);
            tree[p]=merge(tree[left(p)],tree[right(p)]);
        }
    }
    node query(int index,int start,int end,int l,int r)
    {
        node result;
        result.sum=result.p=INT_MIN;
        result.s=result.msum=INT_MIN;

        if(r<start || end<l)
            return result;
        if(l<=start && end<=r)
            return tree[index];

        int mid = (start+end)/2;
        if (l > mid)
            return query(right(index), mid+1, end, l, r);
        if (r <= mid)
            return query(left(index), start, mid, l, r);

        node left = query(2*index,start,mid,l,r);
        node right = query(2*index+1,mid+1,end,l,r);

        result.sum = left.sum + right.sum;
        result.p =
                max(left.p, left.sum + right.p);
        result.s =
                max(right.s, right.sum + left.s);
        result.msum =
                max(result.p,
                    max(result.s,
                        max(left.msum,
                            max(right.msum,
                                left.s + right.p))));
        return result;
    }

public:
    SegmentTree(const vi &_A){
        A= _A;                  //copy contents to A private member
        n=(int)A.size();
        tree.resize(4*n);
        build(1,0,n-1);
    }
    //overloading
    node rmq(int i,int j){
        //cout<<"qlow= "<<i<<" qhigh="<<j<<"\n";
        return query(1,0,n-1,i,j);
    }
    void printTree(){
        cout<<"TREE:\n";
        for (int i = 0; i <tree.size() ; ++i) {
            cout<<"sum: "<<tree[i].sum<<"\n";
            cout<<"MAX sum: "<<tree[i].msum<<"\n";
            cout<<"prefix: "<<tree[i].p<<"\n";
            cout<<"suffix: "<<tree[i].s<<"\n";
            cout<<"---------\n";
        }
    }
};

void fastscan(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;

    number = 0;

    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;

        // extract the next character from the buffer
        c = getchar();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}

int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);
    int N;
    fastscan(N);
    int arr[N];
    for (int i = 0; i <N ; ++i) {
        fastscan(arr[i]);
    }
    vi A(arr,arr+N);
    SegmentTree st(A);

    int M,r,l;
    fastscan(M);
    //st.printTree();
    for (int j = 0; j <M ; ++j) {
        //cout<<j<<"\n";
        fastscan(l);
        fastscan(r);
        cout<<st.rmq(l-1,r-1).msum<<"\n";
    }
    return 0;
}