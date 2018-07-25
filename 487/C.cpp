//
// Created by bhagirathi on 6/14/2018.
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
int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    char grid[51][51];
    memset(grid,' ', sizeof(grid));

    for (int i = 2; i <=9 ; i++) {
        if(i==4 || i==7)
            continue;
        int j=3;
        if(i==2 || i==5 || i==8)
            j=2;
        for (; j <=50 ; j+=2) {
            //first belt
            if(b>1) {
                grid[i][j] = 'B';
                b--;
            }

            //second belt
            if(c>1) {
                grid[i+10][j] = 'C';
                c--;
            }

            //second belt
            if(d>1) {
                grid[i+20][j] = 'D';
                d--;
            }

            //second belt
            if(a>1) {
                grid[i+30][j] = 'A';
                a--;
            }
        }
    }

    for (int k = 1; k <=10 ; ++k) {
        for (int l = 1; l <=50 ; ++l) {
            if(grid[k][l]==' ')
                grid[k][l]='A';
        }
    }
    for (int k = 11; k <=20 ; ++k) {
        for (int l = 1; l <=50 ; ++l) {
            if(grid[k][l]==' ')
                grid[k][l]='B';
        }
    }
    for (int k = 21; k <=30 ; ++k) {
        for (int l = 1; l <=50 ; ++l) {
            if(grid[k][l]==' ')
                grid[k][l]='C';
        }
    }
    for (int k = 31; k <=50 ; ++k) {
        for (int l = 1; l <=50 ; ++l) {
            if(grid[k][l]==' ')
                grid[k][l]='D';
        }
    }

    cout<<"50 50"<<"\n";
    for (int i = 1; i <=50 ; ++i) {
        for (int j = 1; j <=50 ; ++j) {
            cout<<grid[i][j];
        }
        cout<<"\n";
    }
    return 0;
}


