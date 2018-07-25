//
// Created by bhagirathi on 5/15/2018.
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
#define MAX 1000005

const int mod = 1e9+7;
const int mod1 = 1e9+9;
struct mentor{
    int ind;
    int neg;
    int skill;
};
bool acompare(mentor lhs, mentor rhs) { return lhs.skill < rhs.skill; }
int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);

    int n,k;
    cin>>n>>k;
    struct mentor mentors[n];
    for (int i = 0; i <n ; ++i) {
           mentors[i].ind=i;
           mentors[i].neg=0;
           cin>>mentors[i].skill;
    }

    int l,r;
    for (int j = 0; j <k ; ++j) {
        cin>>l>>r;
        l--;
        r--;
        if(mentors[l].skill>mentors[r].skill){
            mentors[l].neg--;
        }
        else{
            mentors[r].neg--;
        }
    }
    sort(mentors,mentors+n,acompare);

    int ans[n];
    int same=0;
    ans[mentors[0].ind]=0;
    //cout<<mentors[0].ind<<" , "<<mentors[0].neg<<" , "<<mentors[0].skill<<"\n";
    for (int i = 1; i <n ; ++i) {
        //cout<<mentors[i].ind<<" , "<<mentors[i].neg<<" , "<<mentors[i].skill<<"\n";
        if(mentors[i].skill==mentors[i-1].skill){
            same++;
            //cout<<same<<"\n";
            ans[mentors[i].ind]=i-same+mentors[i].neg;
        }
        else{
            same=0;
            //cout<<i<<"\n";
            ans[mentors[i].ind]=i-same+mentors[i].neg;
        }
    }
    for (int i = 0; i <n ; ++i) {
        if(ans[i]>=0)
            cout<<ans[i]<<" ";
        else
            cout<<"0"<<" ";
    }
    return 0;
}
