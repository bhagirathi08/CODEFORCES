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
int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);
    int k;
    cin>>k;

    vector<int> vect[k];
    vector<ll> sum;
    int n;
    for (int i = 0; i <k ; ++i) {
        cin>>n;
        int num;
        ll temp=0;
        for (int j = 0; j <n ; ++j) {
            cin>>num;
            vect[i].push_back(num);
            temp+=num;
        }
        sum.push_back(temp);
    }
    map<ll,ii> store;
    bool done=false;
    for (int i = 0; i <k && !done ; ++i) {
        ll temp=0;
        for (int j = 0; j <vect[i].size() ; ++j) {
            temp=sum[i]-vect[i][j];
            if(store.find(temp)==store.end()){
                ii p=make_pair(i+1,j+1);
                store.emplace(temp,p);
            }
            else{
                ii ans=store.find(temp)->second;

                if((i+1)==ans.first)
                    continue;

                done=true;
                cout<<"YES\n";
                cout<<(i+1)<<" "<<(j+1)<<"\n";
                cout<<ans.first<<" "<<ans.second<<"\n";
                break;
            }
        }
    }
    if(!done){
        cout<<"NO\n";
    }

    return 0;
}
