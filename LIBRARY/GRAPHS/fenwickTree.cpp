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
class FenwickTree{
private:
    vi ft;
public:
    FenwickTree(int n){
        ft.assign(n+1,0);
    }
    int LSOne(int num){
        return (num&(-num));
    }
    int rsq(int b){
        int sum=0;
        for (; b;b-=LSOne(b)) {
            sum+=ft[b];
        }
        return sum;
    }
    int rsq(int a,int b){
        return rsq(b)-(a==1?0:rsq(a-1));
    }
    void adjust(int k,int v){
        for (; k <(int)ft.size() ; k+=LSOne(k)) {
            ft[k]+=v;
        }
    }
};

int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    //freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);
    int f[]={2,4,5,5,6,6,6,7,7,8,9};
    FenwickTree ft(10);
    for (int i = 0; i <11 ; ++i) {
        ft.adjust(f[i],1);
    }
    printf("%d\n",ft.rsq(1,1));
    printf("%d\n",ft.rsq(1,2));
    printf("%d\n",ft.rsq(1,6));
    printf("%d\n",ft.rsq(1,10));
    printf("%d\n",ft.rsq(3,6));
    ft.adjust(5,2);
    printf("%d\n",ft.rsq(1,10));
    return 0;
}
