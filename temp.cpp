#include<iostream>
using namespace std ;

const int N = 100 ;

int a[N] , b[N] , n , m , len , L ;

int main() {

    cin >> n ;
    for( int i = 0 ; i < n ; i++ ) cin >> a[i] ;
    cin >> m ;
    for( int i = 0 ; i < m ; i++ ) cin >> b[i] ;
    len = n + m - 1 ;
    L = n + m ;
    n--  , m-- ;

    while( len >= 0 ) {
        if( m < 0 ) a[len] = a[n--];
        else if( n < 0 ) a[len] = b[m--];
        else if( a[n] > b[m] ) a[len] = a[n--];
        else a[len] = b[m--];
        len--;
    }

    for( int i = 0 ; i < L ; i++ ) cout << a[i] << " " ;
}
