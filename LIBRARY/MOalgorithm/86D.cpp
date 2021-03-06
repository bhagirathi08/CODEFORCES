#include <iostream>
#include <algorithm>
#include <cmath>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int n, q, sqn;
struct que{
    int l, r;
    int ind;
};
que Q[200002];

bool f( que A, que B ){
    if( A.l / sqn < B.l / sqn )
        return true;
    if( A.l / sqn > B.l / sqn )
        return false;
    return A.r < B.r;
}

long long int A[200002], s[1000002];
long long int ans[200002], answer = 0;
int L, R;

void add( int i ){
    answer += 2 * s[ A[i] ] * A[i] + A[i];
    s[ A[i] ]++;
}

void remove( int i ){
    s[ A[i] ]--;
    answer -= 2 * s[ A[i] ] * A[i] + A[i];
}

long long int query( int i ){

    while( L < Q[i].l ){
        remove( L );
        L++;
    }
    while( L > Q[i].l ){
        L--;
        add( L );
    }
    while( R < Q[i].r ){
        R++;
        add( R );
    }
    while( R > Q[i].r ){
        remove( R );
        R--;
    }
    return answer;

}

int main(){

    optimizar_io
    cin >> n >> q;
    sqn = sqrt( n );
    for( int i = 1; i <= n; i++ )
        cin >> A[i];
    for( int i = 1; i <= q; i++ ){
        cin >> Q[i].l >> Q[i].r;
        Q[i].ind = i;
    }
    sort( Q + 1, Q + q + 1, f );
    //for( int i = 1; i <= q; i++ )
    //	cout << Q[i].l << " " << Q[i].r << "\n";

    for( int i = 1; i <= q; i++ )
        ans[ Q[i].ind ] = query( i );
    for( int i = 1; i <= q; i++ )
        cout << ans[i] << "\n";


    return 0;

}