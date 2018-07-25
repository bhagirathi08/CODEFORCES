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
bool lengthWise(string x,string y){
    if(x.length()<y.length())
        return true;
    else
        return false;
}
int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);
    int n;
    cin>>n;
    string words[n];
    for (int i = 0; i <n ; ++i) {
        cin>>words[i];
    }
    sort(words,words+n,lengthWise);
    bool pos=true;
    for (int j = 1; j <n ; ++j) {
        if(words[j].find(words[j-1])==std::string::npos){
            pos=false;
            break;
        }
    }
    if(pos){
        cout<<"YES\n";
        for (int j = 0; j <n ; ++j) {
            cout<<words[j]<<"\n";
        }
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}
