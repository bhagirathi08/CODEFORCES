//
// Created by bhagirathi on 4/29/2018.
//
#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define pi pair<int, int>
#define pii pair<pi,int>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define MAX 100005

const int mod = 1e9+7;
const int mod1 = 1e9+9;

int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/Codechef/EASY/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/Codechef/EASY/output.txt", "w", stdout);

    int n,m;
    cin>>n>>m;
    int blockSize=(int)ceil(sqrt(n));
    //cout<<blockSize<<"\n";
    int blks=n/blockSize + 1;
    //cout<<blks<<"\n";
    unordered_map<int,int> blocks[blks];

    //take array input
    int arr[n];
    for (int i = 0; i <n ; ++i) {
        cin>>arr[i];
    }

    //build blocks
    for (int i = 0; i <n ; ++i) {
        int blockIndex=i/blockSize;
        if(blocks[blockIndex].find(arr[i])==blocks[blockIndex].end()){
            blocks[blockIndex][arr[i]]=1;
        } else {
            blocks[blockIndex].find(arr[i])->second++;
        }
    }

    /*for (int j = 0; j <blks ; ++j) {
        cout<<"BLOCK: "<<j<<"\n";
        for (auto it=blocks[j].begin();it!=blocks[j].end();it++) {
            cout<<it->first<<" "<<it->second<<"\n";
        }
        cout<<"\n";
    }*/

    while(m--){
        int l,r;
        cin>>l>>r;
        l--;r--;
        int leftBlock=l/blockSize;
        int rightBlock=r/blockSize;
        //cout<<leftBlock<<" "<<rightBlock<<"\n";


        //traverse the partial left block
        map<int,int> temp;
        for (int i = l; i <(leftBlock+1)*blockSize && i<=r ; ++i) {
            //cout<<"Left Block\n";
            if(temp.find(arr[i])==temp.end())
                temp[arr[i]]=1;
            else
                temp.find(arr[i])->second++;
        }

        //traverse the blocks inbetween
        for (int i = leftBlock+1; i <rightBlock ; ++i) {
            //cout<<"Middle Block\n";
            for (auto it=blocks[i].begin();it!=blocks[i].end();it++) {
                int key=it->first;
                if(temp.find(key)==temp.end())
                    temp[key]=1;
                else
                    temp.find(key)->second+=it->second;
            }
        }

        //traverse the partial right block
        //cout<<(r*blockSize)<<" "<<r;
        if(leftBlock!=rightBlock) {
            for (int i = rightBlock * blockSize; i <= r; ++i) {
                //cout << "Right Block\n";
                if (temp.find(arr[i]) == temp.end())
                    temp[arr[i]] = 1;
                else
                    temp.find(arr[i])->second++;
            }
        }
        int ans=0;
        for (auto it=temp.begin();it!=temp.end();it++) {
            if(it->first==it->second)
                ans++;
        }
        cout<<ans<<"\n";
    }

    return 0;
}