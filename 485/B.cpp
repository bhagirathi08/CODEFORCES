//
// Created by bhagirathi on 6/4/2018.
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
#define f(i,a,b) for(int i = (a); i <= (b); i++)
#define fd(i,a,b) for(int i = (a); i >= (b); i--)

const double eps = 1e-12;

int main() {
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/input.txt", "r", stdin);
    freopen("C:/Users/bhagirathi/CLionProjects/codeforces/debug/output.txt", "w", stdout);
    int x, y;
    cin >> x >> y;

    if (log(x) * y - log(y) * x < -eps) {
        cout << "<\n";
    } else if (log(x) * y - log(y) * x > eps) {
        cout << ">\n";
    } else {
        cout << "=";
    }
}
