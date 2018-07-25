//
// Created by bhagirathi on 6/7/2018.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,int> li;
typedef vector<ii> vii;
typedef vector<int> vi;

#define f(i,a,b) for(int i = (a); i <= (b); i++)
#define fd(i,a,b) for(int i = (a); i >= (b); i--)
#define MAX 150000+5
#define mod1 1e9+7
#define mod2 1e9+9

struct CustomCompare
{
    bool operator()(const li& lhs, const li& rhs)
    {
        if(lhs.first>rhs.first)
            return true;
        else if(lhs.first<rhs.first)
            return false;
        else{
            if(lhs.second>rhs.second)
                return true;
            else
                return false;
        }
    }
};


int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);
    int n;
    cin>>n;
    priority_queue<li,vector<li>,CustomCompare> pq;
    int num;
    for (int i = 0; i <n ; ++i) {
        cin>>num;
        pq.push({num,i});
    }
    ll ans[MAX];
    memset(ans,-1, sizeof(ans));
    int count=0;
    while(pq.size()>=2){
        li cur1=pq.top();
        pq.pop();
        //cout<<cur1.first<<" : "<<cur1.second<<"\n";
        li cur2=pq.top();
        if(cur1.first==cur2.first){
            pq.pop();
            li temp={2*cur2.first,cur2.second};
            pq.push(temp);
        }
        else{
            count++;
            ans[cur1.second]=cur1.first;
        }
    }

    li last=pq.top();
    ans[last.second]=last.first;
    count++;

    cout<<count<<"\n";
    for (int i = 0; i <n ; ++i) {
        if(ans[i]!=-1)
            printf("%lld ",ans[i]);
    }
    return 0;
}
